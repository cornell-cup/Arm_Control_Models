%% Perform Control in XYZ Frame
function [FinalMotorControlAngles] = PiFunction_3Axis(ShoulderAngledeg, ElbowAngledeg, RotatorCuffAngledeg, L1, L2, goalx, goaly, goalz)
%% Inputs:
% ShoulderAngledeg: The starting angle in degrees of the shoulder servo
% ElbowAngledeg: The starting angle in degrees of the elbow servo
% RotatorCuffAngle: The starting angle in degrees of the rotator cuff
% L1: The length of the upper arm (between pivot points), in inches
% L2: The length of the lower arm (between pivot points), in inches
% goalx: The x-coordinate of the goal point of the arm, in inches
% goaly: The y-coordinate of the goal point of the arm, in inches
% goalz: The z-coordinate of the goal point of the arm, in inches

%% Outputs
% FinalMotorControlAngles: A 3-value vector that contains the command
% angles of the servos, in radians, in the order of shoulder angle, elbow
% angle, and rotatorcuff angle

%% Code
%ShoulderAngledeg = 40;
%ElbowAngledeg = 5;
%RotatorCuffAngledeg = 20;
%L1 = 20;
%L2 = 25;
goaltolerance = .1; %Inches. Making this smaller may prevent solution convergence.
numpoints = 1000; %The number of points to generate along the trajectory. Probably won't help convergence to make this smaller
limitangchange = 2*pi/108; %Limit the maximum angle change on any motor per step. Make this smaller if solution does not converge


ShoulderAngle = ShoulderAngledeg/180*pi;
ElbowAngle = ElbowAngledeg/180*pi; % Elbow Angle is Measured CCW from Shoulder Angle
RotatorCuffAngle = RotatorCuffAngledeg/180*pi; % Rotator Cuff Angle is measured counterclockwise from 

[ElbowStart, ArmStart] = CalcArmPos3d([ShoulderAngle; ElbowAngle; RotatorCuffAngle], L1, L2);
ArmEnd = [goalx; goaly;goalz];
MotorPos(:, 1) = [ShoulderAngle; ElbowAngle; RotatorCuffAngle];

%% Create the Path to Travel Along
magchangex = ArmEnd(1) - ArmStart(1);
magchangey = ArmEnd(2) - ArmStart(2);
magchangez = ArmEnd(3) - ArmStart(3);
for j = 1:numpoints
    t = j/numpoints; % Function has to equal 1 when t is maxed out
    Pointstocontroltox(j) = t*magchangex + ArmStart(1);
    Pointstocontroltoy(j) = t*magchangey + ArmStart(2);
    Pointstocontroltoz(j) = t*magchangez + ArmStart(3);
end
ControlPoints = [Pointstocontroltox; Pointstocontroltoy; Pointstocontroltoz];

%% Calculate the Trajectory
ElbowPos(:, 1) = ElbowStart;
ArmPos(:, 1) = ArmStart;
for i = 2:numpoints
    % Generate this timesteps control
    Lastxy = ControlPoints(:, i-1);
    Nextxy = ControlPoints(:, i);
    deltaXY = Nextxy - Lastxy; % This is effectively the velocity vector we want the arm to follow
    % Calculate Jacobian of Arm Position With Respect to Motor Commands
    MotorPosTemp = MotorPos(:, i-1);
    theta = MotorPosTemp(1); phi = MotorPosTemp(2); psi = MotorPosTemp(3);
    JacMat = CalcMotorJacobian3d(theta, phi, psi, L1, L2);
    deltaanglecommands = inv(JacMat)*deltaXY;
    deltaanglecommands(1) = min([deltaanglecommands(1), limitangchange]);
    deltaanglecommands(2) = min([deltaanglecommands(2), limitangchange]);
    deltaanglecommands(3) = min([deltaanglecommands(3), limitangchange]);
    % Update Dynamics to Show where the arm is now
    MotorPosTemp = MotorPosTemp + deltaanglecommands;
    [ElbowPosStep, ArmPosStep] = CalcArmPos3d(MotorPosTemp, L1, L2);
    %end
 %   fprintf('Step %d out of $d\n', i, numpoints)
    MotorPos(:, i) = MotorPosTemp;
    ElbowPos(:, i) = ElbowPosStep;
    ArmPos(:, i) = ArmPosStep;
    
end
while norm(ArmPosStep-ControlPoints(:, i))>goaltolerance
    % If arm did not arrive at solution in initial numpoints, keep
    % simulating until it does
    Lastxy = ArmPos(:, end);
    Nextxy = ControlPoints(:, i);
    deltaXY = Nextxy - Lastxy; % This is effectively the velocity vector we want the arm to follow
    % Calculate Jacobian of Arm Position With Respect to Motor Commands
    MotorPosTemp = MotorPos(:, end);
    ArmPosStep = ArmPos(:, end);
    ElbowPosStep = ElbowPos(:, end);
    theta = MotorPosTemp(1); phi = MotorPosTemp(2); psi = MotorPosTemp(3);
    JacMat = CalcMotorJacobian3d(theta, phi, psi, L1, L2);
    deltaanglecommands = inv(JacMat)*deltaXY;
    deltaanglecommands(1) = min([deltaanglecommands(1), limitangchange]);
    deltaanglecommands(2) = min([deltaanglecommands(2), limitangchange]);
    deltaanglecommands(3) = min([deltaanglecommands(3), limitangchange]);
    % Update Dynamics to Show where the arm is now
    MotorPosTemp = MotorPosTemp + deltaanglecommands;
    [ElbowPosStep, ArmPosStep] = CalcArmPos3d(MotorPosTemp, L1, L2);
    MotorPos = [MotorPos, MotorPosTemp];
    ElbowPos = [ElbowPos, ElbowPosStep];
    ArmPos = [ArmPos, ArmPosStep];
end
FinalMotorControlAngles = wrapToPi(MotorPos(:, end));
