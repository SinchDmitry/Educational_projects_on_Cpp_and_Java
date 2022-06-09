#include <ros/ros.h>
#include <ros/package.h>

#include <opencv2/aruco.hpp>
#include <tf/transform_broadcaster.h>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <dynamic_reconfigure/server.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

cv::Mat CameraMatrix(3, 3, CV_64F); 
cv::Mat DistCoeffs(1, 5, CV_64F);

class ImageConverter {
    private :

    ros::NodeHandle nh;
    image_transport::ImageTransport it;
    image_transport::Publisher pub;
    image_transport::Subscriber sub_pic;
    ros::Subscriber sub_pos;
    tf::TransformBroadcaster br;

    public :

    ImageConverter() : it(nh) {
        sub_pos = nh.subscribe("/camera/color/camera_info", 100, &ImageConverter::coord_matrix, this);
        sub_pic = it.subscribe("/camera/color/image_raw", 100, &ImageConverter::get_color_pic, this);
        pub = it.advertise("/camera/markers", 100);
    }

    void    get_color_pic(const sensor_msgs::ImageConstPtr& msg) {
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        cv::Mat image = cv_ptr->image;
        std::vector<int> markerIds;
        std::vector<std::vector<cv::Point2f>> markerCorners;
        cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_1000);
        cv::aruco::detectMarkers(image, dictionary, markerCorners, markerIds);

        cv::Mat outputImage = image.clone();
        if (markerIds.size() > 0) {
            cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
        }

        sensor_msgs::ImagePtr msg_pub = cv_bridge::CvImage(std_msgs::Header(), "bgr8",  outputImage).toImageMsg();
        pub.publish(msg_pub);
        
        std::vector<cv::Vec3d> rvecs, tvecs;
        cv::aruco::estimatePoseSingleMarkers(markerCorners, 0.3, CameraMatrix, DistCoeffs, rvecs, tvecs);
        for (size_t i = 0; i < markerCorners.size(); ++i)
        {
            const double angle = cv::norm(rvecs[i]);
            cv::Vec3d axis = rvecs[i] / angle;
            tf::Quaternion q;
            q.setRotation(tf::Vector3(axis[0], axis[1], axis[2]), angle);

            tf::Transform transform;
            transform.setOrigin(tf::Vector3(tvecs[i][0], tvecs[i][1], tvecs[i][2]));
            transform.setRotation(q);
            br.sendTransform(tf::StampedTransform(transform.inverse(), ros::Time::now(), "marker_frame", "camera_frame"));
        }
    }

    void    coord_matrix(const sensor_msgs::CameraInfoConstPtr& msg) {

        CameraMatrix.at<double>(0,0) = msg->K[0];
        CameraMatrix.at<double>(0,2) = msg->K[2];
        CameraMatrix.at<double>(1,1) = msg->K[4];
        CameraMatrix.at<double>(1,2) = msg->K[5];
        CameraMatrix.at<double>(2,2) = msg->K[8];

        DistCoeffs.at<double>(0,0) = msg->D[0];
        DistCoeffs.at<double>(0,1) = msg->D[1];
        DistCoeffs.at<double>(0,2) = msg->D[2];
        DistCoeffs.at<double>(0,3) = msg->D[3];
        DistCoeffs.at<double>(0,4) = msg->D[4];

    }     
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "grey_picture");
    ImageConverter correction;
    ros::spin();
}