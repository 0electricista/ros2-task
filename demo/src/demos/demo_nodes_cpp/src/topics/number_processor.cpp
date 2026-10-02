#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class number_processor : public rclcpp::Node
{
  public:
    number_processor()
    : Node("number_processor"), count_(0)
    {
        
      sub_ = create_subscription<std_msgs::msg::String>("chatter", 10, 
      std::bind(&number_processor::callback, this, std::placeholders::_1));
      

      pub_ = this->create_publisher<std_msgs::msg::String>("processed_data", 10);

    }

  private:


    void callback(const std_msgs::msg::String & msg_in) {
      size_t pos = msg_in.data.find(": ");
      std::string num_str = msg_in.data.substr(pos + 2);
      int primo = std::stoi(num_str);

      int cuadrado = primo*primo;

      auto msg_out = std_msgs::msg::String();
      msg_out.data = "[PROCESADO]: " + std::to_string(cuadrado);

      RCLCPP_INFO(this->get_logger(), "'%s'", 
                 msg_out.data.c_str());

      pub_->publish(msg_out);

    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<number_processor>());
  rclcpp::shutdown();
  return 0;
}