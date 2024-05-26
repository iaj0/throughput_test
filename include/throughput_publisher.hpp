#pragma once

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
using namespace std::chrono_literals;

namespace composition{
    class ThroughputPublisher : public rclcpp::Node {
    public:
        ThroughputPublisher(const rclcpp::NodeOptions& options);
    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
        rclcpp::TimerBase::SharedPtr timer;

        float linear_x = 1.0;
        float linear_y = 1.0;
        float linear_z = 1.0;

    };
}// namespace composition