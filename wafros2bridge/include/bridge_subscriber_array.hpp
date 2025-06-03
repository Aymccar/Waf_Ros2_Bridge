#pragma once
#include "bridge_subscriber.hpp"

#include <vector>
#include <functional>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32_multi_array.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>

using Subscriber_int_array_t = rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr;
using Subscriber_float_array_t = rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr;

struct array_int_msg_t {
    std::vector<int> data;
};

struct array_float_msg_t {
    std::vector<float> data;
};

class BridgeSubscriberArrayInt : public BridgeSubscriber {
public:
    BridgeSubscriberArrayInt(std::function<void(array_int_msg_t)> callback);
    //TODO Destructor

    void set_subscriber(Subscriber_int_array_t subscriber){subscriber_ = subscriber;};

    void callback(std_msgs::msg::Int32MultiArray::SharedPtr msg);
    array_int_msg_t get() const {return data;};

private:
    Subscriber_int_array_t subscriber_;

    array_int_msg_t data;
    std::function<void(array_int_msg_t)> user_callback;
};


class BridgeSubscriberArrayFloat : public BridgeSubscriber {
public:
    BridgeSubscriberArrayFloat(std::function<void(array_float_msg_t)> callback);
    //TODO Destructor

    void set_subscriber(Subscriber_float_array_t subscriber){subscriber_ = subscriber;};

    void callback(std_msgs::msg::Float32MultiArray::SharedPtr msg);
    array_float_msg_t get() const {return data;};

private:
    Subscriber_float_array_t subscriber_;

    array_float_msg_t data;
    std::function<void(array_float_msg_t)> user_callback;
};
