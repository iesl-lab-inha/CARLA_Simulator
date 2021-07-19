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

import carla

from global_route_planner import  GlobalRoutePlanner
from global_route_planner_dao import GlobalRoutePlannerDAO 

import time
import math
import numpy as np
import controller

from multiprocessing import Process
from os import system
import sys
from agents.tools.misc import get_speed

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
lock = 0
z=1

vehicle_num = 271

gSpeed=30
#wps=[]

client = carla.Client("localhost", 2000)
client.set_timeout(10)
#world = client.load_world('Town04')
world = client.get_world()
spawn_points = world.get_map().get_spawn_points()

vehicles = world.get_actors().find(vehicle_num)
#spawnPoint = carla.Transform(carla.Location(x=-400.0, y=30.0, z=0.275307 ),carla.Rotation(pitch=0.0, yaw=0.0, roll=0.000000))
spawnPoint=carla.Transform(carla.Location(spawn_points[120].location),carla.Rotation(pitch=0.0, yaw=-180.0, roll=0.000000))
vehicles = carla.Actor.set_transform(vehicles,spawnPoint)
vehicles = world.get_actors().find(vehicle_num)

#vehicles = world.get_actors().filter('vehicle.toyota.prius')
#cmd="throttle=0.00000, steer=0.500000, brake=0.000000, hand_brake=False, reverse=False, manual_gear_shift=False, gear=0"
#vehicles.apply_control(cmd)
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
SPEED_OFFSET = 3.6
Thtotte = 0.9
elseThtotte=0.2
vehicle_ctrl_info.brake = 0.0
vehicle_ctrl_info.hand_brake=False
vehicle_ctrl_info.gear = 4
can_data = 0
flag=0
#ack_vehicle_ctrl_info.speed= 1.3466
#ack_vehicle_ctrl_info.acceleration=0.6208;

#distance_v=0
#control=0
ii=0
#j = 0 
#vehicle_loc = 0
#target = 0
'''------------------------------------------------------------'''
'''-----------CARLA_python-------------------------------------'''

def find_waypoind(w1,w2) :
    wps=[]
    amap = world.get_map() 
    sampling_resolution = 2
    dao = GlobalRoutePlannerDAO(amap, sampling_resolution)
    grp = GlobalRoutePlanner(dao)
    grp.setup()
    spawn_points = world.get_map().get_spawn_points()
    #a = carla.Location(spawn_points[a].location)#351 120
    a = w1.get_location()
    b = carla.Location(spawn_points[w2].location)#367 123
    w_route = grp.trace_route(a, b) 

    world.debug.draw_point(a,color=carla.Color(r=255, g=0, b=0),size=0.4 ,life_time=12.0)
    world.debug.draw_point(b,color=carla.Color(r=255, g=0, b=0),size=0.4 ,life_time=12.0)


    for i in range(len(w_route)):
        wps.append(w_route[i][0])
        world.debug.draw_point(w_route[i][0].transform.location,color=carla.Color(r=255, g=255, b=0),size=0.2 ,life_time=12.0)
    
    print('find_waypoind')
    return wps
    #vehicle=spawn_vehicle()
    #spawnPoint=carla.Transform(carla.Location(x=-400.0, y=30.0, z=0.275307 ),carla.Rotation(pitch=0.0, yaw=0.0, roll=0.000000))


def drive_through_plan(planned_route,speed,vehicles,PID):
    """
    This function drives throught the planned_route with the speed passed in the argument
    
    """
    #global i,j,target,distance_v,control, lock
    global lock,ii,z
    #test = find_waypoind(vehicles,planned_route[len(planned_route)])
    #planned_route = test
    #if j == 0 :
    target=planned_route[0]

    #j = 1
    ii=0
    while True:
        vehicle_loc= vehicles.get_location()
        #vehicle_loc= spawnPoint.get_location()
        distance_v =find_dist_veh(vehicle_loc,target)
        control = PID.run_step(speed,target)
        vehicles.apply_control(control)
        print('target',target)
        print('vehicle_loc',vehicle_loc)
        print('i',ii)
        if ii==(len(planned_route)-1):
            print("last waypoint reached")
            control = PID.run_step(0,planned_route[len(planned_route)-1])
            vehicles.apply_control(control)
            ii = 0
            z = z + 1
            lock = 0
            break
        
        if (distance_v<3.5):
            control = PID.run_step(speed,target)
            vehicles.apply_control(control)
            ii=ii+1
            target=planned_route[ii]
            print("vehicle_Debug4")

        cdata, f = asyncio.get_event_loop().run_until_complete(can_rc())

        if cdata[2] !=6:
            lock = 0 
            #i=0
            #control = PID.run_step(0,target)
            vehicles = carla.VehicleControl().steer =0.5
            vehicles = carla.VehicleControl().brake =1.0
            vehicles = carla.VehicleControl().throttle=0.0
            #print('last_control',control)
            #vehicles.apply_control(control)
            print('can_lock',lock)
            break

    #control = PID.run_step(0,planned_route[len(planned_route)-1])
    #vehicle.apply_control(control)

