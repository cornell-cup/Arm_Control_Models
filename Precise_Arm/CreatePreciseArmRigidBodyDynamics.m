robot = robotics.RigidBodyTree('Dataformat','column','MaxNumBodies',7);
bodyNames = {'b1','b2', 'b3', 'b4'};
parentNames = {'base','base', 'b1', 'b2'};
jointNames = {'j1','j2', 'j3', 'j4'};
jointTypes = {'fixed','fixed', 'revolute', 'revolute'};
fixedTforms = { trvec2tform([0 -2 5]), ... % Upper Arm Servo Location
                trvec2tform([0 2 5]),...
                trvec2tform([0 -2 27]),...
                trvec2tform([0 2 27])};
for k = 1:length(bodyNames)

    b = robotics.RigidBody(bodyNames{k});
    b.Joint = robotics.Joint(jointNames{k},jointTypes{k});
    
    if ~strcmp(jointTypes{k},'fixed')
        b.Joint.JointAxis = [0 1 0];
    end
    
    b.Joint.setFixedTransform(fixedTforms{k});
    
    robot.addBody(b,parentNames{k});
end
% bn = 'handle';
% b = robotics.RigidBody(bn);
% b.Joint.setFixedTransform(trvec2tform([0 -0.15 0]));
% robot.addBody(b,'b6');
% gik = robotics.GeneralizedInverseKinematics('RigidBodyTree',robot);
% gik.ConstraintInputs = {'position',...  % Position constraint for closed-loop mechanism
%                         'position',...  % Position constraint for end-effector 
%                         'joint'};       % Joint limits
% gik.SolverParameters.AllowRandomRestart = false;
% 
% % Position constraint 1
% positionTarget1 = robotics.PositionTarget('b6','ReferenceBody','b3');
% positionTarget1.TargetPosition = [0 -0.1 0];
% positionTarget1.Weights = 50;
% positionTarget1.PositionTolerance = 1e-6;
% 
% % Joint limit bounds
% jointLimBounds = robotics.JointPositionBounds(gik.RigidBodyTree);
% jointLimBounds.Weights = ones(1,size(gik.RigidBodyTree.homeConfiguration,1))*10;
% 
% % Position constraint 2
% desiredEEPosition = [0.9 -0.1 0.9]'; % Position is relative to base.
% positionTarget2 = robotics.PositionTarget('handle');
% positionTarget2.TargetPosition = desiredEEPosition; 
% positionTarget2.PositionTolerance = 1e-6;
% positionTarget2.Weights = 1;
% iniGuess = homeConfiguration(robot);
% [q, solutionInfo] = gik(iniGuess,positionTarget1,positionTarget2,jointLimBounds);
% 
% 
% loopClosingViolation = solutionInfo.ConstraintViolations(1).Violation;
% jointBndViolation = solutionInfo.ConstraintViolations(2).Violation;
% eePositionViolation = solutionInfo.ConstraintViolations(3).Violation;

subplot(1,2,1)
show(robot,homeConfiguration(robot));
title('Home Configuration')
view([0 -1 0]);
% subplot(1,2,2)
% show(robot,q);
% title('GIK Solution')
% view([0 -1 0]);
