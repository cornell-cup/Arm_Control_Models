%% Perform Control in XYZ Frame
close all
clear variables

%% Initial Positions and Parameters
RotatorCuffAngledeg = 25;
ElbowAngledeg = -40;
ShoulderAngledeg = 25;
L1 = 20;
L2 = 25;
%% Target XYZ Position
goalx = 2;
goaly = 10;
goalz = 4;

InitialMotorControlAngles = [ShoulderAngledeg; ElbowAngledeg; RotatorCuffAngledeg]/pi() * 180;
%disp(InitialMotorControlAngles/pi*180)

[FinalMotorControlAngles] = PiFunction_3Axis(ShoulderAngledeg, ElbowAngledeg, RotatorCuffAngledeg, L1, L2, goalx, goaly, goalz);
%disp(FinalMotorControlAngles/pi()*180)

%% Make a Plot of the Results
[XYZElbStart, XYZEndAffectStart] = CalcArmPos3d(InitialMotorControlAngles, L1, L2);
[XYZElb, XYZEndAffect] = CalcArmPos3d(FinalMotorControlAngles, L1, L2);
figure()
hold on
%% Plot Starting Position for the Arm
plot3(XYZEndAffectStart(1), XYZEndAffectStart(2), XYZEndAffectStart(3), 'k*');
% Plot Elbow
elb = plot3([0, XYZElbStart(1)], [0, XYZElbStart(2)], [0, XYZElbStart(3)], 'm--');
%plot Forearm
forearm = plot3([XYZElbStart(1), XYZEndAffectStart(1)], [XYZElbStart(2), XYZEndAffectStart(2)], [XYZElbStart(3), XYZEndAffectStart(3)], 'b--');

%% Plot Ending Position for The Arm
plot3(goalx, goaly, goalz, 'g*');
% Plot Elbow
elb = plot3([0, XYZElb(1)], [0, XYZElb(2)], [0, XYZElb(3)], 'm');
%plot Forearm
forearm = plot3([XYZElb(1), XYZEndAffect(1)], [XYZElb(2), XYZEndAffect(2)], [XYZElb(3), XYZEndAffect(3)], 'b');

legend('Starting Point', 'Upper Arm Start', 'Forearm Start', 'Goal Point', 'Upper Arm End', 'Forearm End')