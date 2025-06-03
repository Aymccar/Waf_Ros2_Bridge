#include "bridge_subscriber_array.hpp"

#include <rclcpp/rclcpp.hpp>

#include <functional>

BridgeSubscriberArrayInt::BridgeSubscriberArrayInt(std::function<void(array_int_msg_t)> callback):
    BridgeSubscriber()
{
    user_callback = callback;
}

void BridgeSubscriberArrayInt::callback(std_msgs::msg::Int32MultiArray::SharedPtr msg){
    data.data = std::vector(msg->data);
    user_callback(data);
}

BridgeSubscriberArrayFloat::BridgeSubscriberArrayFloat(std::function<void(array_float_msg_t)> callback):
    BridgeSubscriber()
{
    user_callback = callback;
}

void BridgeSubscriberArrayFloat::callback(std_msgs::msg::Float32MultiArray::SharedPtr msg){
    data.data = std::vector(msg->data);
    user_callback(data);
}
