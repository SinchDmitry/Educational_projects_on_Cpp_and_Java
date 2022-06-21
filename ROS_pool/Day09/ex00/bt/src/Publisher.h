#ifndef PUBLISHER_H
# define PUBLISHER_H

# include <ros/ros.h>
# include "behaviortree_cpp_v3/bt_factory.h"
# include <std_msgs/UInt16.h>
# include <std_msgs/String.h>

class Publisher : public BT::SyncActionNode
{
    private:

        ros::Publisher pub;
        ros::NodeHandle nh;

    public:
    
        Publisher(const std::string& name, const BT::NodeConfiguration& config)
         : BT::SyncActionNode(name, config) {
            pub = nh.advertise<std_msgs::String>("/hello_message", 100);
        }

        static BT::PortsList providedPorts() {
            return { BT::InputPort<uint16_t>("num_of_print") };
        }

        BT::NodeStatus tick() override {
            BT::Optional<uint16_t> msg = getInput<uint16_t>("num_of_print");
            if (!msg) {
                throw BT::RuntimeError("missing required input [num_of_print]: ", msg.error() );
            }
            std_msgs::String a;
            a.data = "Hello ROS!";
            for (int i = 0; i < msg.value(); i++) {
                pub.publish(a);
            }
            return BT::NodeStatus::SUCCESS;
        }
};

#endif
