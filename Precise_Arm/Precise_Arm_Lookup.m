function [thetavec, phivec] = Precise_Arm_Lookup()
% Calculate the motor angle to be commanded by the shoulder motor with 
% respect to the upper arm given a desired angle of the elbow with respect
% to the upper arm
L1 = 12;
L2 = 10;
L3 = 3;
L4 = 5;

numpoints = 360;
phivec = linspace(pi/4, 3*pi/4, numpoints);
thetavec = zeros(size(phivec));
for i = 1:numpoints
    phi = phivec(i);
    f = @(y) calcangle(y,phi); %
    theta0 = phi;
    %calcangle(theta0, phi)
    [thetavec(i),~]=fzero(f,theta0);

end
end
function out = calcangle(theta, phi)
    L1 = 12;
    L2 = 12.5;
    L4 = 3;
    L3 = L1+L4-L2;
    out = L3 * sin(theta) + L2*sqrt(1 - ((L1 + L4*cos(phi) - L3*cos(theta))/L2)^2) - L4 * sin(phi);

end