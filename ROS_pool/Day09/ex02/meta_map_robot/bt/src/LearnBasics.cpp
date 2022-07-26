#include <ros/ros.h>
#include <ros/package.h>
#include "behaviortree_cpp_v3/bt_factory.h"
#include "Scriber.h"
#include "Publisher.h"
#include "Charger.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "tree");
    BT::BehaviorTreeFactory factory;
    std::string all_path;

    factory.registerNodeType<Scriber>("Calculator");
    factory.registerNodeType<Charger>("to_charge");
    factory.registerNodeType<Publisher>("Move_maker");
    
    all_path = ros::package::getPath("bt") + "/my_tree.xml";
    auto tree = factory.createTreeFromFile(all_path);

    tree.tickRoot();
    // ros::spin();
    // ros::Rate loop_rate(10);
    // while (ros::ok()) {
    //     tree.tickRoot();
    //     ros::spinOnce();
    //     loop_rate.sleep();
    // }
    return 0;
}
