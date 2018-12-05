'''
Created on Nov 25, 2018

@author: dtmasetti
'''
# Main Simulation Module
import numpy as np
global ElbowAngleSim, ShoulderAngleSim, ObjectLocationSim
ElbowAngleSim = float(5)
ShoulderAngleSim = float(0)
ObjectLocationSim = np.array([[float(12)], [float(5)]])

def ReadEncoder(encodernum):
    # On the actual robot, this function should read the encoder measurement sent back through serial
    if encodernum == 0:
        ShoulderAngleEncoderRead = ShoulderAngleSim
        return ShoulderAngleEncoderRead
    elif encodernum == 1:
        ElbowAngleEncoderRead = ElbowAngleSim
        return ElbowAngleEncoderRead
    else:
        AttributeError
def ReadObjectRecognitionFunction():
    # On the actual robot, this function should use the camera mounted on the robot to calculate the desired arm position (in the reference frame of the arm)
    ObjectRecognitionLoc = ObjectLocationSim
    return ObjectRecognitionLoc