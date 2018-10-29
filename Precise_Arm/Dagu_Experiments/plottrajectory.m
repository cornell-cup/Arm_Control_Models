close all;
d = 1;
t = linspace(0, d, 1000);

y = (10 * (t/d).^3 - 15 * (t/d).^4 + 6 * (t/d).^5);
y2 = -1/2*cos(t*pi)+.5
plot (t, y);
hold on
plot (t, y2);