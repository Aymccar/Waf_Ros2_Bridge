#pragma once
#include "bridge_subscriber.hpp"

#include <functional>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

using Subscriber_IMU_t = rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr;
struct user_msg_t {
    float accel_x;
    float accel_y;
    float accel_z;

    float gyro_x;
    float gyro_y;
    float gyro_z;
};

class BridgeSubscriberIMU : public BridgeSubscriber {
public:
    BridgeSubscriberIMU(std::function<void(user_msg_t)> callback);
    //TODO Destructor

    void set_subscriber(Subscriber_IMU_t subscriber){subscriber_ = subscriber;};

    void callback(sensor_msgs::msg::Imu::SharedPtr msg);
    user_msg_t get() const {return data;};

private:
    Subscriber_IMU_t subscriber_;

    user_msg_t data;
    std::function<void(user_msg_t)> user_callback;
};
