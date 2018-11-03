function [XYElbow, XYEndAffect] = CalcArmPos(MotorPos, L1, L2)
% MotorPos is a 2 element vector of the two motor positions
theta = MotorPos(1);
phi = MotorPos(2);
XYElbow = [L1*cos(theta);L1*sin(theta)];
transform = [cos(theta), sin(theta); -sin(theta), cos(theta)];
XYEndAffect = XYElbow + transform*[L2*cos(phi); L2*sin(phi)];