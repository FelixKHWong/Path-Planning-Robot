#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

//define pickup coordinates
float pick_up_x = 4;
float pick_up_y = -3;
//define dropoff coordinates
float drop_off_x = -2;
float drop_off_y = -4;

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;

  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    marker.header.stamp = ros::Time::now();

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pick_up_x;
    marker.pose.position.y = pick_up_y;
    marker.pose.position.z = 0.3;
   // marker.pose.orientation.x = 0.0;
   // marker.pose.orientation.y = 0.0;
    //marker.pose.orientation.z = 0.0;
   // marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

   marker.lifetime = ros::Duration();
   while (marker_pub.getNumSubscribers() < 1)
       {
       if (!ros::ok())
         {
           return 0;
         }
         ROS_WARN_ONCE("Please create a subscriber to the marker");
         sleep(1);
       }
    marker_pub.publish(marker);

    ROS_INFO_STREAM("created marker. Waiting");

    ros::Duration(5).sleep();

    marker.header.stamp = ros::Time::now();
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);

    ROS_INFO_STREAM("deleted marker. Waiting");
    ros::Duration(5).sleep();

    marker.header.stamp = ros::Time::now();
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = drop_off_x;
    marker.pose.position.y = drop_off_y;
    marker.pose.position.z = 0.3;
    marker_pub.publish(marker);
    ROS_INFO_STREAM("Created Marker in Final Destination");
}
