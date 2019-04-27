%% Perform Control in XYZ Frame
close all
clear variables
ShoulderAngledeg = 40;
ElbowAngledeg = 5;
RotatorCuffAngledeg = 20;
ShoulderAngle = ShoulderAngledeg/180*pi;
ElbowAngle = ElbowAngledeg/180*pi; % Elbow Angle is Measured CCW from Shoulder Angle
RotatorCuffAngle = RotatorCuffAngledeg/180*pi; % Rotator Cuff Angle is measured counterclockwise from 
L1 = 20;
L2 = 25;

[ElbowStart, ArmStart] = CalcArmPos3d([ShoulderAngle; ElbowAngle; RotatorCuffAngle], L1, L2);
figure()
axis equal
hold on
plot3([0, ElbowStart(1)], [0, ElbowStart(2)], [0, ElbowStart(3)])
view(45, 45)
plot3([ElbowStart(1),ArmStart(1)], [ElbowStart(2), ArmStart(2)], [ElbowStart(3), ArmStart(3)]);
legend('Upper Arm', 'Lower Arm')
ArmEnd = [20; 10; 20];
numpoints = 1000;
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
% Pointstocontroltox = linspace(Armstart(1), Armend(1), numpoints);
% Pointstocontroltoy = linspace(Armstart(2), Armend(2), numpoints);
% ControlPoints = MakeIanSux(start, width, height)
ControlPoints = [Pointstocontroltox; Pointstocontroltoy; Pointstocontroltoz];

%% Do the control and dynamic simulation
timestep = .1;
limitangchange = 2*pi/108;
ElbowPos(:, 1) = ElbowStart;
ArmPos(:, 1) = ArmStart;
for i = 2:numpoints
    % Figure Out What Control Should Be
    Lastxy = ControlPoints(:, i-1);
    Nextxy = ControlPoints(:, i);
    deltaXY = Nextxy - Lastxy; % This is effectively the velocity vector we want the arm to follow
    % Calculate Jacobian of Arm Position With Respect to Motor Commands

    MotorPosTemp = MotorPos(:, i-1);
    ArmPosStep = ArmPos(:, i-1);
    ElbowPosStep = ElbowPos(:, i-1);
    %while norm(ArmPosStep-ControlPoints(:, i))>.5
        theta = MotorPosTemp(1); phi = MotorPosTemp(2); psi = MotorPosTemp(3);
        JacMat = CalcMotorJacobian3d(theta, phi, psi, L1, L2);
        deltaanglecommands = inv(JacMat)*deltaXY;
        deltaanglecommands(1) = min([deltaanglecommands(1), limitangchange]);
        deltaanglecommands(2) = min([deltaanglecommands(2), limitangchange]);
        deltaanglecommands(3) = min([deltaanglecommands(3), limitangchange]);
        % Update Dynamics to Show where the arm is now
        MotorPosTemp = MotorPosTemp + deltaanglecommands%*timestep;
        [ElbowPosStep, ArmPosStep] = CalcArmPos3d(MotorPosTemp, L1, L2);
    %end
    fprintf('Step %d out of $d\n', i, numpoints)
    MotorPos(:, i) = MotorPosTemp;
    ElbowPos(:, i) = ElbowPosStep;
    ArmPos(:, i) = ArmPosStep;
    
end
while norm(ArmPosStep-ControlPoints(:, i))>.5
        % Figure Out What Control Should Be
    Lastxy = ArmPos(:, end);
    Nextxy = ControlPoints(:, i);
    deltaXY = Nextxy - Lastxy; % This is effectively the velocity vector we want the arm to follow
    % Calculate Jacobian of Arm Position With Respect to Motor Commands

    MotorPosTemp = MotorPos(:, end);
    ArmPosStep = ArmPos(:, end);
    ElbowPosStep = ElbowPos(:, end);
    %while norm(ArmPosStep-ControlPoints(:, i))>.5
        theta = MotorPosTemp(1); phi = MotorPosTemp(2); psi = MotorPosTemp(3);
        JacMat = CalcMotorJacobian3d(theta, phi, psi, L1, L2);
        deltaanglecommands = inv(JacMat)*deltaXY;
        deltaanglecommands(1) = min([deltaanglecommands(1), limitangchange]);
        deltaanglecommands(2) = min([deltaanglecommands(2), limitangchange]);
        deltaanglecommands(3) = min([deltaanglecommands(3), limitangchange]);
        % Update Dynamics to Show where the arm is now
        MotorPosTemp = MotorPosTemp + deltaanglecommands%*timestep;
        [ElbowPosStep, ArmPosStep] = CalcArmPos3d(MotorPosTemp, L1, L2);
    %end
    fprintf('Step %d out of $d\n', i, numpoints)
    MotorPos = [MotorPos, MotorPosTemp];
    ElbowPos = [ElbowPos, ElbowPosStep];
    ArmPos = [ArmPos, ArmPosStep];
end
MotorPos(:, end)
figure()
axis equal
hold on
plot3(ControlPoints(1, :), ControlPoints(2, :), ControlPoints(3, :), 'r');

[~, numpoints] = size(ArmPos);
for i = 1:numpoints
    plot3(ArmPos(1, i), ArmPos(2, i), ArmPos(3, i), 'g*')
    % Plot Elbow
      elb = plot3([0, ElbowPos(1, i)], [0, ElbowPos(2, i)], [0, ElbowPos(3, i)], 'm')
    % Plot Forearm
      forearm = plot3([ElbowPos(1, i), ArmPos(1, i)], [ElbowPos(2, i), ArmPos(2, i)], [ElbowPos(3, i), ArmPos(3, i)], 'b')
    pause(.005)
    if i~=numpoints
        delete(elb)
        delete(forearm)
    end

end
