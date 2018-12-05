'''
Created on Nov 17, 2018

@author: dtmasetti
'''
import numpy as np
def Calc2linkJac(theta, phi, L1, L2):
    dxdthet = -L1*np.sin(theta)-L2*np.cos(phi)*np.sin(theta) + L2*np.cos(theta)*np.sin(phi)
    dxdphi = -L2*np.cos(theta)*np.sin(phi) + L2*np.sin(theta)*np.cos(phi);
    dydthet = L1*np.cos(theta) - L2*np.cos(phi)*np.cos(theta) - L2*np.sin(phi)*np.sin(theta);
    dydphi = L2*np.sin(phi)*np.sin(theta) + L2*np.cos(phi)*np.cos(theta);
    return np.array([[dxdthet, dxdphi], [dydthet, dydphi]])