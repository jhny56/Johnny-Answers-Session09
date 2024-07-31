#include "robot_driver.hpp"

using std::placeholders::_1;

RobotDriver::RobotDriver()
: Node("robot_driver"),
  finding_wall_(true),
  distance_to_wall_(0.3),
  wall_distance_tolerance_(0.02),
  distance_threshold_(1),
  find_wall_distance(0.6)
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

float RobotDriver::getFrontRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    // Define the front region angle range (e.g., ±20 degrees around the front)
    float front_angle = 20.0;
    float front_angle_range = front_angle * M_PI / 180.0;  // Convert degrees to radians

    // Calculate the indices for the desired angle range
    int start_index = static_cast<int>((msg->angle_min - front_angle_range) / msg->angle_increment);
    int end_index = static_cast<int>(( msg->angle_min + front_angle_range) / msg->angle_increment);

    int num_ranges = static_cast<int>(msg->ranges.size());
    start_index = (start_index + num_ranges) % num_ranges;
    end_index = (end_index + num_ranges) % num_ranges;

     // Collect the distances in the front region
    std::vector<float> front_ranges;
    if (start_index < end_index) {
        front_ranges.insert(front_ranges.end(), msg->ranges.begin() + start_index, msg->ranges.begin() + end_index + 1);
    } else {
        front_ranges.insert(front_ranges.end(), msg->ranges.begin() + start_index, msg->ranges.end());
        front_ranges.insert(front_ranges.end(), msg->ranges.begin(), msg->ranges.begin() + end_index + 1);
    }

    // Check if ranges array is not empty and indices are valid
    if (front_ranges.empty()) {
        RCLCPP_ERROR(this->get_logger(), "Invalid ranges in LaserScan data");
        return std::numeric_limits<float>::infinity();
    }

     // Get the minimum distance in the front region
    float front_region = *std::min_element(front_ranges.begin(), front_ranges.end());

    return front_region;
}

float RobotDriver::getRightRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    // Define the right region angle range (e.g., from 60 to 90 degrees)
    float start_angle = -90.0;  // Right 90 degrees
    float end_angle = -60.0;    // Right 60 degrees
    float start_angle_rad = start_angle * M_PI / 180.0;  // Convert degrees to radians
    float end_angle_rad = end_angle * M_PI / 180.0;      // Convert degrees to radians

    // Calculate the indices for the desired angle range
    int start_index = static_cast<int>((start_angle_rad - msg->angle_min) / msg->angle_increment);
    int end_index = static_cast<int>((end_angle_rad - msg->angle_min) / msg->angle_increment);

    int num_ranges = static_cast<int>(msg->ranges.size());
    start_index = (start_index + num_ranges) % num_ranges;
    end_index = (end_index + num_ranges) % num_ranges;

    RCLCPP_INFO(this->get_logger(), "Start index: %d", start_index);
    RCLCPP_INFO(this->get_logger(), "End index: %d", end_index);

    // Collect the distances in the right region
    std::vector<float> right_ranges;
    if (start_index < end_index) {
        right_ranges.insert(right_ranges.end(), msg->ranges.begin() + start_index, msg->ranges.begin() + end_index + 1);
    } else {
        right_ranges.insert(right_ranges.end(), msg->ranges.begin() + start_index, msg->ranges.end());
        right_ranges.insert(right_ranges.end(), msg->ranges.begin(), msg->ranges.begin() + end_index + 1);
    }

    // Check if ranges array is not empty and indices are valid
    if (right_ranges.empty()) {
        RCLCPP_ERROR(this->get_logger(), "Invalid ranges in LaserScan data");
        return std::numeric_limits<float>::infinity();
    }

    // Get the minimum distance in the right region
    float right_region = *std::min_element(right_ranges.begin(), right_ranges.end());

    return right_region;
}

void RobotDriver::find_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist)
{
  
    // Log the calculated indices for debugging
    // RCLCPP_INFO(this->get_logger(), "Start index: %d", start_index);
    // RCLCPP_INFO(this->get_logger(), "End index: %d", end_index);


    // // Print front_ranges
    // std::cout << "front_ranges: ";
    // for (const auto &range : front_ranges) {
    //     std::cout << range << " ";
    // }
    // std::cout << std::endl;

    // Get the minimum distance in the front region
    float front_region = getFrontRegion(msg);

    // Log the front region distance for debugging
    RCLCPP_INFO(this->get_logger(), "Front region distance: %f", front_region);
    // Check if ranges array is not empty and indices are valid

    if (front_region < find_wall_distance) {
        twist.linear.x = 0.0;
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

    float front_region = getFrontRegion(msg);
    // if (std::isinf(front_region)) {
    //     RCLCPP_WARN(this->get_logger(), "Received invalid front region distance");
    //     twist.linear.x = 0.0;
    //     twist.angular.z = 0.0;  // Stop the robot in case of an error
    //     return;
    // }

    // float right_region = *std::min_element(ranges.end() - 90, ranges.end() - 60);
    float right_region = getRightRegion(msg);

    // Define a maximum angular velocity
    const float max_angular_velocity = 1.5;

    // Calculate the proportional control for angular velocity based on front region distance
    if (front_region < distance_threshold_) {
        float proximity_factor = front_region / distance_threshold_;

        twist.linear.x = 0.8 * proximity_factor;
        twist.angular.z = max_angular_velocity * (1 - proximity_factor);
    } else {
        if (right_region < distance_to_wall_ - wall_distance_tolerance_) {
            float proximity_factor = right_region / (distance_to_wall_ - wall_distance_tolerance_);
            twist.linear.x = 0.8;
            twist.angular.z = 0.25 * (1 - proximity_factor) ;  // Too close to wall, turn left
        } else if (right_region > distance_to_wall_ + wall_distance_tolerance_) {
            float proximity_factor = right_region / (distance_to_wall_ + wall_distance_tolerance_);
            twist.linear.x = 0.8;
            twist.angular.z = -0.25 * proximity_factor;  // Too far from wall, turn right
        } else {
            twist.linear.x = 0.8;
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
