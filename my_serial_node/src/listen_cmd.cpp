/*
 * listen_cmd.cpp
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
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void cmd_vel_callback(const geometry_msgs::Twist& vel_cmd)
{ 
    ROS_INFO("I heard: [%f] [%f]", vel_cmd.linear.x,vel_cmd.linear.y);
    std::cout << "Twist Received " << std::endl;
}


int main( int argc, char* argv[] )
{
ros::init(argc, argv, "toeminator_publisher" );

ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("/cmd_vel", 1000, cmd_vel_callback);

while( n.ok() ) 
{
    ros::spin();
}

return 1;
}
