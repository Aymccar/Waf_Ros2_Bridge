#include "bridge_subscriber_array.hpp"

#include <rclcpp/rclcpp.hpp>

#include <functional>

BridgeSubscriberArray::BridgeSubscriberArray(std::function<void(std::vector<int>)> callback):
    BridgeSubscriber()
{
    user_callback = callback;
}

void BridgeSubscriberArray::callback(std_msgs::msg::Int32MultiArray::SharedPtr msg){
    data = std::vector(msg->data);
    user_callback(data);
}
