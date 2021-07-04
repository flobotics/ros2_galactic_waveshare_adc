#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "ros2_galactic_waveshare_adc_interfaces/msg/waveshare_adc.hpp"
#include "rclcpp/node.hpp"


using namespace std::chrono_literals;


class WaveshareAdcPublisher : public rclcpp::Node
{
  public:
	WaveshareAdcPublisher()
    : Node("waveshare_adc_publisher"), count_(0)
    {
      publisher_ = this->create_publisher<ros2_galactic_waveshare_adc_interfaces::msg::WaveshareAdc>("topic", 10);
      timer_ = this->create_wall_timer(500ms,
    		  	  	  	  	  			std::bind(&WaveshareAdcPublisher::timer_callback,
    		  	  	  	  	  			this));
    }


  private:
    void timer_callback()
    {
      auto message = ros2_galactic_waveshare_adc_interfaces::msg::WaveshareAdc();
      message.adc0 = 0.3;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.adc0);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<ros2_galactic_waveshare_adc_interfaces::msg::WaveshareAdc>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaveshareAdcPublisher>());
  rclcpp::shutdown();
  return 0;
}
