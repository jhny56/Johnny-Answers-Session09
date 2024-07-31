#ifndef WALL_FINDER_NODE_HPP_
#define WALL_FINDER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/bool.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "cpp_turtle/srv/find_wall.hpp"


class WallFinderNode : public rclcpp::Node
{
public:
    WallFinderNode();
    
private:
    void laser_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void find_wall_logic(const sensor_msgs::msg::LaserScan::SharedPtr msg, geometry_msgs::msg::Twist &twist);
    float getFrontRegion(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    void find_wall_service_callback(const std::shared_ptr<cpp_turtle::srv::FindWall::Request> request,
                                    std::shared_ptr<cpp_turtle::srv::FindWall::Response> response);


    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr wall_found_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twist_publisher_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_subscription_;
    rclcpp::Service<cpp_turtle::srv::FindWall>::SharedPtr find_wall_service_;

    float find_wall_distance;
    bool finding_wall_;
};

#endif  // WALL_FINDER_NODE_HPP_
