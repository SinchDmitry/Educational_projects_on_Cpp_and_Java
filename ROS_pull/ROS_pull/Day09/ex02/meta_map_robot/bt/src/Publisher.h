#ifndef PUBLISHER_H
# define PUBLISHER_H

# include "patrol_bot.h"

class Publisher : public BT::SyncActionNode
{
    private :
    ros::NodeHandle nh;
    ros::Subscriber battary;
    //define a client for to send goal requests to the move_base server through a SimpleActionClient
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac;
    
    public:
    
    Publisher(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config), ac("move_base", true) {
            battary = nh.subscribe("/battery_status", 100, &Publisher::check_battary, this);
        }

    static BT::PortsList providedPorts() {
        return { BT::InputPort<velosity>("data_array") };
    }

    BT::NodeStatus tick() override {
        ROS_INFO("Pub | flag : %d", g_flag);
        BT::Optional<velosity> msg = getInput<velosity>("data_array");
        if (!msg) {
            throw BT::RuntimeError("missing required input [data_array]: ", msg.error() );
        }
        std::cout << "Moving to x : " << vel_data.x << " | y : " << vel_data.y << " | angle : " \
            << vel_data.t << std::endl;
        moveToGoal(vel_data.x, vel_data.y, vel_data.t);
        
        if (driver() == true) {
            g_flag = 0;
        }
        return BT::NodeStatus::SUCCESS;
    }

    bool    driver() {
        ros::Rate   loop_rate(10);
        while (g_flag != 2) {
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
                ROS_INFO("You have reached the destination");
                return true;
            }
            ros::spinOnce();
            loop_rate.sleep();
        }
        return false;
    }

    void    check_battary(const std_msgs::UInt16Ptr& msg) {
        if (msg->data < 50) {
            g_flag = 2;
        }
    }
    
    void    moveToGoal(double xGoal, double yGoal, double tGoal) {

        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))) {
            ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        //set up the frame parameters
        ROS_INFO("**********************************************************************************");
        ROS_INFO("**********************************************************************************");
        ROS_INFO("Publisher");
        ROS_INFO("**********************************************************************************");
        ROS_INFO("**********************************************************************************");

        goal.target_pose.header.frame_id = "map";
        goal.target_pose.header.stamp = ros::Time::now();

        /* moving towards the goal*/

        goal.target_pose.pose.position.x =  xGoal;
        goal.target_pose.pose.position.y =  yGoal;
        goal.target_pose.pose.position.z =  0.0;
        goal.target_pose.pose.orientation.x = 0.0;
        goal.target_pose.pose.orientation.y = 0.0;
        goal.target_pose.pose.orientation.z = tGoal;
        goal.target_pose.pose.orientation.w = 1.0;

        ROS_INFO("Sending goal location ...");
        ac.sendGoal(goal);
        g_flag == 1;
        // ac.waitForResult();

        }
};

#endif