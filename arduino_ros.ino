#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/String.h>
#include <AFMotor.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);


AF_DCMotor motor1(1);  // Instantiate all the motors
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int get_direction( const int input )
{
    if( input > 0 )
     { 
       return FORWARD;
     }
     else if( input < 0 )
     {
        return BACKWARD;
     }
     else
     {
        return RELEASE;
     } 
}

int get_speed( const int input )
{
  return abs(input);
}

void robot_cb(const std_msgs::Int16MultiArray& cmd_msg)
{
  char msg[64];
  sprintf(msg,"got: %i %i %i %i", cmd_msg.data[0],cmd_msg.data[1],cmd_msg.data[2],cmd_msg.data[3]);
  str_msg.data = msg;
  chatter.publish( &str_msg );

  //motor1.setSpeed(get_speed(cmd_msg.data[0]));
//  motor1.run(get_direction(cmd_msg.data[0]));  
  //motor2.setSpeed(get_speed(cmd_msg.data[1]));
//  motor2.run(get_direction(cmd_msg.data[1]));  
  //motor3.setSpeed(get_speed(cmd_msg.data[2]));
//  motor3.run(get_direction(cmd_msg.data[2]));  
  //motor4.setSpeed(get_speed(cmd_msg.data[3]));
//  motor4.run(get_direction(cmd_msg.data[3]));    
}


ros::Subscriber<std_msgs::Int16MultiArray> sub("robot", &robot_cb);

void setup(){
  motor1.setSpeed(1000);
  motor2.setSpeed(1000);
  motor3.setSpeed(1000);
  motor4.setSpeed(1000);
  
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
