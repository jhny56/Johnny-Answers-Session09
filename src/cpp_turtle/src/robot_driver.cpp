#include "robot_driver.hpp"

using std::placeholders::_1;

RobotDriver::RobotDriver()
: Node("robot_driver"),
  finding_wall_(true),
  distance_to_wall_(0.2),
  wall_distance_tolerance_(0.05),
  distance_threshold_(0.3)
{
    //publisher to control robot speed with the /smd_vel topic
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

    //subscription to take the 360 degree ranges of the robot in the /scan topic, and run the listener_callback at every published scan
    subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&RobotDriver::listener_callback, this, _1));
    
    // publisher to tell when the wall is found (aka start the race)
    wall_found_publisher_ = this->create_publisher<std_msgs::msg::Bool>("wall_found", 10);

    // // client to tell the robot to find the wall (its unused for now) TODO
    // client_ = this->create_client<cpp_turtle::srv::FindWall>("find_wall");

    // //wait for the find wall server to be active
    // while (!client_->wait_for_service(std::chrono::seconds(1))) {
    //     RCLCPP_INFO(this->get_logger(), "Service not available, waiting...");
    // }

    // //request of type FindWall srv
    // auto request = std::make_shared<cpp_turtle::srv::FindWall::Request>();
    // auto future = client_->async_send_request(request);

    // // wait until we get future result, here i dont think its working. TODO
    // if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS) {
    //     RCLCPP_INFO(this->get_logger(), "Found the wall");
    //     finding_wall_ = false;
    // } else {
    //     RCLCPP_ERROR(this->get_logger(), "Failed to call service find_wall");
    // }
}

void RobotDriver::listener_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    auto twist = geometry_msgs::msg::Twist();

    if (finding_wall_) {
        find_wall_logic(msg, twist);
    } else {
        follow_wall_logic(msg, twist);
    }

    publisher_->publish(twist);
}

void RobotDriver::find_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist)
{
    auto ranges = msg->ranges;
    float front_region = *std::min_element(ranges.begin(), ranges.begin() + 20);
    front_region = std::min(front_region, *std::min_element(ranges.end() - 20, ranges.end()));

    if (front_region < distance_threshold_) {
        twist.linear.x = 0.0;
        twist.angular.z = 0.5;  // Turn to find the wall
        finding_wall_ = false;
        auto wall_found_msg = std_msgs::msg::Bool();
        wall_found_msg.data = true;
        wall_found_publisher_->publish(wall_found_msg);
        RCLCPP_INFO(this->get_logger(), "WALL FOUND: DATA = TRUE");
    } else {
        twist.linear.x = 0.4;
        twist.angular.z = 0.0;  // Move forward to find the wall
    }
}

void RobotDriver::follow_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist)
{
    auto ranges = msg->ranges;
    float front_region = *std::min_element(ranges.begin(), ranges.begin() + 20);
    front_region = std::min(front_region, *std::min_element(ranges.end() - 20, ranges.end()));
    float right_region = *std::min_element(ranges.end() - 90, ranges.end() - 60);

    if (front_region < distance_threshold_) {
        twist.linear.x = 0.0;
        twist.angular.z = 0.5;  // Turn left to avoid front obstacle
    } else {
        if (right_region < distance_to_wall_ - wall_distance_tolerance_) {
            twist.linear.x = 0.4;
            twist.angular.z = 0.2;  // Too close to wall, turn left
        } else if (right_region > distance_to_wall_ + wall_distance_tolerance_) {
            twist.linear.x = 0.4;
            twist.angular.z = -0.2;  // Too far from wall, turn right
        } else {
            twist.linear.x = 0.4;
            twist.angular.z = 0.0;  // Move forward while maintaining distance
        }
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotDriver>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
