'''
Created on Nov 17, 2018
Function that can be called on R2D2 to generate 3-angle commands for any given X,Y,Z point that is achievable by R2.
@author: dtmasetti
'''
import numpy as np
import Calc3dArmPos as Calc3dArmPos
import Gjac_3Axis_2linkarm as Gjac
 
# The Following Information Should be Passed As Inputs
goalx= 12 #Target X coordinate
goaly = 20 #Target Y Coordinate
goalz = 4 #Target Z Coordinate
RotatorCuffAngledeg = np.float(25) #Starting Rotator Cuff Angle (either measure or command this)
ElbowAngledeg = np.float(40) #Starting Elbow Angle (either measure or command this)
ShoulderAngledeg = np.float(10) #Starting Shoulder Angle (either measure or command this)
L1 = np.float(20) #Length of Upper Arm
L2 = np.float(25) #Length of Forearm

# Code Begins Here  
pi = np.pi
goaltolerance = .1 #Inches. Making this smaller may prevent solution convergence.
numpoints = 1000 #The number of points to generate along the trajectory. Probably won't help convergence to make this smaller
limitangchange = 2*pi/108 #Limit the maximum angle change on any motor per step. Make this smaller if solution does not converge

ShoulderAngle = ShoulderAngledeg/180*pi
ElbowAngle = ElbowAngledeg/180*pi
RotatorCuffAngle = RotatorCuffAngledeg/180*pi

# Calculate where the end affector is    
[ElbowStart, ArmStart] = Calc3dArmPos.Calc3dArmPos(ShoulderAngle, ElbowAngle, RotatorCuffAngle, L1, L2)
# Store the target point in a vector
ArmEnd = np.array([[goalx],[goaly],[goalz]])

# Create Vector of Starting Arm Angles
MotorPos = np.array([[ShoulderAngle],[ElbowAngle], [RotatorCuffAngle]])

# Plan the trajectory
magchangex = float(ArmEnd[0]) - float(ArmStart[0])
magchangey = float(ArmEnd[1]) - float(ArmStart[1])
magchangez = float(ArmEnd[2]) - float(ArmStart[2])

ctrlptsx = np.zeros(numpoints)
ctrlptsy = np.zeros(numpoints)
ctrlptsz = np.zeros(numpoints)
ctrlptsxyz = np.zeros([3, numpoints])
# Calculate Control Trajectory
for i in range(0, numpoints):
    fraction = np.float(i+1)/np.float(numpoints)
    ctrlptsx[i] = fraction * magchangex + float(ArmStart[0])
    ctrlptsy[i] = fraction * magchangey + float(ArmStart[1])
    ctrlptsz[i] = fraction * magchangez + float(ArmStart[2])
    
ctrlptsxyz = ([[ctrlptsx], [ctrlptsy], [ctrlptsz]])   
theta = ShoulderAngle
phi = ElbowAngle
psi = RotatorCuffAngle 
for i in range(1, numpoints):
    i = int(i)
    Lastxyz = np.array([[ctrlptsx[i-1]],
                        [ctrlptsy[i-1]],
                        [ctrlptsz[i-1]]])
    Nextxyz = np.array([[ctrlptsx[i]],
                        [ctrlptsy[i]],
                        [ctrlptsz[i]]])
    deltaXY = Nextxyz - Lastxyz # Arm Traj Between Control Points
    # Calculate Jacobian of Arm Position With Respect to Motor Commands
    JacMat = Gjac.Calc3axisJac(theta, phi, psi, L1, L2)

    jacinv = np.linalg.inv(JacMat)
    deltaXY.shape = (deltaXY.size, 1)
    deltaanglecommands = jacinv.dot(deltaXY)
    thetaold = np.float(theta)
    phiold = np.float(phi)
    psiold = np.float(psi)
    theta = thetaold + np.float(deltaanglecommands[0])
    phi = phiold + np.float(deltaanglecommands[1])
    psi = psiold + np.float(deltaanglecommands[2])
    [ElbowPosStep, ArmPosStep] = Calc3dArmPos.Calc3dArmPos(theta, phi, psi, L1, L2)
    
dist = np.sqrt((ArmPosStep[0] - ctrlptsx[i])**2 + (ArmPosStep[1]-ctrlptsy[i])**2 + (ArmPosStep[2]-ctrlptsz[i])**2)
while dist > goaltolerance:
    i = int(i)
    Lastxyz = ArmPosStep
    #print Lastxyz
    Nextxyz = np.array([[ctrlptsx[i]],
                        [ctrlptsy[i]],
                        [ctrlptsz[i]]])
    deltaXY = Nextxyz - Lastxyz # Arm Traj Between Control Points
    # Calculate Jacobian of Arm Position With Respect to Motor Commands
    JacMat = Gjac.Calc3axisJac(theta, phi, psi, L1, L2)
    jacinv = np.linalg.inv(JacMat)
    deltaXY.shape = (deltaXY.size, 1)
    deltaanglecommands = jacinv.dot(deltaXY)
    thetaold = np.float(theta)
    phiold = np.float(phi)
    psiold = np.float(psi)
    theta = thetaold + np.float(deltaanglecommands[0])
    phi = phiold + np.float(deltaanglecommands[1])
    psi = psiold + np.float(deltaanglecommands[2])
    [ElbowPosStep, ArmPosStep] = Calc3dArmPos.Calc3dArmPos(theta, phi, psi, L1, L2)
    dist = np.sqrt((ArmPosStep[0] - ctrlptsx[i])**2 + (ArmPosStep[1]-ctrlptsy[i])**2 + (ArmPosStep[2]-ctrlptsz[i])**2)
#print(ArmPosStep) # Print this if you want to see that the arm is arriving at the goal

# Return these three variables as outputs from the function
FinalShoulderAngle = theta #Radians
FinalElbowAngle = phi #Radians
FinalRotatorCuffAngle = psi #Radians
print(theta)
print(phi)
print(psi)