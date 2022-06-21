#include <ros/ros.h>
#include <ros/package.h>
#include "behaviortree_cpp_v3/bt_factory.h"
#include "Scriber.h"
#include "Publisher.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "tree");
    BT::BehaviorTreeFactory factory;
    std::string all_path;

    factory.registerNodeType<Scriber>("Subscriber");
    factory.registerNodeType<Publisher>("Publisher");

    all_path = ros::package::getPath("bt") + "/my_tree.xml";
    auto tree = factory.createTreeFromFile(all_path);

    ros::Rate loop_rate(10);
    while (ros::ok()) {
        tree.tickRoot();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
