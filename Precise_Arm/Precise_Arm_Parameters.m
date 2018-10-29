close all
clear variables
%% Arm Servo Positions
Base_Servo_Ang =0;
UpArm_Servo_Ang = 20; % CCW rotation around y axis, reference to inertial z
CamLink_Servo_Ang = 0; % CCW rotation around y axis, reference to inertial z

%% Servo Information
S_Base_Loc = [0, 0, 0]; % Rotates around z. This is the defining point of the reference frame
SBaseanglerange = 360;

S_UpArm_Loc = [0, -2, 5]; % The Upper Arm begins on this point, and rotates around the x axis
S_UpArm_anglerange = 180;

S_LoArmLink_Loc = [0, 2, 5]; % The Servo Radius Begins Here
S_LoArmLink_anglerange = 360;

%% Upper Arm Dimensions
L_UpArm = 28.267; %cm
UpArmtransmat = MakeYAxisTrans(UpArm_Servo_Ang ); %Transformation from Inertial to Upper Arm, Z along arm
ArmEndPoint = S_UpArm_Loc' + inv(UpArmtransmat)*[0; 0; L_UpArm]; 
UpArmPos = [S_UpArm_Loc; ArmEndPoint'];

%% Servo Radius
R_LoArmLink_S = 2; %cm
CamRadiustransmat = MakeYAxisTrans(CamLink_Servo_Ang);
Camlinkstartpoint = S_LoArmLink_Loc'+inv(CamRadiustransmat)*[0;0;R_LoArmLink_S];
CamRadPos = [S_LoArmLink_Loc; Camlinkstartpoint'];

%% Lower Arm Linkage
L_camlink = 28.267; %cm This is a guess


%% Lower Arm Dimensions
L_LoArm = 27.6966; %cm

%% Plot the Arm Geometry
figure()
hold on
axis equal
title('Arm Geometry')
plotpoint(S_Base_Loc);
plotpoint(S_UpArm_Loc);
plotpoint(S_LoArmLink_Loc);
disp(UpArmPos)
plot3dline(UpArmPos);
plot3dline(CamRadPos);
legend('Base Servo', 'Upper Arm Servo', 'Lower Arm Link Servo', 'Upper Arm', 'Cam Radius')
xlabel('X Axis (Inertial)');
ylabel('Y Axis (Inertial)');
zlabel('Z Axis (Inertial)');