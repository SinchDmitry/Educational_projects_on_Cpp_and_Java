#ifndef PUBLISHER_H
# define PUBLISHER_H

# include "patrol_bot.h"

class Publisher : public BT::SyncActionNode
{
    public:
    
        Publisher(const std::string& name, const BT::NodeConfiguration& config)
         : BT::SyncActionNode(name, config) { }

        static BT::PortsList providedPorts() {
            return { BT::InputPort<velosity>("data_array") };
        }

        BT::NodeStatus tick() override {
            BT::Optional<velosity> msg = getInput<velosity>("data_array");
            if (!msg) {
                throw BT::RuntimeError("missing required input [data_array]: ", msg.error() );
            }
            std::cout << "Moving to x : " << vel_data.x << " | y : " << vel_data.y << " | angle : " \
                << vel_data.t << std::endl;
            sleep(2);
            std::cout << "Successfully reached x : " << vel_data.x << " | y : " << vel_data.y << " | angle : " \
                << vel_data.t << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

#endif