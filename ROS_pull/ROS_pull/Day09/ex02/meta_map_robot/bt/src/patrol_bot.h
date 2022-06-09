#ifndef PATROL_BOT_H
# define PATROL_BOT_H

# include <ros/ros.h>
# include <actionlib/client/simple_action_client.h>
# include <move_base_msgs/MoveBaseAction.h>
# include "behaviortree_cpp_v3/bt_factory.h"
# include <std_msgs/UInt16.h>
# include <std_msgs/String.h>
# include <geometry_msgs/Twist.h>

struct  velosity {
    double  x;
    double  y;
    double  t;
} vel_data;

int g_flag = 0;

#endif