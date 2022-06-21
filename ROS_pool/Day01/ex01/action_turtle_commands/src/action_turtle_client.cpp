#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <action_turtle_commands/Message_turtle_commandsAction.h>

typedef	actionlib::SimpleActionClient<action_turtle_commands::Message_turtle_commandsAction> client;

void	action(client &ac, std::string command, int distance, int angle)
{
	action_turtle_commands::Message_turtle_commandsGoal goal;
	goal.command = command;
	goal.s = distance;
	goal.angle = angle;
	ac.sendGoal(goal);
	bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));
	if (finished_before_timeout)
	{
    	actionlib::SimpleClientGoalState state = ac.getState();
    	ROS_INFO("Action finished: %s",state.toString().c_str());
  	}
  	else
    	ROS_INFO("Action did not finish before the time out.");
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "action_client");
	// actionlib::SimpleActionClient<action_turtle_commands::Message_turtle_commandsAction> ac("my_action_server", true);
	client ac("my_action_server", true);
	ROS_INFO("Waiting for action server to start.");
	ac.waitForServer();
	ROS_INFO("Action server started, sending goal.");
	action(ac, "forward", 3, 0);
	action(ac, "turn_right", 0, 90);
	action(ac, "forward", 1, 0);
  	return 0;
}
