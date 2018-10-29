function ytransmat = MakeYAxisTrans(angledeg)
% Assumes CCW Rotation around Y Axis, angle in degrees
anglerad = angledeg *pi / 180;
ytransmat = [cos(anglerad), 0, -sin(anglerad);
                         0, 1,              0;
             sin(anglerad), 0,  cos(anglerad)];