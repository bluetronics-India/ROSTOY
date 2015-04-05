#include <ros.h>
#include <Servo.h> 
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/String.h>
#include <std_msgs/MultiArrayDimension.h>

ros::NodeHandle  nh; // ros node handle
std_msgs::Int16MultiArray out_state; // our current state
std_msgs::String stat; // our current status

ros::Publisher robot_state("state", &out_state); // publish our state
ros::Publisher robot_status("status", &stat); // publish a status message

// create our servo objects
Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 
int state[4];    // variable to store the servo position 


// user input scrubbing
int clip(int value,int top, int bottom)
{
  return min(max(value,bottom),top); 
}

void robot_cb(const std_msgs::Int16MultiArray& cmd_msg)
{
  // copy the input object to our state variable
  // and write it to the servos. 
  memcpy(&state,&cmd_msg.data[1],4*2);
  myservo1.write(state[0]);
  myservo2.write(state[1]);
  myservo3.write(state[2]);
  myservo4.write(state[3]);
  return;
}

// listen to the robot topic, when there is a message
// call the robot_cb function
ros::Subscriber<std_msgs::Int16MultiArray> robot("robot", &robot_cb);

void setup(){
   myservo1.attach(3);  // attaches the servo on pin 3 to the servo object    
   myservo2.attach(6);  // attaches the servo on pin 6 to the servo object  
   myservo3.attach(10);  // attaches the servo on pin 10 to the servo object
   myservo4.attach(13);  // attaches the servo on pin 13 to the servo object 
   // Setup our state variable
   for( int i=0; i < 4; i++ )
   {
      state[i] = 90;
   }
   // send the servos to a neutral state
   myservo1.write(state[0]);
   myservo1.write(state[1]);
   myservo1.write(state[2]);
   myservo1.write(state[3]);
   // Tell ros about our baud rate
   nh.getHardware()->setBaud(115200); //or what ever baud you want
   // initialize the node
   nh.initNode();
   // subscribe to the robot topic
   nh.subscribe(robot);
   // advertise that we publish two topics, state and status
   nh.advertise(robot_state);
   nh.advertise(robot_status);
}

// message string 
char stat_str[64];

void loop(){
 // update ros stuff
 nh.spinOnce();
 // copy over our data from ros. 
 memcpy(&out_state.data[1],&state,4*2);
 // construct our state message
 out_state.data_length = 5;
 out_state.layout.data_offset = 0;
 robot_state.publish( &out_state );
 sprintf(stat_str,"%i %i %i %i",state[0],state[1],state[2],state[3]);
 stat.data = stat_str;
 // publish our state message. 
 robot_status.publish( &stat );  
 delay(5);
}
