/*
 * myserialnode.cpp
 * 
 * Copyright 2018 cc <>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include "ros/ros.h"
#include <serial/serial.h>
#include "crc.h"
#include "global.h"
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include "std_msgs/UInt8.h"
#include "std_msgs/UInt8MultiArray.h"
serial::Serial ros_ser;
crc::CRC cc_crc;
global::GLOBAL cc_global;

/*
 * 
 * name: 回调函数
 * @param:msg
 * @return:no
 * 
 */
void callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO_STREAM("Write to serial port:" << msg->data);
    ros_ser.write(msg->data);
}


int main (int argc, char** argv)
{
    static int counter;
    static int smx=0;
    static uint8_t s_buffer[100];
    int i;
    int tst1=1,tst2=2;
    static int p;
    unsigned int test_crc;

    std_msgs::UInt8MultiArray  r_buffer;
    ros::init(argc, argv, "myserialnode");
    ros::NodeHandle cc_setial1;
    //订阅主题command
    ros::Subscriber command_sub = cc_setial1.subscribe("command", 1000, callback);
    //发布主题sensor
    ros::Publisher sensor_pub = cc_setial1.advertise<std_msgs::UInt8MultiArray>("sensor", 1000);

    try
    {
        ros_ser.setPort("/dev/ttyUSB0");
        ros_ser.setBaudrate(38400);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ros_ser.setTimeout(to);
        ros_ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }
    if(ros_ser.isOpen())
    {
        ROS_INFO_STREAM("Serial Port opened");

    }
    else
    {
        return -1;
    }
    ros::Rate loop_rate(100);
    while(ros::ok())
    {

        ros::spinOnce();

        memset(s_buffer,0,sizeof(s_buffer));
        //7E 03 01 99 40 3A
        //数据打包
        s_buffer[0] = 0x7E;
        s_buffer[1] = 0x11;
        //VA
        s_buffer[2] = 0x01;
        s_buffer[3] = 0X01;
        //s_buffer[4] = 0X00;
        s_buffer[5] = 0;
        s_buffer[6] = 0;
        s_buffer[7] = 0;
        s_buffer[9] =0;
        s_buffer[10] = 0;
        s_buffer[11] = 0;
        s_buffer[12] = 0;
        s_buffer[13] = 0;
        s_buffer[14] = 0;
        s_buffer[15] = 0;
        s_buffer[16] = 0;
        s_buffer[17] = 0;

        counter++;
        if(counter>=10)
        {
            counter=0;
            cc_global.global_counter++;
            if(cc_global.global_counter>100)
                cc_global.global_counter=0;
            s_buffer[4]=cc_global.global_counter;
            s_buffer[18]=cc_crc.sum(s_buffer,1,5);
            test_crc= cc_crc.CRC16(&s_buffer[1],4);
            ros_ser.write(s_buffer,19);
            ROS_INFO("serial sends: 0x%x 0x%x 0X%x", s_buffer[4],s_buffer[18],test_crc);
            cc_crc.sayHello();
            
            
        }





        if(ros_ser.available())
        {

            ROS_INFO_STREAM("Reading from serial port");
            //std_msgs::String serial_data;
            std_msgs::UInt8MultiArray  serial_data;
            //获取串口数据
            p=ros_ser.available();
            ros_ser.read (serial_data .data,p) ;
            ROS_INFO("serial  heard: %x ", p);
            r_buffer.data.resize(p+1);
            r_buffer.data[0]=p;
            for(i=0; i<p; i++)
            {
                r_buffer.data[i+1]=serial_data .data[i];
            }
            sensor_pub.publish( r_buffer);
        }

        loop_rate.sleep();
    }
}
