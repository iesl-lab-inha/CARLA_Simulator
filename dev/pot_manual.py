 #!/usr/bin/env python
import pandas as pd

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

from ackermann_msgs.msg import AckermannDrive 
from carla_ackermann_control.msg import EgoVehicleControlInfo
from rospy_message_converter import json_message_converter

import can
import asyncio
'''
df = pd.read_table("kang.txt", sep=":", names=['Name', 'Data'])
last_velocity = df[df["Name"] == 'velocity'].iloc[-1, 1]
'''

'''
bus = can.Bus(interface='socketcan',
              channel='can0',
              receive_own_messages=True)
'''

#GLOBAL_DATA
gCanDataResult = 0
gPotBreak = 0;
gPotAccel = 0;
gPotEmotion =0;
Flag_ack = 0;

#break_on="{throttle: 0.0, steer: 0.0, break: 1.0, hand_brake: 1.0, reverse: 0, gear: 1, manual_gear_shift: 0}"
#['header', 'throttle', 'steer', 'brake', 'hand_brake', 'reverse', 'gear', 'manual_gear_shift']
'''----------------------------------------------------------------'''
'''--------------------ROS_init------------------------------------'''
vehicle_ctrl_info = CarlaEgoVehicleControl()
ack_vehicle_ctrl_info=AckermannDrive()
vehicle_cmd = rospy.Publisher("/carla/ego_vehicle/vehicle_control_cmd", 
    CarlaEgoVehicleControl, queue_size=1)
ack_vehicle_cmd = rospy.Publisher("/carla/ego_vehicle/ackermann_cmd", 
    AckermannDrive, queue_size=1)


'''------------------------------------------------------------'''
'''-----------ROS_pub_Info-------------------------------------'''
SPEED_OFFSET = 3.713
Thtotte = 0.9
elseThtotte=0.2
vehicle_ctrl_info.brake = 0.0
vehicle_ctrl_info.hand_brake=False
vehicle_ctrl_info.gear = 4
#ack_vehicle_ctrl_info.speed= 1.3466
#ack_vehicle_ctrl_info.acceleration=0.6208;


'''------------------------------------------------------------------'''
'''---------------------------Vehicle_CTRL---------------------------'''
def Ackermann_Info_Func(speed, acceleration):
    ack_vehicle_ctrl_info.speed = speed / SPEED_OFFSET;
    ack_vehicle_ctrl_info.acceleration = acceleration;

def Ack_Vehilce_ctrl(veldata, biodata) :
    if( biodata[0] == 1):
        if( ((veldata*SPEED_OFFSET)-20) > 5 ):
            ack_vehicle_ctrl_info.speed = 3 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration = 0;
            print('11111')
        else:
            ack_vehicle_ctrl_info.speed = 20 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration = abs((veldata) - (20/SPEED_OFFSET)) #0.6208; #2km
    elif( biodata[0] == 2):
            ack_vehicle_ctrl_info.speed = 0 
            ack_vehicle_ctrl_info.acceleration = 0;
    elif( biodata[0] == 3):
        if( biodata[1] == 1) :
            ack_vehicle_ctrl_info.speed = 0 
            ack_vehicle_ctrl_info.acceleration = 0; #2km
        elif( (veldata*SPEED_OFFSET) > 30) :   
            ack_vehicle_ctrl_info.speed =  0;
            ack_vehicle_ctrl_info.acceleration =abs((veldata) - (10/SPEED_OFFSET))
        else:
            ack_vehicle_ctrl_info.speed = 10 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration =  abs((veldata) - (10/SPEED_OFFSET)); #2km
    elif( biodata[0] == 4):
        if( ((veldata*SPEED_OFFSET)-40) > 5 ):
            ack_vehicle_ctrl_info.speed =  5 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration = 2
        else:
            ack_vehicle_ctrl_info.speed = 40 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration = 0.6208 #2km
    else:
        ack_vehicle_ctrl_info.speed = 0 / SPEED_OFFSET
        ack_vehicle_ctrl_info.acceleration = 3 #2km


