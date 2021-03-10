#include <ros/ros.h>

#include <cv_bridge/cv_bridge.h>

class Example {
  ros::NodeHandle n;
  ros::Subscriber imageSub;
public:
  Example() {
    imageSub = n.subscribe("/drone_camera_264_main/image_raw", 1, &Example::imageCallback, this);
  }

  void imageCallback(const sensor_msgs::ImageConstPtr &msg) {
    ROS_INFO("%d x %d size: %zu", msg->width, msg->height, msg->data.size());
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    // cv_ptr->image
  }
};


int main(int argc, char **argv) {
  ros::init(argc, argv, "example");

  ros::AsyncSpinner spinner(0);
  Example e;
  ros::waitForShutdown();

  return 0;
}

