#include "bridge_subscriber_array.hpp"

#include <rclcpp/rclcpp.hpp>

#include <functional>

BridgeSubscriberArray::BridgeSubscriberArray(std::function<void(array_msg_t)> callback):
    BridgeSubscriber()
{
    user_callback = callback;
}

void BridgeSubscriberArray::callback(std_msgs::msg::Int32MultiArray::SharedPtr msg){
    data.data = std::vector(msg->data);
    user_callback(data);
}
