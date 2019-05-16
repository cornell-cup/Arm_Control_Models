function [XYZElbow, XYZEndAffect] = CalcArmPos3d(MotorPos, L1, L2)
% MotorPos is a 3 element vector of the two motor positions
theta = MotorPos(1);
phi = MotorPos(2);
psi = MotorPos(3);
XYZElbow = [L1*cos(theta)*sin(psi);L1*sin(theta); L1*cos(psi)];
%disp(L1*cos(theta)*sin(psi))
XYZEndAffect = XYZElbow + [(L2*cos(theta)*cos(phi) - L2*sin(theta)*sin(phi))*sin(psi); 
                            L2*cos(phi)*sin(theta) + L2*sin(phi)*cos(theta)          ;
                            L2*cos(theta+phi)*cos(psi)];
