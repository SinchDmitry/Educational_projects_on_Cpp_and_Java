#ifndef CHARGER_H
# define CHARGER_H

# include "patrol_bot.h"

class Charger : public BT::SyncActionNode
{
    private :

    XmlRpc::XmlRpcValue point_ch;
    ros::NodeHandle     nh;
    ros::Subscriber     battary;
    double              x, y, t;

    public:
    
    Charger(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) { 
            nh.getParam("dock_station_pose", point_ch);
            ROS_ASSERT(point_ch.getType() == XmlRpc::XmlRpcValue::TypeArray);
            for (int32_t i = 0; i < point_ch.size(); i++) {
                ROS_ASSERT(point_ch[i].getType() == XmlRpc::XmlRpcValue::TypeDouble);
            }
            x = point_ch[0];
            y = point_ch[1];
            t = point_ch[2];
            battary = nh.subscribe("/battery_status", 100, &Charger::check_battary, this);
            ROS_INFO("ch");
        }
    
    static BT::PortsList providedPorts() { return {};
    }

    BT::NodeStatus tick() override {
        ROS_INFO("TIC | flag : %d", g_flag);
        ros::Rate   loop_rate(10);
        if (g_flag == 2) {
            std::cout << "Moving to x : " << x << " | y : " << y << " | angle : " << t << std::endl;
            if (moveToGoal(x, y, t)) {
                while (g_flag != 1) {
                    ros::spinOnce();
                    loop_rate.sleep();
                }
                return BT::NodeStatus::SUCCESS;
            }
            throw BT::RuntimeError("missing required input [data_array]");
        }
        ROS_INFO("TO_CALC | flag : %d", g_flag);
        return BT::NodeStatus::SUCCESS;
    }

    void    check_battary(const std_msgs::UInt16Ptr& msg) {
        if (msg->data == 100) {
            g_flag = 1;
        }
    }

    bool moveToGoal(double xGoal, double yGoal, double tGoal) {

        //define a client for to send goal requests to the move_base server through a SimpleActionClient
        actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))) {
            ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        //set up the frame parameters
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

        ac.waitForResult();

        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
            ROS_INFO("You have reached the destination");
            return true;
        }
        else {
            ROS_INFO("The robot failed to reach the destination");
            return false;
        }
    }
};

#endif
