#ifndef THROUGHPUT_SUBSCRIBER_HPP
#define THROUGHPUT_SUBSCRIBER_HPP

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

namespace composition {

class ThroughputSubscriber : public rclcpp::Node {
public:
    explicit ThroughputSubscriber(const rclcpp::NodeOptions &options);
    
private:
    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
};

} // namespace composition

#endif // THROUGHPUT_SUBSCRIBER_HPP
