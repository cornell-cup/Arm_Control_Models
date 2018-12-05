'''
Created on Nov 17, 2018
Function that can be called on R2D2 to command the arm to the location specified object recognition function output
Assumes that "ReadEncoder", "ElbowAngleLookup", and "GetObjectRecognitionLocation" functions are all available on R2 System
@author: dtmasetti
'''
import numpy as np
import Calc2LinkArmPos as CalcArmPos
import Gjac_2linkarm as Gjac
import matplotlib
import matplotlib.pylab as pyl
import matplotlib.pyplot as plt
import Simulation
import time
from matplotlib.backend_bases import GraphicsContextBase
def ElbowAngleLookup(anglein):
    return anglein
pi = np.pi

####################### Add Code Here ################################################################################################
# Replace the lines below with the initial motor angles. For demo day, since we don't have motor position being fed
# back to the pi, just use the initial motor commands as the position. Pick any angles but make sure the arm is actually controlled there 
ShoulderAngledeg = Simulation.ReadEncoder(0) #Initial angle in degrees
ElbowAngledegprelookup = Simulation.ReadEncoder(1) #Initial angle in degrees

numctrlptsperinch = 10 ## Increase this for better path tracking, but slower simulation

# Get Arm Goal, from object detection algorithm - in demo day, this is simply the goal/waypoint that we want the arm to go to
# Note, this ArmEnd is simply one location in this case. It can be replaced with a "For" Loop if desired to command to multiple positions
ArmEnd = Simulation.ReadObjectRecognitionFunction()
####################### End Add Code Region ##########################################################################################

# Perform Path Planning 
ElbowAngledeg = ElbowAngleLookup(ElbowAngledegprelookup) #This is a straight pass through. Assumes shoulder motor angle for lower arm control is identical to elbow angle (True in parallelogram case)
ShoulderAngleStart = ShoulderAngledeg/180*pi
ElbowAngleStart = ElbowAngledeg/180*pi
CurrAngs = np.array([[ShoulderAngleStart],[ElbowAngleStart]])

# Initialize Precise Arm Parameters
import Parameters_Precise_Arm as PrecArm # This requires that the Parameters_Precise_Arm be updated to match the real parameters
# Calculate where the precise arm end affector is    
[ElbowStart, ArmStart] = CalcArmPos.Calc2LinkArmPos(CurrAngs, PrecArm.L1, PrecArm.L2)

# Plan the trajectory
magchangex = float(ArmEnd[0]) - float(ArmStart[0])
magchangey = float(ArmEnd[1]) - float(ArmStart[1])
totalmag = np.sqrt(magchangex**2 + magchangey**2)
numpoints = int(np.round(totalmag * numctrlptsperinch))
ctrlptsx = np.zeros(numpoints)
ctrlptsy = np.zeros(numpoints)
ctrlptsangs = np.zeros((2, numpoints))
ctrlptsxy = np.zeros((2, numpoints))
# Calculate Control Trajectory
for i in range(0, numpoints):
    fraction = np.float(i+1)/np.float(numpoints)
    ctrlptsx[i] = fraction * magchangex
    ctrlptsy[i] = fraction * magchangey
    ctrlptsxy[(0,1), i] = np.squeeze([[ctrlptsx[i]], [ctrlptsy[i]]])
    if i==0:
        ctrlptsangs[(0, 1), i] = np.squeeze(CurrAngs)
    else:
        Lastxy = ctrlptsxy[(0,1), i-1]
        Nextxy = ctrlptsxy[(0,1), i]
        deltaXY = Nextxy - Lastxy # Arm Traj Between Control Points
        # Calculate Jacobian of Arm Position With Respect to Motor Commands
        theta = ctrlptsangs[0, i-1]
        phi = ctrlptsangs[1, i-1]
        JacMat = Gjac.Calc2linkJac(theta, phi, PrecArm.L1, PrecArm.L2)
        jacinv = np.linalg.inv(JacMat)
        deltaXY.shape = (deltaXY.size, 1)
        deltaanglecommands = jacinv.dot(deltaXY)
        ctrlptsangs[0, i] = ctrlptsangs[0, i-1] + deltaanglecommands[0]
        ctrlptsangs[1, i] = ctrlptsangs[1, i-1] + deltaanglecommands[1]
if 1: # This will save a figure of the predicted trajectory of the elbow and arm to your C:/Temp Location
    a = pyl.figure()
    [L, W]= np.shape(ctrlptsangs)
    for i in range(W):
        CurrAngs = ctrlptsangs[(0, 1), i]
        [XYElbowPos, XYArmPos] = CalcArmPos.Calc2LinkArmPos(CurrAngs, PrecArm.L1, PrecArm.L2)
        pyl.plot(XYElbowPos[0], XYElbowPos[1], 'r*')
        pyl.plot(XYArmPos[0], XYArmPos[1], 'b*')
    a.savefig('C:\\temp\plotArmPath')
#    for i in range()
#    CurrAngs = 

#    pyl.plot()
################################################# Add Code Here to Send Commands to Motors#################################      
# ctrlptsangs now should include the the angles to control the motors to throughout operation to trace a straight line path in 
# between the start point and the end point. If you loop through these angles with well-timed sleeps, you could create a smooth path
# and, theoretically, the end affector would travel in a perfect straight line, even though the motor angles would do something funky
# This could be cool if we want to sign an autograph.
# Note that the arduino simply has to receive both angle commands and immediately implement them, but sleeps could be added in 
# the arduino as well to make the arms move more slowly

# Pseudocode begins here -- replace with actual code for communicating with arduino
# For all angles in ctrlptsangs
#      Serial.Write(shouldermotor, ctrlptsangs[0, index])
#      Serial.Write(Elbowmotor, ctrlptsangs[1, index])
#      Sleep(tunableamountoftime) based on how quickly the servos respond to commands

