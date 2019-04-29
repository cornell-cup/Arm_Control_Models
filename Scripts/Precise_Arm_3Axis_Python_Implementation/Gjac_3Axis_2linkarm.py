'''
Created on Nov 17, 2018

@author: dtmasetti
'''
import numpy as np
def Calc3axisJac(theta, phi, psi, L1, L2):
    dxdthet = (-L1*np.sin(theta)-L2*np.cos(phi)*np.sin(theta) - L2*np.cos(theta)*np.sin(phi))*np.sin(psi)
    dxdphi = (-L2*np.cos(theta)*np.sin(phi) + L2*np.sin(theta)*np.cos(phi))*np.sin(psi)
    dxdpsi =  (L1*np.cos(theta) + L2*np.cos(theta)*np.cos(phi) - L2*np.sin(theta)*np.sin(phi))* np.cos(psi)
    
    
    dydthet = L1*np.cos(theta) + L2*np.cos(phi)*np.cos(theta) - L2*np.sin(phi)*np.sin(theta)
    dydphi = -L2*np.sin(phi)*np.sin(theta) + L2*np.cos(phi)*np.cos(theta)
    dydpsi  = 0
        
    dzdthet = (-L1*np.sin(theta) - L2*np.sin(theta+phi)) * np.cos(psi)
    dzdphi = -L2*np.sin(theta+phi)*np.cos(psi)
    dzdpsi = -(L1*np.cos(theta)+L2*np.cos(theta+phi))*np.sin(psi)
    return np.array([[dxdthet, dxdphi, dxdpsi], [dydthet, dydphi, dydpsi], [dzdthet, dzdphi, dzdpsi]])