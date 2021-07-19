 #!/usr/bin/env python

import json

 #ros
import rospy
from geometry_msgs.msg import Twist, Transform, Pose, PoseWithCovariance
from nav_msgs.msg import Odometry

#carla rosbridge
from carla_ros_bridge.vehicle import Vehicle
from carla_ros_bridge.ego_vehicle import EgoVehicle
import carla_common.transforms as transforms
from carla_msgs.msg import CarlaEgoVehicleInfo, CarlaEgoVehicleInfoWheel,\
    CarlaEgoVehicleControl, CarlaEgoVehicleStatus

from rospy_message_converter import json_message_converter

import can

#break_on="{throttle: 0.0, steer: 0.0, break: 1.0, hand_brake: 1.0, reverse: 0, gear: 1, manual_gear_shift: 0}"
#['header', 'throttle', 'steer', 'brake', 'hand_brake', 'reverse', 'gear', 'manual_gear_shift']
vehicle_data = CarlaEgoVehicleControl()
SPEED_OFFSET = 3.713
class Subvelocity:
    #global
    gdata = ""
    def __init__(self):
        self.json_str =""

    def GetRosdata(self):
        #return self.json_str
        return Subvelocity.gdata

    def RosSubCallbak_DataCarla(self,data):      
        #self.json_str = json_message_converter.convert_ros_message_to_json(data)
        rosdata = json_message_converter.convert_ros_message_to_json(data)
        js = json.loads(rosdata)
        #print('------------------------------')
        #print(js)/carla/ego_vehicle/vehicle_control_cmd carla_msgs/CarlaEgoVehicleControl
        vehicle_cmd = rospy.Publisher("/carla/ego_vehicle/vehicle_control_cmd", 
        CarlaEgoVehicleControl, queue_size=1)
        vel_data=js['velocity']
        if( (vel_data*SPEED_OFFSET) >= 0.0 ) and  ( (vel_data*SPEED_OFFSET) <= 10.0 ) :
            vehicle_data.throttle= 1.0
            vehicle_data.brake = 0.0
            #vehicle_data.steer = 1.0
            #vehicle_data.hand_brake=1
            #print('1')
            vehicle_cmd.publish(vehicle_data)
        elif( (vel_data*SPEED_OFFSET) > 10.0 ):
            vehicle_data.throttle = 0.0
            vehicle_data.brake = 1.0
            #print('2')
            vehicle_cmd.publish(vehicle_data)
        
            #print('ok')
        Subvelocity.gdata = vel_data



def main():
    while not rospy.is_shutdown():
        #rospy.init_node("sub_hglee_velocity", anonymous=False)
        rospy.init_node("pub_hglee_velocity", anonymous=False)
        SubVeldata = Subvelocity()

        try:
            rospy.Subscriber("/carla/ego_vehicle/vehicle_status", 
            CarlaEgoVehicleStatus,SubVeldata.RosSubCallbak_DataCarla )
            rospy.sleep(0.05)
        except Exception as e:
            print( 'exception' , e )

        a = SubVeldata.GetRosdata()
        print('*******************************')
        print((a*SPEED_OFFSET))
        #while not rospy.is_shutdown():
        #if(SubVeldata > 8):
            #vehicle_cmd.publish(String_cmd)
        #    print('ok')
        #rospy.spin()



if __name__ == "__main__":
    while True:
        main()
        