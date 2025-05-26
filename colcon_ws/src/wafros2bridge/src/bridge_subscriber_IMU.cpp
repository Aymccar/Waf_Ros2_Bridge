#include "bridge_subscriber_IMU.hpp"

#include <rclcpp/rclcpp.hpp>

#include <functional>

BridgeSubscriberIMU::BridgeSubscriberIMU(std::function<void(user_msg_t)> callback):
    BridgeSubscriber()
{
    user_callback = callback;
}

void BridgeSubscriberIMU::callback(sensor_msgs::msg::Imu::SharedPtr msg){
    data.accel_x = msg->linear_acceleration.x;
    data.accel_y = msg->linear_acceleration.y;
    data.accel_z = msg->linear_acceleration.z;

    data.gyro_x = msg->angular_velocity.x;
    data.gyro_y = msg->angular_velocity.y;
    data.gyro_z = msg->angular_velocity.z;

    user_callback(data);
}
