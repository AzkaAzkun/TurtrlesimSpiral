#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>

class publisherTurtlesim : public rclcpp::Node
{
public:
    publisherTurtlesim() : Node("publisher_turtlesim"), count_ (0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&publisherTurtlesim::timer_callback, this));
    }
private:
    void timer_callback(){
        geometry_msgs::msg::Twist msg;
        msg.linear.x =  2+count_ * 0.01;
        msg.angular.z = 1.5;
        publisher_->publish(msg);

        count_++;
    }
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};

int main(int argc,char **argv){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<publisherTurtlesim>());
    rclcpp::shutdown();
}