
import carla

from global_route_planner import  GlobalRoutePlanner
from global_route_planner_dao import GlobalRoutePlannerDAO 

import time
import math
import numpy as np
import controller
import rospy

import can
import asyncio
from os import system
import sys


vehicle_num = 219
#spawn_points[346].location

gCanDataResult = 0

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
    if gCanDataResult[0]!=5:
        exec(open('./pid_pot.py').read())
        print('out')
    # Clean-up
    print(gCanDataResult)
    notifier.stop()
    #can0.shutdown()


#Location(x=-410.0, y=16.0, z=0.275307 )
def spawn_vehicle(spawnPoint=carla.Transform(carla.Location(x=-400.0, y=30.0, z=0.275307 ),carla.Rotation(pitch=0.0, yaw=0.0, roll=0.000000))):
    
    """
    
    This function spawn vehicles in the given spawn points. If no spawn 
    point is provided it spawns vehicle in this 
    position x=27.607,y=3.68402,z=0.02
    """
    
    spawnPoint=spawnPoint
    world = client.get_world()
    blueprint_library = world.get_blueprint_library()
    bp = blueprint_library.find('vehicle.toyota.prius')

    vehicle = world.spawn_actor(bp, spawnPoint)
    return vehicle
    

    
def drive_through_plan(planned_route,vehicle,speed,PID):
    """
    This function drives throught the planned_route with the speed passed in the argument
    
    """
    
    i=0
    target=planned_route[0]
    print('target',target)
   
    while True:
        vehicle_loc= vehicle.get_location()
        #vehicle_loc= spawnPoint.get_location()
        distance_v =find_dist_veh(vehicle_loc,target)
        control = PID.run_step(speed,target)
        vehicle.apply_control(control)
        asyncio.get_event_loop().run_until_complete(can_rc())


        if i==(len(planned_route)-1):
            print("last waypoint reached")
            break 
        
        if (distance_v<3.5):
            control = PID.run_step(speed,target)
            vehicle.apply_control(control)
            i=i+1
            target=planned_route[i]

            

    control = PID.run_step(0,planned_route[len(planned_route)-1])
    vehicle.apply_control(control)
                

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



#rospy.init_node("pub_hglee_pid", anonymous=False)

client = carla.Client("localhost", 2000)
client.set_timeout(10)
#world = client.load_world('Town04')
world = client.get_world()



amap = world.get_map()
sampling_resolution = 2
dao = GlobalRoutePlannerDAO(amap, sampling_resolution)
grp = GlobalRoutePlanner(dao)
grp.setup()
spawn_points = world.get_map().get_spawn_points()
a = carla.Location(spawn_points[351].location)
b = carla.Location(spawn_points[367].location)
w1 = grp.trace_route(a, b) 

world.debug.draw_point(a,color=carla.Color(r=255, g=0, b=0),size=0.4 ,life_time=120.0)
world.debug.draw_point(b,color=carla.Color(r=255, g=0, b=0),size=0.4 ,life_time=120.0)




wps=[]

for i in range(len(w1)):
    wps.append(w1[i][0])
    world.debug.draw_point(w1[i][0].transform.location,color=carla.Color(r=255, g=0, b=0),size=0.2 ,life_time=120.0)

spawnPoint=carla.Transform(carla.Location(x=-400.0, y=30.0, z=0.275307 ),carla.Rotation(pitch=0.0, yaw=0.0, roll=0.000000))
vehicles = world.get_actors().find(vehicle_num)
vehicles = carla.Actor.set_transform(vehicles,spawnPoint)
vehicles = world.get_actors().find(vehicle_num)

#vehicle=spawn_vehicle()
#spawnPoint=carla.Transform(carla.Location(x=-400.0, y=30.0, z=0.275307 ),carla.Rotation(pitch=0.0, yaw=0.0, roll=0.000000))

PID=setup_PID(vehicles)

speed=30
drive_through_plan(wps,vehicles,speed,PID)
print('end')


'''
client = carla.Client("localhost", 2000)
world = client.get_world()
vehicles = world.get_actors().filter('vehicle.toyota.prius')
print(vehicles)'''