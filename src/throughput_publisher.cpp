#include "../include/throughput_publisher.hpp"
#include <iostream>

namespace composition {
    ThroughputPublisher::ThroughputPublisher(const rclcpp::NodeOptions& options) 
    : Node{"throughput_publisher", options} {
    // complete this code
    this->publisher = this->create_publisher<geometry_msgs::msg::Twist>("throughput", 10);
    //create publisher callback
    auto publisher_callback = [this](void) -> void {
        auto message = std::make_unique<geometry_msgs::msg::Twist>();
        message->linear.x = linear_x; //4 bytes
        message->linear.y = linear_y; //4 bytes

        this->publisher->publish(std::move(message));
    };
    //create timer
    timer = this->create_wall_timer(100ms, publisher_callback);

}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(composition::ThroughputPublisher)