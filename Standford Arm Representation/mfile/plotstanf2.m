function plotstanf2(theta1,theta2,d3,theta4,theta5,theta6)

P0=[0;0;0;1];
L1 = 1;
L2 = 3;
L4 = 1;
L5 = 1;
L6 = 1;
% L: (6x4) Parameters table
L = zeros(6,4); 
%     \   alpha     a       d       theta  
% i    \____________________________________
L(1,:) = [0         0       L1      theta1];
L(2,:) = [-pi/2     0       L2      theta2];
L(3,:) = [pi/2      0       d3      0     ];
L(4,:) = [0         0       L4      theta4];
L(5,:) = [-pi/2     0       L5      theta5];
L(6,:) = [pi/2      0       L6      theta6];

% T01 = [cos(theta1), -sin(theta1), 0, 0; sin(theta1), cos(theta1), 0 ,0;0, 0, 1, 0;0, 0, 0, 1];
% T12 = [cos(theta2), -sin(theta2), 0, 0;           0, 0, 1, L2;-sin(theta2), cos(theta2), 0, 0;0, 0, 0, 1];
% T23 = [          1,            0, 0, 0;           0, 0, -1, -d3;0, 1, 0, 0;0, 0, 0, 1];
% T34 = [cos(theta4), -sin(theta4), 0, 0; sin(theta4), cos(theta4), 0, 0;0, 0, 1, 0;0, 0, 0, 1];
% T45 = [cos(theta5), -sin(theta5), 0, 0;           0, 0, 1, 0;-sin(theta5), -cos(theta5), 0, 0;0, 0, 0, 1];
% T56 = [cos(theta6), -sin(theta6), 0, 0;           0, 0, -1, 0;sin(theta6), cos(theta6), 0, 0;0, 0, 0, 1];
% Tranform matrix
T = @(alpha,a,d,theta)[
    cos(theta),                 -sin(theta),                  0,                a;
    sin(theta*cos(alpha)),  cos(theta)*cos(alpha),  -sin(alpha),    -sin(alpha)*d;
    sin(theta)*sin(alpha),  cos(theta)*sin(alpha),   cos(alpha),     cos(alpha)*d;
                        0,                      0,            0,                1   ];
Ts     = zeros(4,4,6);
T0i    = zeros(4,4,6);
joints = zeros(4,6);
Ts(:,:,1)   = T(L(1,1),L(1,2),L(1,3),L(1,4));
T0i(:,:,1)  = Ts(:,:,1);
joints(:,1) = T0i(:,:,1)*P0;
for i =2:6
    Ts(:,:,i)   = T(L(i,1),L(i,2),L(i,3),L(i,4));
    T0i(:,:,i)  = Ts(:,:,i)*Ts(:,:,i-1);
    joints(:,i) = T0i(:,:,i)*P0;
end

vl = .3;
frame0 = [vl,0,0;0,vl,0;0,0,vl;1,1,1];
frames = zeros(6,3,6);

for i = 1:6
    frame_temp = (T0i(:,:,i)*frame0(:,1))';
    frames(1:2,:,i) = [joints(1:3,i)';frame_temp(1:3)];
    frame_temp = (T0i(:,:,i)*frame0(:,2))';
    frames(3:4,:,i) = [joints(1:3,i)';frame_temp(1:3)];
    frame_temp = (T0i(:,:,i)*frame0(:,3))';
    frames(5:6,:,i) = [joints(1:3,i)';frame_temp(1:3)];
end

for i = 1:5
    plot3([joints(1,i);joints(1,i+1)],[joints(2,i);joints(2,i+1)],[joints(3,i);joints(3,i+1)],'m');hold on
end
grid on
title('Standfor Arm Position Representation'), xlabel('x'), ylabel('y'), zlabel('z'), legend('line1:joint1 to joint2','line2:joint2 to joint3','line3:joint3 to joint4','line4:joint4 to joint5','line5:joint5 to joint6','joints position')

% for i = 1:6
%     plot3(joints(1,i),joints(2,i),joints(3,i),'ko');hold on
%     plot3(frames(1:2,1,i),frames(1:2,2,i),frames(1:2,3,i),'r');hold on
%     plot3(frames(3:4,1,i),frames(3:4,2,i),frames(3:4,3,i),'g');hold on
%     plot3(frames(5:6,1,i),frames(5:6,2,i),frames(5:6,3,i),'b');hold on
% end

end