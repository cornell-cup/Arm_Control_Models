'''
Created on Nov 17, 2018

@author: dtmasetti
'''
import numpy as np
def Calc2LinkArmPos(MotorPos, L1, L2):
    # MotorPos is a 2 element vector of the two motor positions
    theta = float(MotorPos[0])
    phi = float(MotorPos[1])
    XYElbow = np.array([[L1*np.cos(theta)],[L1*np.sin(theta)]])
    XYElbow.shape = (2,1)
    transform = np.matrix([[np.cos(theta), np.sin(theta)], [-np.sin(theta), np.cos(theta)]])
    multarray = np.array([L2*np.cos(phi), L2*np.sin(phi)])
    multarray.shape=(2, 1)
    XYEndAffect = XYElbow + transform*multarray
    return XYElbow, XYEndAffect 