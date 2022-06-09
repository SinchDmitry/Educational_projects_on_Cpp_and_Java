#include <ros/ros.h>
#include <ros/package.h>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv/ImgProcessingConfig.h>
#include <dynamic_reconfigure/server.h>

class ImageConverter {
    private :
        ros::NodeHandle nh;
        image_transport::ImageTransport it;
        image_transport::Publisher pub_gamma;
        image_transport::Publisher pub_br;
        image_transport::Subscriber sub;
        dynamic_reconfigure::Server<opencv::ImgProcessingConfig> server;
        dynamic_reconfigure::Server<opencv::ImgProcessingConfig>::CallbackType f;
        int contrast;
        int brightness;
        int gamma;

    public :
        ImageConverter() : it(nh) {
            sub = it.subscribe("/image/color", 1, &ImageConverter::get_color_pic, this);
            pub_gamma = it.advertise("/image/gamma", 1);
            pub_br = it.advertise("/image/contrast_brightness", 1);
            f = boost::bind(&ImageConverter::callback, this, _1, _2);
            server.setCallback(f);
        }

        void    get_color_pic(const sensor_msgs::ImageConstPtr& msg) {
            cv_bridge::CvImagePtr cv_ptr;
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            cv::Mat image = cv_ptr->image;
            cv::Mat new_img;
            image.convertTo(new_img, -1, brightness, contrast);
            sensor_msgs::ImagePtr msg_pub = cv_bridge::CvImage(std_msgs::Header(), "bgr8", new_img).toImageMsg();
            pub_br.publish(msg_pub);
            for( int y = 0; y < image.rows; y++ ) {
                for( int x = 0; x < image.cols; x++ ) {
                    for( int c = 0; c < image.channels(); c++ ) {
                        new_img.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>(pow((image.at<cv::Vec3b>(y, x)[c] / 255.0), (1.0 / gamma)) * 255.0);
                    }
                }
            }
            msg_pub = cv_bridge::CvImage(std_msgs::Header(), "bgr8", new_img).toImageMsg();
            pub_gamma.publish(msg_pub);
        }

        void    callback(opencv::ImgProcessingConfig &config, uint32_t level) {  
            // ROS_INFO("Reconfigure Request: %f %f %f",
            // config.contrast, config.brightness,
            // config.gamma);
            contrast = config.contrast;
            brightness = config.brightness;
            gamma = config.gamma;
        }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "grey_picture");
    ImageConverter correction;
    ros::spin();
}