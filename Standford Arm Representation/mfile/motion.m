function []=motion()
diff_angle = 2*pi/100;
angles = [0:diff_angle:2*pi];


for i = 1:length(angles)
    plotstanf(angles(i),0,1,0,0,0);
    pause(0.1);
end