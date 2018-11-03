function Precise_Arm_Parameters()
close all
clear variables
%% Arm Servo Positions
Base_Servo_Ang =0;
UpArm_Servo_Ang = 10; % CCW rotation around y axis, reference to inertial z
CamRad_Ang = 0; % CCW rotation around y axis, reference to inertial z

%% Servo Information
S_Base_Loc = [0; 0; 0]; % Rotates around z. This is the defining point of the reference frame
SBaseanglerange = 360;

S_UpArm_Loc = [0; -2; 5]; % The Upper Arm begins on this point, and rotates around the x axis
S_UpArm_anglerange = 180;

S_LoArmLink_Loc = [0; 2; 5]; % The Servo Radius Begins Here
S_LoArmLink_anglerange = 360;

%% Upper Arm Dimensions
L_UpArm = 28.267; %cm
UpArmtransmat = MakeYAxisTrans(UpArm_Servo_Ang ); %Transformation from Inertial to Upper Arm, Z along arm
ArmEndPoint = S_UpArm_Loc + inv(UpArmtransmat)*[0; 0; L_UpArm]; 
UpArmPos = [S_UpArm_Loc, ArmEndPoint];

%% Servo Radius
L_CamRad = 2; %cm
CamRadiustransmat = MakeYAxisTrans(CamRad_Ang);
Camlinkstartpoint = S_LoArmLink_Loc+inv(CamRadiustransmat)*[0;0;L_CamRad];
CamRadPos = [S_LoArmLink_Loc, Camlinkstartpoint];

%% Lower Arm Angles
L_CamLink = 50.267; %cm This is a guess
L_LowArmHorn = 1.5;
x0 = [-30; -5];
pars = [UpArm_Servo_Ang/180*pi, CamRad_Ang/180*pi, L_UpArm, L_LowArmHorn, L_CamRad, L_CamLink];
camlinklowerlinkangles = fsolve(@solvecamlink,x0,[], pars, UpArmtransmat, CamRadiustransmat);
%Check my math
[out1] = solvecamlink(camlinklowerlinkangles, pars, UpArmtransmat, CamRadiustransmat);
CamLink_Ang = camlinklowerlinkangles(2);
LowerLink_Ang = camlinklowerlinkangles(1);
CamLink_Ang = x0(2);
LowerLink_Ang = x0(1);

%% CamLink Position
CamLinkTransmat = MakeYAxisTrans(CamLink_Ang);
camlinkendpoint = Camlinkstartpoint + inv(CamRadiustransmat)*inv(CamLinkTransmat) * [0;0;L_CamLink];
CamLinkPos = [Camlinkstartpoint, camlinkendpoint];

%% Low Arm Dimensions
L_LoArm = 27.6966; %cm
LoArmtransmat = MakeYAxisTrans(LowerLink_Ang);
LoarmEndPoint = ArmEndPoint + inv(UpArmtransmat)*inv(LoArmtransmat)*[0;0;L_LoArm];
LoArmPos = [ArmEndPoint, LoarmEndPoint];

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
plot3dline(CamLinkPos);
plot3dline(LoArmPos);
legend('Base Servo', 'Upper Arm Servo', 'Lower Arm Link Servo', 'Upper Arm', 'Cam Radius', 'Cam Link', 'Lo Arm Radius')
xlabel('X Axis (Inertial)');
ylabel('Y Axis (Inertial)');
zlabel('Z Axis (Inertial)');

end
function [output] = solvecamlink(input, pars, transmat1, transmat2)
    anguparm = pars(1);
    angcamrad = pars(2);
    L_UpArm = pars(3);
    L_LowArmHorn = pars(4); 
    L_CamRad = pars(5);
    L_CamLink = pars(6);
    anglowarm = input(1);
    angcamlink = input(2);
    uparmtransmat = transmat1;
    camradtransmat = transmat2;

    term1 = L_UpArm.*[cos(anguparm); 0; sin(anguparm)];
    term2 = inv(uparmtransmat)*(L_LowArmHorn.*[cos(anglowarm); 0; sin(anglowarm)]);
    term3 = L_CamRad.*[cos(angcamrad); 0; sin(angcamrad)];
    term4 = inv(camradtransmat)*(L_CamLink.*[cos(angcamlink); 0; sin(angcamlink)]);
    temp =  term1 + term2 - term3 - term4;
    output = [temp(1); temp(3)];
end