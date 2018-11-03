function [dxyjac2d] = CalcMotorJacobian(theta, phi, L1, L2)
    dxdthet = -L1*sin(theta)-L2*cos(phi)*sin(theta) + L2*cos(theta)*sin(phi);
    dxdphi = -L2*cos(theta)*sin(phi) + L2*sin(theta)*cos(phi);
    dydthet = L1*cos(theta) - L2*cos(phi)*cos(theta) - L2*sin(phi)*sin(theta);
    dydphi = L2*sin(phi)*sin(theta) + L2*cos(phi)*cos(theta);
    dxyjac2d = [dxdthet, dxdphi; dydthet, dydphi];
end