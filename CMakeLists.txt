# cmake_minimum_required(VERSION 3.8)
# project(throughput_test)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)
# # uncomment the following section in order to fill in
# # further dependencies manually.
# # find_package(<dependency> REQUIRED)

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # uncomment the line when a copyright and license is not present in all source files
#   #set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # uncomment the line when this package is not in a git repo
#   #set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()

# cmake_minimum_required(VERSION 3.5)
# project(throughput_test)

# include_directories(include)

# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(rclcpp_components REQUIRED)
# find_package(geometry_msgs REQUIRED)

# add_library(throughput_publisher SHARED src/throughput_publisher.cpp)
# ament_target_dependencies(throughput_publisher rclcpp rclcpp_components geometry_msgs)

# add_library(throughput_subscriber SHARED src/throughput_subscriber.cpp)
# ament_target_dependencies(throughput_subscriber rclcpp rclcpp_components geometry_msgs)

# rclcpp_components_register_nodes(throughput_publisher "composition::ThroughputPublisher")
# rclcpp_components_register_nodes(throughput_subscriber "composition::ThroughputSubscriber")

# add_executable(throughput_publisher src/throughput_publisher.cpp)
# ament_target_dependencies(throughput_publisher rclcpp rclcpp_components geometry_msgs)
# add_executable(throughput_subscriber src/throughput_subscriber.cpp)
# ament_target_dependencies(throughput_subscriber rclcpp rclcpp_components geometry_msgs)

# install(TARGETS
#   throughput_publisher
#   throughput_subscriber
#   DESTINATION lib/${PROJECT_NAME})

# ament_package()


# cmake_minimum_required(VERSION 3.5)
# project(throughput_test)

# include_directories(include)

# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(rclcpp_components REQUIRED)
# find_package(geometry_msgs REQUIRED)

# add_library(throughput_publisher_component SHARED src/throughput_publisher.cpp)
# ament_target_dependencies(throughput_publisher_component rclcpp rclcpp_components geometry_msgs)

# add_library(throughput_subscriber_component SHARED src/throughput_subscriber.cpp)
# ament_target_dependencies(throughput_subscriber_component rclcpp rclcpp_components geometry_msgs)

# rclcpp_components_register_nodes(throughput_publisher_component "composition::ThroughputPublisher")
# rclcpp_components_register_nodes(throughput_subscriber_component "composition::ThroughputSubscriber")

# add_executable(throughput_publisher_node src/throughput_publisher.cpp)
# ament_target_dependencies(throughput_publisher_node rclcpp rclcpp_components geometry_msgs)
# add_executable(throughput_subscriber_node src/throughput_subscriber.cpp)
# ament_target_dependencies(throughput_subscriber_node rclcpp rclcpp_components geometry_msgs)

# install(TARGETS
#   throughput_publisher_component
#   throughput_subscriber_component
#   throughput_publisher_node
#   throughput_subscriber_node
#   DESTINATION lib/${PROJECT_NAME})

# ament_package()

cmake_minimum_required(VERSION 3.8)
project(throughput_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)

# Add the publisher library
add_library(throughput_publisher_component SHARED src/throughput_publisher.cpp)
ament_target_dependencies(throughput_publisher_component rclcpp rclcpp_components geometry_msgs)
rclcpp_components_register_nodes(throughput_publisher_component "composition::ThroughputPublisher")

# Add the subscriber library
add_library(throughput_subscriber_component SHARED src/throughput_subscriber.cpp)
ament_target_dependencies(throughput_subscriber_component rclcpp rclcpp_components geometry_msgs)
rclcpp_components_register_nodes(throughput_subscriber_component "composition::ThroughputSubscriber")

# Create a container executable to load the composable nodes
add_executable(throughput_test_container src/container.cpp)
ament_target_dependencies(throughput_test_container rclcpp rclcpp_components)

install(TARGETS
  throughput_publisher_component
  throughput_subscriber_component
  throughput_test_container
  DESTINATION lib/${PROJECT_NAME})

ament_package()