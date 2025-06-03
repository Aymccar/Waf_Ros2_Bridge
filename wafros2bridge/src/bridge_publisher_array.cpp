#include "bridge_publisher_array.hpp"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <vector>


BridgePublisherArray::BridgePublisherArray(Publisher_int_array_t publisher):
    BridgePublisher()
{
    publisher_ = publisher;
}

void BridgePublisherArray::publish(uint16_t* data, size_t n)
{
    std_msgs::msg::Int32MultiArray ros_msg;

    std::vector<int> vec(data, data+n);

    ros_msg.data = vec;
    publisher_->publish(ros_msg);
}

