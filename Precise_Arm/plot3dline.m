function plot3dline(Line)
% Line of the format [x1, y1, z1]; [x2, y2, z2]
plot3([Line(1, 1), Line(2, 1)], [Line(1, 2), Line(2, 2)], [Line(1, 3), Line(2, 3)])