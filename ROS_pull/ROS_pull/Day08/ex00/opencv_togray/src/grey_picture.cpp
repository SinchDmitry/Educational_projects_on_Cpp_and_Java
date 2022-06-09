#include <ros/ros.h>
#include <ros/package.h>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

class ImageConverter {
    private :
        ros::NodeHandle nh;
        image_transport::ImageTransport it;
        image_transport::Publisher pub;
        image_transport::Subscriber sub;

    public :
        ImageConverter() : it(nh) {
            sub = it.subscribe("/image/color", 1, &ImageConverter::get_color_pic, this);
            pub = it.advertise("/image/grey", 1);
        }

        void    get_color_pic(const sensor_msgs::ImageConstPtr& msg) {
            cv_bridge::CvImagePtr cv_ptr;
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            cv::Mat image = cv_ptr->image;
            cv::Mat new_img;
            cv::cvtColor(image, new_img, CV_BGR2GRAY); 
            sensor_msgs::ImagePtr msg_pub = cv_bridge::CvImage(std_msgs::Header(), "mono8", new_img).toImageMsg();
            pub.publish(msg_pub);
        }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "to_grey");
    ImageConverter to_gray;
    ros::spin();
}