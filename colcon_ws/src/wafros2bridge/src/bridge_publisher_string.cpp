#include "bridge_publisher_string.hpp"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>


BridgePublisherString::BridgePublisherString(Publisher_string_t publisher):
    BridgePublisher()
{
    publisher_ = publisher;
}

void BridgePublisherString::publish(std::string msg)
{
    std_msgs::msg::String ros_msg;
    ros_msg.data = msg;
    publisher_->publish(ros_msg);
}

