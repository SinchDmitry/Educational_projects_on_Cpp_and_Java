#include <ros/ros.h>
#include <ros/package.h>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv/CannyDetectionConfig.h>
#include <dynamic_reconfigure/server.h>

class ImageConverter {
    private :
        ros::NodeHandle nh;
        image_transport::ImageTransport it;
        image_transport::Publisher pub_canny;
        // image_transport::Publisher pub_gamma;
        // image_transport::Publisher pub_br;
        image_transport::Subscriber sub;
        dynamic_reconfigure::Server<opencv::CannyDetectionConfig> server;
        dynamic_reconfigure::Server<opencv::CannyDetectionConfig>::CallbackType f;
        double canny_low_threshold;
        double canny_high_threshold;
        int blure_kernel_size;
        int canny_kernel_size;

    public :
        ImageConverter() : it(nh) {
            sub = it.subscribe("/image/origin", 1, &ImageConverter::get_color_pic, this);
            pub_canny = it.advertise("/image/canny", 1);
            f = boost::bind(&ImageConverter::callback, this, _1, _2);
            server.setCallback(f);
        }

        void    get_color_pic(const sensor_msgs::ImageConstPtr& msg) {
            cv_bridge::CvImagePtr cv_ptr;
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            cv::Mat image = cv_ptr->image;
            cv::Mat new_img;
            cv::cvtColor(image, new_img, CV_BGR2GRAY);
            // image.convertTo(new_img, -1, brightness, contrast);
            cv::GaussianBlur(new_img, image, cv::Size(blure_kernel_size, blure_kernel_size), 0);
            cv::Canny(image, new_img, canny_low_threshold, canny_high_threshold, canny_kernel_size);
            sensor_msgs::ImagePtr msg_pub = cv_bridge::CvImage(std_msgs::Header(), "mono8", new_img).toImageMsg();
            pub_canny.publish(msg_pub);
            
        }

        void    callback(opencv::CannyDetectionConfig &config, uint32_t level) { 
            canny_low_threshold = config.canny_low_threshold;
            canny_high_threshold = config.canny_high_threshold;
            blure_kernel_size = config.blure_kernel_size;
            canny_kernel_size = config.canny_kernel_size; 
        }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "grey_picture");
    ImageConverter correction;
    ros::spin();
}