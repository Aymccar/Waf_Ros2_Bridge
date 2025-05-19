cmake_minimum_required(VERSION 3.8)
project(wafros2bridge)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

# Add your shared library
add_library(${PROJECT_NAME} SHARED
    src/bridge_server.cpp
    src/bridge_publisher_string.cpp
    src/bridge_node.cpp
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  std_msgs
)

ament_export_targets(${PROJECT_NAME} HAS_LIBRARY_TARGET)

# Install the library
install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  DESTINATION lib
  INCLUDES DESTINATION include
)

ament_package()
