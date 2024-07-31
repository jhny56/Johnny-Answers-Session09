#ifndef ROBOT_DRIVER_HPP_
#define ROBOT_DRIVER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "cpp_turtle/srv/find_wall.hpp"
#include "std_msgs/msg/bool.hpp"

class RobotDriver : public rclcpp::Node
{
public:
    RobotDriver();
    
private:
    void listener_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void find_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist);
    void follow_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist);
    void find_wall_service_callback();
    float getFrontRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    float getRightRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg);

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr wall_found_publisher_;
    rclcpp::Client<cpp_turtle::srv::FindWall>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;

    bool finding_wall_;
    float distance_to_wall_;
    float wall_distance_tolerance_;
    float distance_threshold_;
    float find_wall_distance;
};

#endif  // ROBOT_DRIVER_HPP_
