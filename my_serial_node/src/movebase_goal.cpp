#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_datatypes.h>

#include <boost/thread.hpp>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void spinThread(){
  ros::spin();
}

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  ros::NodeHandle n;

  boost::thread spin_thread = boost::thread(boost::bind(&spinThread));

//  MoveBaseClient ac("pose_base_controller");
MoveBaseClient ac("move_base", true);
  //give some time for connections to register
  sleep(2.0);

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 2 meters forward
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x =0.798;
  goal.target_pose.pose.position.y = 3.771;
    goal.target_pose.pose.position.z = 0.0;
  goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(M_PI);
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("we do it success");
  else
    ROS_INFO("The base failed to move forward 2 meters for some reason");

  return 0;
}
