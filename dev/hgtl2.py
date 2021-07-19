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

#break_on="{throttle: 0.0, steer: 0.0, break: 1.0, hand_brake: 1.0, reverse: 0, gear: 1, manual_gear_shift: 0}"
#['header', 'throttle', 'steer', 'brake', 'hand_brake', 'reverse', 'gear', 'manual_gear_shift']
vehicle_ctrl_info = CarlaEgoVehicleControl()
vehicle_cmd = rospy.Publisher("/carla/ego_vehicle/vehicle_control_cmd", 
    CarlaEgoVehicleControl, queue_size=1)

SPEED_OFFSET = 3.713
Thtotte = 0.9
elseThtotte=0.2

def AccCmd( sveldata, inveldata  ) :

    if(  1 > (sveldata - inveldata) ):
        vehicle_ctrl_info.throttle = Thtotte
        vehicle_ctrl_info.brake = 0.00


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
        vehicle_cmd.publish(vehicle_ctrl_info)
        Subvelocity.gdata = vel_data
        

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
    # Start sending first message
    #can0.send(can.Message(arbitration_id=0, is_extended_id=False))

    #print('Bouncing 10 messages...')
    #for _ in range(10):
        # Wait for next message from AsyncBufferedReader
    msg = await reader.get_message()
        # Delay response
    #await asyncio.sleep(0.5)
        #msg.arbitration_id += 1
        #can0.send(msg)
    # Wait for last message to arrive
    #await reader.get_message()
    #print(msg.arbitration_id)
    gCanDataResult = msg.data
    gPotBreak = gCanDataResult[3]
    gPotBreak |= (gCanDataResult[4]<<8)
    gPotAccel = gCanDataResult[5]
    gPotAccel |= (gCanDataResult[6]<<8)
    print('pot',gPotBreak)
    # Clean-up
    notifier.stop()
    #can0.shutdown()
    return gCanDataResult


def main():
    while not rospy.is_shutdown():
        #rospy.init_node("sub_hglee_velocity", anonymous=False)
        rospy.init_node("pub_hglee_velocity", anonymous=False)
        SubVeldata = Subvelocity()

        try:
            rospy.Subscriber("/carla/ego_vehicle/vehicle_status", 
            CarlaEgoVehicleStatus,SubVeldata.RosSubCallbak_DataCarla )
            rospy.sleep(0.05)
            #a = SubVeldata.GetRosdata()
            #b = asyncio.get_event_loop().run_until_complete(can_rc())
            #asyncio.get_event_loop().close()
            #print('main vel', a*SPEED_OFFSET)
        except Exception as e:
            print( 'exception' , e )


        #rospy.Rate(5)
        #a = SubVeldata.GetRosdata()

        df = pd.read_table("kang.txt", sep=":", names=['Name', 'Data'])
        last_velocity = df[df["Name"] == 'velocity'].iloc[-1, 1]
        print('last_velocity', last_velocity)
        a = float(last_velocity)

        b = asyncio.get_event_loop().run_until_complete(can_rc())
        '''
        async for msg in bus:
            print(">","{}: {}".format(hex(msg.arbitration_id), msg.data))
            gCanDataResult=b
        '''
        print('main can', b)
        #print('*******************************')
        #print((a*SPEED_OFFSET))
        print('main vel1', a*SPEED_OFFSET)
        Vehicle_ctrl(a,b)
        
        
        #asyncio.get_event_loop().close

        #while not rospy.is_shutdown():
        #if(SubVeldata > 8):
            #vehicle_cmd.publish(String_cmd)
        #    print('ok')
        #rospy.spin()
'''
# Get the default event loop
loop = asyncio.get_event_loop()
# Run until main coroutine finishes
loop.run_until_complete(can_rc())
loop.close()
'''
if __name__ == "__main__":
    while True:
        try :
            main()
        except Exception as e:
            print( 'exception' , e )