#include <ros/ros.h>
#include <ros/package.h>
#include "behaviortree_cpp_v3/bt_factory.h"
#include "Scriber.h"
#include "Publisher.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "tree");
    BT::BehaviorTreeFactory factory;
    std::string all_path;

    factory.registerNodeType<Scriber>("Calculator");
    factory.registerNodeType<Publisher>("Move_maker");

    ros::package::getPath("bt") + "/my_tree.xml";
    auto tree = factory.createTreeFromFile(allpath);

    tree.tickRoot();
    return 0;
}
