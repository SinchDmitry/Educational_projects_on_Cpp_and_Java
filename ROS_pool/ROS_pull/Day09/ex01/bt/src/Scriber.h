#ifndef SCRIBER_H
# define SCRIBER_H

# include "patrol_bot.h"

class Scriber : public BT::SyncActionNode
{
    private:
        ros::Subscriber     data;
        ros::NodeHandle     nh;
        int                 counter;
        int                 iter_counter;
        int                 loop;
        XmlRpc::XmlRpcValue points;

    public:
        Scriber(const std::string& name, const BT::NodeConfiguration& config)
        : BT::SyncActionNode(name, config) {
            counter = 0;
            iter_counter = 0;
            nh.getParam("time_to_repeat", loop);
            nh.getParam("points", points);
            ROS_ASSERT(points.getType() == XmlRpc::XmlRpcValue::TypeArray);
            for (int32_t i = 0; i < points.size(); i++) {
                ROS_ASSERT(points[i].getType() == XmlRpc::XmlRpcValue::TypeArray);
                for (int32_t j = 0; j < points[i].size(); j++) { 
                    ROS_ASSERT(points[i][j].getType() == XmlRpc::XmlRpcValue::TypeDouble);
                }
            }
        }

        static BT::PortsList providedPorts() {
            return { BT::OutputPort<velosity>("data_output") };
        }

        BT::NodeStatus tick() override {
            while (loop == -1 || iter_counter < loop) {
                if (counter < points.size()) {
                    vel_data.x = points[counter][0];
                    vel_data.y = points[counter][1]; 
                    vel_data.t = points[counter][2];
                    counter++;
                } else {
                    counter = 0;
                    iter_counter++;
                }
                if (counter != 0) {
                    setOutput("data_output", vel_data);
                    return BT::NodeStatus::SUCCESS;
                }
            }
            return BT::NodeStatus::FAILURE;
        }

};

#endif