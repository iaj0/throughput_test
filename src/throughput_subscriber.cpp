#include "../include/throughput_subscriber.hpp"
#include <iostream>

namespace composition {

ThroughputSubscriber::ThroughputSubscriber(const rclcpp::NodeOptions &options)
: Node("throughput_subscriber", options) {
    subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "throughput", 
        10, 
        std::bind(&ThroughputSubscriber::topic_callback, this, std::placeholders::_1)
    );
}

void ThroughputSubscriber::topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const {
    RCLCPP_INFO(this->get_logger(), "Received message: linear.x = '%.2f', linear.y = '%.2f'", msg->linear.x, msg->linear.y);
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(composition::ThroughputSubscriber)