def Vehicle_ctrl(veldata,candata) :
    print('vel can',candata[0])    
    if candata[0] == 1 :
        if( (veldata*SPEED_OFFSET) >= 18.0 ) and  ( (veldata*SPEED_OFFSET) <= 20.0 ) :
            vehicle_ctrl_info.throttle= 0.9
            vehicle_ctrl_info.brake = 0.0
            #vehicle_ctrl_info.steer = 1.0
            #vehicle_ctrl_info.hand_brake=1
            print( 'debug - if vel1' )
        elif( (veldata*SPEED_OFFSET) >= 0.0 ) and  ( (veldata*SPEED_OFFSET) <= 17.0 ) :
            vehicle_ctrl_info.throttle= 1.0
            vehicle_ctrl_info.brake = 0.0
        elif( (veldata*SPEED_OFFSET) > 10.0 ):
            vehicle_ctrl_info.throttle = 0.6
            vehicle_ctrl_info.brake = 0.02
            print( 'debug - else vel1' )
    elif candata[0] == 2:
        '''
        if( (veldata*SPEED_OFFSET) >= 0.0 ) and  ( (veldata*SPEED_OFFSET) <= 20.0 ) :
            vehicle_ctrl_info.throttle= Thtotte
            vehicle_ctrl_info.brake = 0.0
            #vehicle_ctrl_info.steer = 1.0
            #vehicle_ctrl_info.hand_brake=1
            print( 'debug - if vel2' )
        elif( (veldata*SPEED_OFFSET) > 20.0 ):
            vehicle_ctrl_info.throttle = elseThtotte
            vehicle_ctrl_info.brake = 0.2
            print( 'debug - else vel2' )
        '''
        vehicle_ctrl_info.throttle= 0.0
        vehicle_ctrl_info.brake = 0.0
    elif candata[0] == 3:
        if( candata[1] == 1) :
            vehicle_ctrl_info.throttle = 0.0
            vehicle_ctrl_info.brake = 0.2
        elif( (veldata*SPEED_OFFSET) >= 0.0 ) and  ( (veldata*SPEED_OFFSET) <= 20.0 ) :
            vehicle_ctrl_info.throttle= Thtotte
            vehicle_ctrl_info.brake = 0.0
            #vehicle_ctrl_info.steer = 1.0
            #vehicle_ctrl_info.hand_brake=1
            print( 'debug - if vel3' )
        elif( (veldata*SPEED_OFFSET) > 20.0 ):
            vehicle_ctrl_info.throttle = elseThtotte
            vehicle_ctrl_info.brake = 0.2
            print( 'debug - else vel3' )
        
    elif candata[0] == 4:
        if( (veldata*SPEED_OFFSET) >= 38.0 ) and  ( (veldata*SPEED_OFFSET) <= 40.0 ) :
            vehicle_ctrl_info.throttle=0.9
            vehicle_ctrl_info.brake = 0.0
            #vehicle_ctrl_info.steer = 1.0
            #vehicle_ctrl_info.hand_brake=1
            print( 'debug - if vel4' )
        elif( (veldata*SPEED_OFFSET) >= 0.0 ) and  ( (veldata*SPEED_OFFSET) <= 37.0 ):
            vehicle_ctrl_info.throttle=1.0
            vehicle_ctrl_info.brake = 0.0
        elif( (veldata*SPEED_OFFSET) >= 41.0 ):
            vehicle_ctrl_info.throttle = 0.6
            vehicle_ctrl_info.brake = 0.02
            print( 'debug - else vel4' )
    else :
        vehicle_ctrl_info.throttle= 0.0
        vehicle_ctrl_info.brake = 1.0
        print( 'debug - why tlqkf' )


'''------------------------------------------------------------------'''
'''-------------------------ROS sub CallBack-------------------------'''
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

        vel_data=js['velocity']
        Subvelocity.gdata = vel_data


'''---------------------------------------------------------'''      
'''---------------------------CAN---------------------------'''
def print_message(msg):
    """Regular callback function. Can also be a coroutine."""
    print(msg)

async def can_rc():
    can0 = can.Bus(interface='socketcan', channel='can0', receive_own_messages=True)
    reader = can.AsyncBufferedReader()
    logger = can.Logger('logfile.asc')

    listeners = [
        #print_message,  # Callback function
        reader,         # AsyncBufferedReader() listener
        logger          # Regular Listener object
    ]
    # Create Notifier with an explicit loop to use for scheduling of callbacks
    loop = asyncio.get_event_loop()
    notifier = can.Notifier(can0, listeners, loop=loop)
    msg = await reader.get_message()

    gCanDataResult = msg.data
    if(gCanDataResult[0] == 0):
        gPotAccel = gCanDataResult[3] / 100
        vehicle_ctrl_info.throttle = gPotAccel
        Flag_ack = 0
    else :
        Flag_ack = 1
    gPotEmotion = gCanDataResult[4]
    print ('| 엑셀:',  gCanDataResult[3] / 100, '| emotion:',gCanDataResult[0], '| user_emotion:', gPotEmotion)
    # Clean-up
    notifier.stop()
    #can0.shutdown()
    return gCanDataResult ,Flag_ack


'''---------------------------MAIN---------------------------'''
def main():
    while not rospy.is_shutdown():
        #rospy.init_node("sub_hglee_velocity", anonymous=False)
        rospy.init_node("pub_hglee_velocity", anonymous=False)
        SubVeldata = Subvelocity()

        try:
            rospy.Subscriber("/carla/ego_vehicle/vehicle_status", 
            CarlaEgoVehicleStatus,SubVeldata.RosSubCallbak_DataCarla )

        except Exception as e:
            print( 'exception' , e )

        df = pd.read_table("kang.txt", sep=":", names=['Name', 'Data'])
        last_velocity = df[df["Name"] == 'velocity'].iloc[-1, 1]
        #print('last_velocity', last_velocity)
        current_velocity = float(last_velocity)
        can_data, flag = asyncio.get_event_loop().run_until_complete(can_rc())

        if( flag == 0 ) :
            vehicle_cmd.publish(vehicle_ctrl_info)
            print('akc1')
        else :
            Ack_Vehilce_ctrl(current_velocity, can_data)
            ack_vehicle_cmd.publish(ack_vehicle_ctrl_info)
            print('ack2')

        print('속도: ', current_velocity*SPEED_OFFSET)
        #Vehicle_ctrl(current_velocity ,can_data)
        
        
if __name__ == "__main__":
    try :
        main()
    except Exception as e:
        print( 'exception' , e )