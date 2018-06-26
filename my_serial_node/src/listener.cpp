#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8MultiArray.h"  

#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include "crc.h"
//回调函数
crc::CRC cc_crc;
class Listener
{
public:
  void callback(const std_msgs::UInt8MultiArray::ConstPtr& r_buffer);
};
void Listener::callback(const std_msgs::UInt8MultiArray::ConstPtr& r_buffer)
{
  if(r_buffer->data[1]==0x7e)
 {
 
  //ROS_INFO("I heard:");//, serial_data->data);
   ROS_INFO("listener heard: %x %d ",r_buffer->data[0],cc_crc.cc11);
   }
   else
   {
     ROS_INFO("wrong");//, serial_data->data);
   }
   
}
//void callback(const std_msgs::String::ConstPtr& msg)
//{
// ROS_INFO("listener got: [%s]", msg->data.c_str());
//}
int main(int argc, char **argv)
{
 ros::init(argc, argv, "listener");
 ros::NodeHandle n;
 //订阅主题
// ros::Subscriber sub = n.subscribe("sensor", 1000, callback);
  Listener listener;
  ros::Subscriber sub = n.subscribe("sensor", 1000, &Listener::callback, &listener);
      //ros::Publisher sensor_pub = n.advertise<std_msgs::UInt8MultiArray>("sensor", 1000);
  
 ros::spin();
 return 0;
}
