#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include <actionlib/server/simple_action_server.h>
#include <action_turtle_commands/Message_turtle_commandsAction.h>
#include "turtlesim/Pose.h"
#include <math.h>

turtlesim::Pose	g_pos;

void poseCallback(const turtlesim::Pose::ConstPtr& msg) {
	g_pos.x = msg->x;
	g_pos.y = msg->y;
}

class TurtleAction
{
protected:
	ros::NodeHandle nh_;
	actionlib::SimpleActionServer<action_turtle_commands::Message_turtle_commandsAction> as_;
	std::string action_name_;
	action_turtle_commands::Message_turtle_commandsFeedback feedback_;
	action_turtle_commands::Message_turtle_commandsResult result_;
	ros::Publisher pub;
	ros::Subscriber sub;
public:

	TurtleAction(std::string name) :
	as_(nh_, name, boost::bind(&TurtleAction::executeCB, this, _1), false),
	action_name_(name)
	{
		as_.start();
		pub = nh_.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
		sub = nh_.subscribe("turtle1/pose", 100, poseCallback);
	}

	~TurtleAction(void)
	{
	}

	void executeCB(const action_turtle_commands::Message_turtle_commandsGoalConstPtr &goal)
	{
		// helper variables
		ros::Rate r(10);
		geometry_msgs::Twist	vel;
		float					x_st;
		float					y_st;
		int						dist = 0;
		unsigned int			time = 0;
		bool 					success = true;

		x_st = g_pos.x;
		y_st = g_pos.y;
		feedback_.odom = 0;
		if (as_.isPreemptRequested() || !ros::ok()){
				ROS_INFO("%s: Preempted", action_name_.c_str());
				as_.setPreempted();
				success = false;
		}
		if (goal->command == "turn_right") vel.angular.z = -(goal->angle * 3.14f) / 180;
		if (goal->command == "turn_left") vel.angular.z = (goal->angle * 3.14f) / 180;
		if (goal->command == "forward") vel.linear.x = goal->s;
		pub.publish(vel);
		if (goal->command == "turn_left" || goal->command == "turn_right")
			sleep(1);
		while (dist < goal->s){
			dist = (int)sqrt(pow(abs(x_st - g_pos.x), 2) + pow(abs(y_st - g_pos.y), 2));
			if (time > 300 || !ros::ok()){
				ROS_INFO("%s: Preempted", action_name_.c_str());
				as_.setPreempted();
				success = false;
				break ;
			}
			if (dist > feedback_.odom + 1){
				feedback_.odom += 1;
				as_.publishFeedback(feedback_);
			}
			r.sleep();
			time++;
		}
		if (success){
			ROS_INFO("%s: Succeeded", action_name_.c_str());
			as_.setSucceeded(result_);
		}
	}

};


int main(int argc, char** argv)
{
	ros::init(argc, argv, "action_server");
	TurtleAction turtle("my_action_server");	
	ros::spin();
	return 0;
}