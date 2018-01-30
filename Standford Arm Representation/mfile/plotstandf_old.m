function []=plotstanf_old(theta1, theta2, d3, theta4, theta5, theta6,x,y,z,L2)
% Inputs : 
%           theta1 : 
%           theta2 : 
%           d3     :
%           theta4 :
%           theta5 :
%           theta6 :
%           x, y, z: Real world frame position, default [0,0,0]
%           L2     : constant, default L2=1
% Outputs : plot3  : plot 3d-graph of stanford arm's position
if nargin <10
    L2 = 3;
end
if nargin < 9
    z = 0;
end
if nargin < 8
    y = 0;
end
if nargin < 7
    x = 0;
end
P0 = [x;y;z;1]; % Real world frame P_origin

% L: (6x4) Parameters table
L = zeros(6,4); 
%     \   alpha     a		d 		theta  
% i    \____________________________________
L(1,:) = [0    		0		0 		theta1];
L(2,:) = [-pi/2		0		L2		theta2];
L(3,:) = [pi/2 		0		d3		0     ];
L(4,:) = [0    		0		0 		theta4];
L(5,:) = [-pi/2		0		0 		theta5];
L(6,:) = [pi/2 		0		0 		theta6];

% Tranform matrix
T = @(alpha,a,d,theta)[
    cos(theta), 				-sin(theta),                  0, 				a;
 	sin(theta*cos(alpha)), 	cos(theta)*cos(alpha), 	-sin(alpha), 	-sin(alpha)*d;
 	sin(theta)*sin(alpha), 	cos(theta)*sin(alpha), 	 cos(alpha), 	 cos(alpha)*d;
                        0, 						0,            0, 				1	];
Ts = zeros(4,4,6);

for i =1:6
    Ts(:,:,i) = T(L(i,1),L(i,2),L(i,3),L(i,4));
end
Joints = zeros(4,6);
Joints(:,1) = Ts(:,:,1)*P0;
frames = zeros(4,2,6);
frames(:,:,1) = [Ts(:,:,1)*[0;0;0;1],Ts(:,:,1)*[.5;.5;.5;1]];
for i = 2:6
   Joints(:,i) = Ts(:,:,i)*Joints(:,i-1);
   frames(:,:,i) = [Ts(:,:,i)*frames(:,1,i-1),Ts(:,:,i)*frames(:,2,i-1)];
end
Joints = Joints';
Joints(:,4) = [];
lines = zeros(2,3,5);
for i = 1:5
    lines(:,:,i) = [Joints(i,:);Joints(i+1,:)];
end
frame1 = [frames(1:3,1,1)';frames(1:3,2,1)'];
frame2 = [frames(1:3,1,2)';frames(1:3,2,2)'];
frame3 = [frames(1:3,1,3)';frames(1:3,2,3)'];
frame4 = [frames(1:3,1,4)';frames(1:3,2,4)'];
frame5 = [frames(1:3,1,5)';frames(1:3,2,5)'];
frame6 = [frames(1:3,1,6)';frames(1:3,2,6)'];

axis([-10 10 -10 10 -10 10])

plot3(Joints(:,1),Joints(:,2),Joints(:,3),'ko',lines(:,1,1),lines(:,2,1),lines(:,3,1),'b',lines(:,1,2),lines(:,2,2),lines(:,3,2),'m',lines(:,1,3),lines(:,2,3),lines(:,3,3),'c',lines(:,1,4),lines(:,2,4),lines(:,3,4),'r',lines(:,1,5),lines(:,2,5),lines(:,3,5),'g');
grid on
title('Standfor Arm Position Representation'), xlabel('x'), ylabel('y'), zlabel('z'), legend('joints position','line1:joint1 to joint2','line2:joint2 to joint3','line3:joint3 to joint4','line4:joint4 to joint5','line5:joint5 to joint6')
% hold on
% plot3(frame1(:,1),frame1(:,2),frame1(:,3),'k',frame2(:,1),frame2(:,2),frame2(:,3),'k',frame3(:,1),frame3(:,2),frame3(:,3),'k',frame4(:,1),frame4(:,2),frame4(:,3),'k',frame5(:,1),frame5(:,2),frame5(:,3),'k',frame6(:,1),frame6(:,2),frame6(:,3),'k')
end
