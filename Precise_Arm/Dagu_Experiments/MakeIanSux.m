stIx = 0;
stIy = 0;

%% Letter I
topline = [stIx, stIx+5; stIy, stIy];
midtopline = [stIx+5, stIx+2.5; stIy, stIy];
linedown = [stIx+2.5, stIx+2.5; stIy, stIy-10];
leftbottomline = [stIx+2.5, stIx; stIy-10, stIy-10];
rightbottomline = [stIx, stIx+5; stIy-10, stIy-10];
Letters(:, :, 1) = topline;
Letters(:, :, 2) = midtopline;
Letters(:, :, 3) = linedown;
Letters(:, :, 4) = leftbottomline;
Letters(:, :, 5) = rightbottomline;
%% Letter A
stAx = stIx + 10;
stAy = stIy -10;
nodes = [stAx, stAy;
         stAx+2.5, stAy+10;
         stAx+5, stAy;
         stAx+3.75, stAy+5;
         stAx+1.25, stAy+5];
Letters=(makelinesbetweennodes(nodes))

[~, ~, numlines] = size(Letters);
figure()
hold on
for j = 1:numlines
    plot(Letters(1, :, j), Letters(2, :, j), 'g');
end