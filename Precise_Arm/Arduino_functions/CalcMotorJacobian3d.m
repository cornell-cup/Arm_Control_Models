function [dxyjac2d] = CalcMotorJacobian3d(theta, phi, psi, L1, L2)    
    dxdthet = (-L1*sin(theta)-L2*cos(phi)*sin(theta) - L2*cos(theta)*sin(phi)) * sin(psi);
    dxdphi =  (-L2*cos(theta)*sin(phi) + L2*sin(theta)*cos(phi)) * sin(psi);
    dxdpsi =  (L1*cos(theta) + L2*cos(theta)*cos(phi) - L2*sin(theta)*sin(phi))* cos(psi);
    
    dydthet = L1*cos(theta) + L2*cos(phi)*cos(theta) - L2*sin(phi)*sin(theta);
    dydphi  = -L2*sin(phi)*sin(theta) + L2*cos(phi)*cos(theta);
    dydpsi  = 0;
    
    dzdthet = (-L1*sin(theta) + -L2*sin(theta+phi)) * cos(psi);
    dzdphi = -L2*sin(theta+phi)*cos(psi);
    dzdpsi = -(L1*cos(theta)+L2*cos(theta+phi))*sin(psi);
    dxyjac2d = [dxdthet, dxdphi, dxdpsi; dydthet, dydphi, dydpsi; dzdthet, dzdphi, dzdpsi];
end