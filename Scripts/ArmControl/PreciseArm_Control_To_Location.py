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
from matplotlib.backend_bases import GraphicsContextBase
def ElbowAngleLookup(anglein):
    return anglein
    
tol = .5
numctrlptsperinch = 10
# Get Encoder Position -- to be used as the initial position in simulation
pi = np.pi
ShoulderAngledeg = Simulation.ReadEncoder(0)
ElbowAngledegprelookup = Simulation.ReadEncoder(1)
ElbowAngledeg = ElbowAngleLookup(ElbowAngledegprelookup)

ShoulderAngleStart = ShoulderAngledeg/180*pi
ElbowAngleStart = ElbowAngledeg/180*pi
CurrAngs = np.array([[ShoulderAngleStart],[ElbowAngleStart]])

# Get Arm Goal, from object detection algorithm
ArmEnd = Simulation.ReadObjectRecognitionFunction()

# Initialize Precise Arm Parameters
import Parameters_Precise_Arm as PrecArm
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