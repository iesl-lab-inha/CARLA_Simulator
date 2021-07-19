 #!/usr/bin/env python

#websocket
import websockets
import asyncio
import json

#ros
import rospy
from geometry_msgs.msg import Twist, Transform
#carla rosbridge
from carla_ros_bridge.vehicle import Vehicle
from carla_ros_bridge.ego_vehicle import EgoVehicle
import carla_common.transforms as transforms
from carla_msgs.msg import CarlaEgoVehicleInfo, CarlaEgoVehicleInfoWheel,\
    CarlaEgoVehicleControl, CarlaEgoVehicleStatus

from rospy_message_converter import json_message_converter



async def connect(hg_data):
    async with websockets.connect("ws://localhost:3000") as websocket:
        await websocket.send(hg_data)
        data = await websocket.recv()
        print(data)

class csRosCarla:
    #global
    gdata = ""
    def __init__(self):
        self.json_str =""

    def GetRosdata(self):
        #return self.json_str
        return csRosCarla.gdata

    def RosSubCallbak_DataCarla(self,data):      
        #self.json_str = json_message_converter.convert_ros_message_to_json(data)
        csRosCarla.gdata = json_message_converter.convert_ros_message_to_json(data)
        
        

def main():

    rospy.init_node("carla_webdata", anonymous=False)
    rsCarladata = csRosCarla()

    try:
        rospy.Subscriber("/carla/ego_vehicle/vehicle_status", 
        CarlaEgoVehicleStatus, rsCarladata.RosSubCallbak_DataCarla )
    except Exception:
        print( 'exception' )
    
    a = rsCarladata.GetRosdata()
    print(a)
    asyncio.get_event_loop().run_until_complete(connect(a))


if __name__ == "__main__":
    while True:
        main()
