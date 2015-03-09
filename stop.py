import rospy
from std_msgs.msg import Int16MultiArray
import time

def publisher():
    pub = rospy.Publisher('robot', Int16MultiArray, queue_size=10)
    rospy.init_node('publisher', anonymous=True)
    msg = Int16MultiArray()
    data = [0,0,0,0]
    msg.data = data
    pub.publish(msg)

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        print "program interrupted before completion"
