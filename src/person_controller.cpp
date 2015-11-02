#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <gazebo_msgs/ModelState.h>



int main(int argc, char** argv)
{
    ros::init(argc, argv, "person_node");
    ros::NodeHandle node;
    ros::Publisher person_pub = node.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 1000);
    
    ros::Rate loop_rate(10);
    
    
    gazebo_msgs::ModelState person_lab1, person_lab2, person_lab3, walker;
    
    person_lab1.model_name = "person_lab1";
    person_lab1.pose.position.x = 9;
    person_lab1.pose.position.y = -2.5;
    person_lab1.pose.position.z = 0;
    person_lab1.pose.orientation.x = 0;
    person_lab1.pose.orientation.y = 0;
    person_lab1.pose.orientation.z = 0;
    person_lab1.pose.orientation.w = 1;
    
    person_lab2.model_name = "person_lab2";
    person_lab2.pose.position.x = -17;
    person_lab2.pose.position.y = 2.8;
    person_lab2.pose.position.z = 0;
    person_lab2.pose.orientation.x = 0;
    person_lab2.pose.orientation.y = 0;
    person_lab2.pose.orientation.z = 0.707;
    person_lab2.pose.orientation.w = 0.707;
    
    person_lab3.model_name = "person_lab3";
    person_lab3.pose.position.x = -18;
    person_lab3.pose.position.y = 5.3;
    person_lab3.pose.position.z = 0;
    person_lab3.pose.orientation.x = 0;
    person_lab3.pose.orientation.y = 0;
    person_lab3.pose.orientation.z = 0.707;
    person_lab3.pose.orientation.w = 0.707;
    
    walker.model_name = "walker";
    walker.pose.position.x = -4.5;
    walker.pose.position.y = 11;
    walker.pose.position.z = 0;
    walker.pose.orientation.x = 0;
    walker.pose.orientation.y = 0;
    walker.pose.orientation.z = -0.707;
    walker.pose.orientation.w = 0.707;

    
    int lab1 = 0;
    int lab2 = 0;
    int lab3 = 0;
    int walk = 0;
    double dx = 0.1;
    while(ros::ok())
    {
        // move person lab 1
        if(lab1 < 47)
        {
            person_lab1.pose.position.y -= dx;
            person_lab1.pose.orientation.z = 0;
            person_lab1.pose.orientation.w = 1;
        }
        if(lab1 >= 47 && lab1 < 94)
        {
            person_lab1.pose.position.x += dx;
            person_lab1.pose.orientation.z = 0.707;
            person_lab1.pose.orientation.w = 0.707;
        }
        if(lab1 >= 94 && lab1 < 141)
        {
            person_lab1.pose.position.y += dx;
            person_lab1.pose.orientation.z = 1;
            person_lab1.pose.orientation.w = 0;
        }
        if(lab1 >= 141 && lab1 < 188)
        {
            person_lab1.pose.position.x -= dx;
            person_lab1.pose.orientation.z = -0.707;
            person_lab1.pose.orientation.w = 0.707;
        }
        if(lab1 == 188)
        {
            person_lab1.pose.position.x = 9;
            person_lab1.pose.position.y = -2.5;
            person_lab1.pose.position.z = 0;
            person_lab1.pose.orientation.x = 0;
            person_lab1.pose.orientation.y = 0;
            person_lab1.pose.orientation.z = 0;
            person_lab1.pose.orientation.w = 1;
            lab1 = 0;
        }
        lab1++;
        
        person_pub.publish(person_lab1);
        
        
        // move person lab 2
        if(lab2 < 60)
        {
            person_lab2.pose.position.x += dx;
            person_lab2.pose.orientation.z = 0.707;
            person_lab2.pose.orientation.w = 0.707;
        }
        if(lab2 >= 60 && lab2 < 158)
        {
            person_lab2.pose.position.y -= dx;
            person_lab2.pose.orientation.z = 0;
            person_lab2.pose.orientation.w = 1;
        }
        if(lab2 >= 158 && lab2 < 218)
        {
            person_lab2.pose.position.x -= dx;
            person_lab2.pose.orientation.z = -0.707;
            person_lab2.pose.orientation.w = 0.707;
        }
        if(lab2 >= 218 && lab2 < 278)
        {
            person_lab2.pose.position.x += dx;
            person_lab2.pose.orientation.z = 0.707;
            person_lab2.pose.orientation.w = 0.707;
        }
        if(lab2 >= 278 && lab2 < 376)
        {
            person_lab2.pose.position.y += dx;
            person_lab2.pose.orientation.z = 1;
            person_lab2.pose.orientation.w = 0;
        }
        if(lab2 >= 376 && lab2 < 436)
        {
            person_lab2.pose.position.x -= dx;
            person_lab2.pose.orientation.z = -0.707;
            person_lab2.pose.orientation.w = 0.707;
        }
        if(lab2 == 436)
        {
            person_lab2.pose.position.x = -17;
            person_lab2.pose.position.y = 2.8;
            person_lab2.pose.position.z = 0;
            person_lab2.pose.orientation.x = 0;
            person_lab2.pose.orientation.y = 0;
            person_lab2.pose.orientation.z = 0.707;
            person_lab2.pose.orientation.w = 0.707;
            lab2 = 0;
        }
        lab2++;
        
        person_pub.publish(person_lab2);

        
        // move person lab 3
        if(lab3 < 80)
        {
            person_lab3.pose.position.x += dx;
            person_lab3.pose.orientation.z = 0.707;
            person_lab3.pose.orientation.w = 0.707;
        }
        if(lab3 >= 80 && lab3 < 152)
        {
            person_lab3.pose.position.y += dx;
            person_lab3.pose.orientation.z = 1;
            person_lab3.pose.orientation.w = 0;
        }
        if(lab3 >= 152 && lab3 < 232)
        {
            person_lab3.pose.position.x -= dx;
            person_lab3.pose.orientation.z = -0.707;
            person_lab3.pose.orientation.w = 0.707;
        }
        if(lab3 >= 232 && lab3 < 312)
        {
            person_lab3.pose.position.x += dx;
            person_lab3.pose.orientation.z = 0.707;
            person_lab3.pose.orientation.w = 0.707;
        }
        if(lab3 >= 312 && lab3 < 384)
        {
            person_lab3.pose.position.y -= dx;
            person_lab3.pose.orientation.z = 0;
            person_lab3.pose.orientation.w = 1;
        }
        if(lab3 >= 384 && lab3 < 464)
        {
            person_lab3.pose.position.x -= dx;
            person_lab3.pose.orientation.z = -0.707;
            person_lab3.pose.orientation.w = 0.707;
        }
        if(lab3 == 464)
        {
            person_lab3.pose.position.x = -18;
            person_lab3.pose.position.y = 5.3;
            person_lab3.pose.position.z = 0;
            person_lab3.pose.orientation.x = 0;
            person_lab3.pose.orientation.y = 0;
            person_lab3.pose.orientation.z = 0.707;
            person_lab3.pose.orientation.w = 0.707;
            lab3 = 0;
        }
        lab3++;
        
        person_pub.publish(person_lab3);
        
        
        // move person walker
        if(walk < 38)
        {
            walker.pose.position.x -= dx;
            walker.pose.orientation.z = -0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 38 && walk < 173)
        {
            walker.pose.position.y -= dx;
            walker.pose.orientation.z = 0;
            walker.pose.orientation.w = 1;
        }
        if(walk >= 173 && walk < 221)
        {
            walker.pose.position.x += dx;
            walker.pose.orientation.z = 0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 221 && walk < 296)
        {
            walker.pose.position.y -= dx;
            walker.pose.orientation.z = 0;
            walker.pose.orientation.w = 1;
        }
        if(walk >= 296 && walk < 371)
        {
            walker.pose.position.y += dx;
            walker.pose.orientation.z = 1;
            walker.pose.orientation.w = 0;
        }
        if(walk >= 371 && walk < 453)
        {
            walker.pose.position.x += dx;
            walker.pose.orientation.z = 0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 453 && walk < 475)
        {
            walker.pose.position.y += dx;
            walker.pose.orientation.z = 1;
            walker.pose.orientation.w = 0;
        }
        if(walk >= 475 && walk < 578)
        {
            walker.pose.position.x += dx;
            walker.pose.orientation.z = 0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 578 && walk < 703)
        {
            walker.pose.position.x -= dx;
            walker.pose.orientation.z = -0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 703 && walk < 725)
        {
            walker.pose.position.y -= dx;
            walker.pose.orientation.z = 0;
            walker.pose.orientation.w = 1;
        }
        if(walk >= 725 && walk < 833)
        {
            walker.pose.position.x -= dx;
            walker.pose.orientation.z = -0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk >= 833 && walk < 968)
        {
            walker.pose.position.y += dx;
            walker.pose.orientation.z = 1;
            walker.pose.orientation.w = 0;
        }
        if(walk >= 968 && walk < 1006)
        {
            walker.pose.position.x += dx;
            walker.pose.orientation.z = 0.707;
            walker.pose.orientation.w = 0.707;
        }
        if(walk == 1006)
        {
            walker.pose.position.x = -4.5;
            walker.pose.position.y = 11;
            walker.pose.position.z = 0;
            walker.pose.orientation.x = 0;
            walker.pose.orientation.y = 0;
            walker.pose.orientation.z = -0.707;
            walker.pose.orientation.w = 0.707;
            walk = 0;
        }
        walk++;
        
        person_pub.publish(walker);
               
        
        ros::spinOnce();
        loop_rate.sleep();
    }
}