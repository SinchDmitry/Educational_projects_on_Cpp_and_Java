#ifndef PATROL_BOT_H
# define PATROL_BOT_H

# include <ros/ros.h>
# include "behaviortree_cpp_v3/bt_factory.h"
# include <std_msgs/UInt16.h>
# include <std_msgs/String.h>
# include <geometry_msgs/Twist.h>

struct  velosity {
    double  x;
    double  y;
    double  t;
} vel_data;

#endif