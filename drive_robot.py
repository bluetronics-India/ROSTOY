import rospy
from std_msgs.msg import Int32MultiArray
import time

def publisher():
    pub = rospy.Publisher('robot', Int32MultiArray, queue_size=10)
    rospy.init_node('publisher', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while True:
        msg = Int32MultiArray()
        data = [0,0,0,0]
        msg.data = data
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        print "program interrupted before completion"
