'''
Created on Nov 17, 2018

@author: dtmasetti
'''
import numpy as np

def Calc3dArmPos(ShoulderAngle, ElbowAngle, RotatorCuffAngle, L1, L2):
    # MotorPos is a 2 element vector of the two motor positions
    theta = np.float(ShoulderAngle)
    phi = np.float(ElbowAngle)
    psi = np.float(RotatorCuffAngle)
    L1 = np.float(L1)
    L2 = np.float(L2)
    XYZElbow = np.array([[L1*np.cos(theta)*np.sin(psi)],[L1*np.sin(theta)], [L1*np.cos(psi)]])
    #print(theta
    XYZEndAffect = XYZElbow + np.array([[(L2*np.cos(theta)*np.cos(phi) - L2*np.sin(theta)*np.sin(phi))*np.sin(psi)],
                                        [L2*np.cos(phi)*np.sin(theta)+L2*np.sin(phi)*np.cos(theta)],
                                        [L2*np.cos(theta+phi)*np.cos(psi)]])
    return XYZElbow, XYZEndAffect 