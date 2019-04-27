%% Start in Just XY Frame
close all
clear variables
ShoulderAngledeg = 0;
ElbowAngledeg = 5;
ShoulderAngle = ShoulderAngledeg/180*pi;
ElbowAngle = ElbowAngledeg/180*pi; % Elbow Angle is Measured CCW from Shoulder Angle
L1 = 20;
L2 = 25;

[ElbowStart, Armstart] = CalcArmPos([ShoulderAngle; ElbowAngle], L1, L2);
figure()
axis equal
hold on
plot([0, ElbowStart(1)], [0, ElbowStart(2)])
plot([ElbowStart(1),Armstart(1)], [ElbowStart(2), Armstart(2)]);
legend('Upper Arm', 'Lower Arm')
Armend = [12; 5];
numpoints = 1000;
MotorPos(:, 1) = [ShoulderAngle; ElbowAngle];

%% Create the Path to Travel Along
magchangex = Armend(1) - Armstart(1);
magchangey = Armend(2) - Armstart(2);
for j = 1:numpoints
    t = j/numpoints; % Function has to equal 1 when t is maxed out
    Pointstocontroltox(j) = t*magchangex + Armstart(1);
    Pointstocontroltoy(j) = t*magchangey + Armstart(2);
end
% Pointstocontroltox = linspace(Armstart(1), Armend(1), numpoints);
% Pointstocontroltoy = linspace(Armstart(2), Armend(2), numpoints);
% ControlPoints = MakeIanSux(start, width, height)
ControlPoints = [Pointstocontroltox; Pointstocontroltoy];

%% Do the control and dynamic simulation
timestep = .01;
ElbowPos(:, 1) = ElbowStart;
ArmPos(:, 1) = Armstart;
for i = 2:numpoints
    % Figure Out What Control Should Be
    Lastxy = ControlPoints(:, i-1);
    Nextxy = ControlPoints(:, i);
    deltaXY = Nextxy - Lastxy; % This is effectively the velocity vector we want the arm to follow
    % Calculate Jacobian of Arm Position With Respect to Motor Commands
    theta = MotorPos(1, i-1); phi = MotorPos(2, i-1);
    JacMat = CalcMotorJacobian(theta, phi, L1, L2);
    deltaanglecommands = inv(JacMat)*deltaXY;
    
    % Update Dynamics to Show where the arm is now
    MotorPos(:, i) = MotorPos(:, i-1) + deltaanglecommands;
    [ElbowPosStep, ArmPosStep] = CalcArmPos(MotorPos(:, i), L1, L2);
    ElbowPos(:, i) = ElbowPosStep;
    ArmPos(:, i) = ArmPosStep;
    
end
MotorPos(:, end)
figure()
axis equal
hold on
plot(ControlPoints(1, :), ControlPoints(2, :), 'r');

for i = 1:numpoints
    plot(ArmPos(1, i), ArmPos(2, i), 'g*')
    % Plot Elbow
      elb = plot([0, ElbowPos(1, i)], [0, ElbowPos(2, i)], 'm')
    % Plot Forearm
      forearm = plot([ElbowPos(1, i), ArmPos(1, i)], [ElbowPos(2, i), ArmPos(2, i)], 'b')
    pause(.005)
    if i~=numpoints
        delete(elb)
        delete(forearm)
    end

end
