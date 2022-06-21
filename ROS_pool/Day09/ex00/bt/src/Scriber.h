#ifndef SCRIBER_H
# define SCRIBER_H

# include <ros/ros.h>
# include "behaviortree_cpp_v3/bt_factory.h"
# include <std_msgs/UInt16.h>

class Scriber : public BT::SyncActionNode
{
    private:
        ros::Subscriber data;
        ros::NodeHandle nh;
        bool flag = false;
 
    public:
        Scriber(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {
            data = nh.subscribe<std_msgs::UInt16>("/repeat_times", 100, &Scriber::msg_check, this);
        }

        static BT::PortsList providedPorts() {
            return { BT::OutputPort<uint16_t>("num_output") };
        }

        BT::NodeStatus tick() override {
            if (flag == false) {
                return BT::NodeStatus::FAILURE;
            }
            flag = false;
            return BT::NodeStatus::SUCCESS;
        }

        void	msg_check(const std_msgs::UInt16::ConstPtr& msg) {
            flag = true;
            setOutput("num_output", msg->data);
        }
};

#endif