def find_dist(start ,end ):
    dist = math.sqrt( (start.transform.location.x - end.transform.location.x)**2 + (start.transform.location.y - end.transform.location.y)**2 )

    return dist



def find_dist_veh(vehicle_loc,target):
    dist = math.sqrt( (target.transform.location.x - vehicle_loc.x)**2 + (target.transform.location.y - vehicle_loc.y)**2 )
    
    return dist

def setup_PID(vehicle):      
    """
    This function creates a PID controller for the vehicle passed to it 
    """
    args_lateral_dict = {
            'K_P': 1.95,
            'K_D': 0.2,
            'K_I': 0.07

            ,'dt': 1.0 / 10.0
            }

    args_long_dict = {
            'K_P': 1,
            'K_D': 0.0,
            'K_I': 0.75
            ,'dt': 1.0 / 10.0
            }

    PID=controller.VehiclePIDController(vehicle,args_lateral=args_lateral_dict,args_longitudinal=args_long_dict)
    
    return PID




'''------------------------------------------------------------------'''
'''---------------------------Vehicle_CTRL---------------------------'''
def Ackermann_Info_Func(speed, acceleration):
    ack_vehicle_ctrl_info.speed = speed / SPEED_OFFSET;
    ack_vehicle_ctrl_info.acceleration = acceleration;

def Ack_Vehilce_ctrl(veldata, biodata) :
    if( biodata[0] == 1):
        if( ((veldata)-20) > 5 ):
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
        elif( (veldata) > 30) :   
            ack_vehicle_ctrl_info.speed =  0;
            ack_vehicle_ctrl_info.acceleration =abs((veldata) - (10/SPEED_OFFSET))
        else:
            ack_vehicle_ctrl_info.speed = 10 / SPEED_OFFSET
            ack_vehicle_ctrl_info.acceleration =  abs((veldata) - (10/SPEED_OFFSET)); #2km
    #elif( biodata[0] == 4):
        #if( ((veldata*SPEED_OFFSET)-40) > 5 ):
            #ack_vehicle_ctrl_info.speed =  5 / SPEED_OFFSETdf
            #ack_vehicle_ctrl_info.acceleration = 2
        #else:
            #ack_vehicle_ctrl_info.speed = 40 / SPEED_OFFSET
            #ack_vehicle_ctrl_info.acceleration = 0.6208 #2km
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
    gdata = 0.0
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
        Subvelocity.gdata = float(vel_data)


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
    if(gCanDataResult[2] == 5 or gCanDataResult[0] == 4):
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
    vehicle_ctrl_info.throttle= 0.0
    vehicle_ctrl_info.brake = 0.0
    vehicle_ctrl_info.steer= 0.0
    

    #Init_Carla()

    speed=30
    time.sleep(3)
    rospy.init_node("pub_hglee_velocity", anonymous=False)
    global lock , vehicles, z
    while not rospy.is_shutdown():
        #rospy.init_node("sub_hglee_velocity", anonymous=False)
        SubVeldata = Subvelocity()
    
        try:
            rospy.Subscriber("/carla/ego_vehicle/vehicle_status", 
            CarlaEgoVehicleStatus,SubVeldata.RosSubCallbak_DataCarla, queue_size = 1)
        except Exception as e:
            print( 'exception' , e )

        current_velocity=SubVeldata.GetRosdata()
        #df = pd.read_table("kang.txt", sep=":", names=['Name', 'Data'])
        #last_velocity = df[df["Name"] == 'velocity'].iloc[-1, 1]
        #print('last_velocity', last_velocity)
        #current_velocity = float(last_velocity)
        current_speed = get_speed(vehicles)
        print(current_speed)
        can_data, flag = asyncio.get_event_loop().run_until_complete(can_rc())

        print('main_lock',lock)
        print('main_z',z)


        if( flag == 0 ) :
            vehicle_cmd.publish(vehicle_ctrl_info)
            print('akc1')
            #lock = 0
        elif( can_data[2] == 6 ) :
            if( (z%2)== 1):
                #j=0
                #i=0
                lock = 1 
                wps=find_waypoind(vehicles,53)
                PID=setup_PID(vehicles)
                drive_through_plan(wps,gSpeed,vehicles,PID)
                print('debug72')

            #elif(  round(vx, 2) == round(x56, 2) and  round(vx, 2) == round(y56, 2) and z==0):
            elif( (z%2) == 0 ):
                #j=0
                #i=0
                wps=find_waypoind(vehicles,120)
                PID=setup_PID(vehicles)
                drive_through_plan(wps,gSpeed,vehicles,PID)
                print('debug56')
        else :
            print('debug_3')
            Ack_Vehilce_ctrl(current_velocity, can_data)
            ack_vehicle_cmd.publish(ack_vehicle_ctrl_info)
            #lock = 1
            print('ack2')
    
        #rospy.sleep(0.01)
        #print('속도: ', float(current_velocity)*SPEED_OFFSET)
        #Vehicle_ctrl(current_velocity ,can_data)

            
if __name__ == "__main__":
    #while True:
    try :
        main()
    
    except Exception as e:
        print( 'exception' , e )