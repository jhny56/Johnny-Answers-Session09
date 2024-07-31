#include "wall_finder.hpp"

WallFinderNode::WallFinderNode()
: Node("wall_finder_node"),
  find_wall_distance(0.5),  // Set your distance threshold here
  finding_wall_(false)
{
    wall_found_publisher_ = this->create_publisher<std_msgs::msg::Bool>("wall_found", 10);
    twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    laser_subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&WallFinderNode::laser_callback, this, std::placeholders::_1));
    find_wall_service_ = this->create_service<cpp_turtle::srv::FindWall>(
        "find_wall", std::bind(&WallFinderNode::find_wall_service_callback, this, std::placeholders::_1, std::placeholders::_2));
}

void WallFinderNode::laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    
    if (finding_wall_) {
        auto twist = geometry_msgs::msg::Twist();
        find_wall_logic(msg, twist);
        twist_publisher_->publish(twist);
    }
}

float WallFinderNode::getFrontRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg){
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

void WallFinderNode::find_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist)
{
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

void WallFinderNode::find_wall_service_callback(
    const std::shared_ptr<cpp_turtle::srv::FindWall::Request> request,
    std::shared_ptr<cpp_turtle::srv::FindWall::Response> response)
{
    (void)request;
    finding_wall_ = true;
    response->success = finding_wall_;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<WallFinderNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
