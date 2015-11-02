#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <gazebo_msgs/ModelState.h>



int main(int argc, char** argv)
{
    ros::init(argc, argv, "worker_node");
    ros::NodeHandle node;
    ros::Publisher worker_pub = node.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1000);
    
    ros::Rate loop_rate(5);
    
    
    gazebo_msgs::ModelState worker1, worker2, worker3;
    
    worker1.model_name = "worker1";
    worker1.pose.position.x = -5;
    worker1.pose.position.y = 12;
    worker1.pose.position.z = 0;
    worker1.pose.orientation.x = 0;
    worker1.pose.orientation.y = 0;
    worker1.pose.orientation.z = 0.707;
    worker1.pose.orientation.w = -0.707;

    worker2.model_name = "worker2";
    worker2.pose.position.x = -3;
    worker2.pose.position.y = 7;
    worker2.pose.position.z = 0;
    worker2.pose.orientation.x = 0;
    worker2.pose.orientation.y = 0;
    worker2.pose.orientation.z = 0.707;
    worker2.pose.orientation.w = 0.707;
    
    worker3.model_name = "worker3";
    worker3.pose.position.x = -6;
    worker3.pose.position.y = 1;
    worker3.pose.position.z = 0;
    worker3.pose.orientation.x = 0;
    worker3.pose.orientation.y = 0;
    worker3.pose.orientation.z = 0;
    worker3.pose.orientation.w = 1;
    
    int work1 = 0;
    int work2 = 0;
    int work3 = 0;
    double dx = 0.1;
    while(ros::ok())
    {
        // move worker 1
        if(work1 < 60)
        {
            worker1.pose.position.x -= dx;
            worker1.pose.orientation.z = 0.707;
            worker1.pose.orientation.w = -0.707;
        }
        if(work1>=60 && work1 < 120)
        {
            worker1.pose.position.x += dx;
            worker1.pose.orientation.z = 0.707;
            worker1.pose.orientation.w = 0.707;
        }
        if(work1 == 120)
        {
            worker1.model_name = "worker1";
            worker1.pose.position.x = -5;
            worker1.pose.position.y = 12;
            worker1.pose.position.z = 0;
            worker1.pose.orientation.x = 0;
            worker1.pose.orientation.y = 0;
            worker1.pose.orientation.z = 0.707;
            worker1.pose.orientation.w = -0.707;
            work1 = 0;
        }
        work1++;
        
        // move worker 2
        if(work2 < 40)
        {
            worker2.pose.position.x += dx;
            worker2.pose.orientation.z = 0.707;
            worker2.pose.orientation.w = 0.707;
        }
        if(work2 >= 40 && work2 < 80)
        {
            worker2.pose.position.x -= dx;
            worker2.pose.orientation.z = 0.707;
            worker2.pose.orientation.w = -0.707;
        }
        if(work2 == 80)
        {
            worker2.model_name = "worker2";
            worker2.pose.position.x = -3;
            worker2.pose.position.y = 7;
            worker2.pose.position.z = 0;
            worker2.pose.orientation.x = 0;
            worker2.pose.orientation.y = 0;
            worker2.pose.orientation.z = 0.707;
            worker2.pose.orientation.w = 0.707;
            work2 = 0;
        }
        work2++;
        
        // move worker 3
        if(work3 < 100)
        {
            worker3.pose.position.y -= dx;
            worker3.pose.orientation.z = 0;
            worker3.pose.orientation.w = 1;
        }
        if(work3 >= 100 && work3 < 200)
        {
            worker3.pose.position.y += dx;
            worker3.pose.orientation.z = 1;
            worker3.pose.orientation.w = 0;
        }
        if(work3 == 200)
        {
            worker3.model_name = "worker3";
            worker3.pose.position.x = -6;
            worker3.pose.position.y = 1;
            worker3.pose.position.z = 0;
            worker3.pose.orientation.x = 0;
            worker3.pose.orientation.y = 0;
            worker3.pose.orientation.z = 0;
            worker3.pose.orientation.w = 1;
            work3 = 0;
        }
        work3++;
      
        worker_pub.publish(worker1);
        worker_pub.publish(worker2);
        worker_pub.publish(worker3);

        ros::spinOnce();
        loop_rate.sleep();
    }
}