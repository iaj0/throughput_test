#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/component_manager.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto options = rclcpp::NodeOptions();
  auto component_manager = std::make_shared<rclcpp_components::ComponentManager>(options);

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(component_manager);
  executor.spin();

  rclcpp::shutdown();
  return 0;
}