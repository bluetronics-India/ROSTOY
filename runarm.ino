#include <ros.h>
#include <Servo.h> 
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/String.h>
#include <std_msgs/MultiArrayDimension.h>
ros::NodeHandle  nh;
std_msgs::Int16MultiArray out_state; 
std_msgs::String stat; 

ros::Publisher robot_state("state", &out_state);
ros::Publisher robot_status("status", &stat);

Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 
int state[4];    // variable to store the servo position 


int clip(int value,int top, int bottom)
{
  return min(max(value,bottom),top); 
}

void robot_cb(const std_msgs::Int16MultiArray& cmd_msg)
{

  //for( int i=0; i < 4; i = i+1 )
  //{
  //  state[i] = clip(cmd_msg.data[i],180,0);
  //}
  memcpy(&state,&cmd_msg.data[1],4*2);
  myservo1.write(state[0]);
  myservo2.write(state[1]);
  myservo3.write(state[2]);
  myservo4.write(state[3]);
  return;
}

ros::Subscriber<std_msgs::Int16MultiArray> robot("robot", &robot_cb);

void setup(){
   myservo1.attach(3);  // attaches the servo on pin 9 to the servo object    
   myservo2.attach(6);  // attaches the servo on pin 9 to the servo object  
   myservo3.attach(10);  // attaches the servo on pin 9 to the servo object
   myservo4.attach(13);  // attaches the servo on pin 9 to the servo object 
   for( int i=0; i < 4; i++ )
   {
      state[i] = 90;
   }
   myservo1.write(state[0]);
   myservo1.write(state[1]);
   myservo1.write(state[2]);
   myservo1.write(state[3]);
   nh.getHardware()->setBaud(115200); //or what ever baud you want
   nh.initNode();
   nh.subscribe(robot);
   nh.advertise(robot_state);
   nh.advertise(robot_status);
}

char stat_str[64];
void loop(){
 nh.spinOnce();
 memcpy(&out_state.data[1],&state,4*2);
 out_state.data_length = 5;
 out_state.layout.data_offset = 0;
 robot_state.publish( &out_state );
 sprintf(stat_str,"%i %i %i %i",state[0],state[1],state[2],state[3]);
 stat.data = stat_str;
 robot_status.publish( &stat );
  
 delay(5);
}
