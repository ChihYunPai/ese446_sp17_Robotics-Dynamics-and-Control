function plotstanf(theta1,theta2,d3,theta4,theta5,theta6)

P0=[0;0;0;1];
L1 = 2;
L2 = 6;
L4 = 2;
L5 = 2;
L6 = 2;
% L: (6x4) Parameters table
L = zeros(6,4); 
%     \   alpha     a		d 		theta  
% i    \____________________________________
L(1,:) = [pi/2    		0		L1 		theta1];
L(2,:) = [-pi/2         0		L2		theta2];
L(3,:) = [pi/2          0		d3		0     ];
L(4,:) = [0             0		L4 		theta4];
L(5,:) = [-pi/2         0		L5 		theta5];
L(6,:) = [pi/2          0		L6 		theta6];

% Tranform matrix
T = @(alpha,a,d,theta)[
    cos(theta),                 -sin(theta),                  0,                a;
    sin(theta*cos(alpha)),  cos(theta)*cos(alpha),  -sin(alpha),    -sin(alpha)*d;
    sin(theta)*sin(alpha),  cos(theta)*sin(alpha),   cos(alpha),     cos(alpha)*d;
                        0,                      0,            0,                1   ];
T01 = T(L(1,1),L(1,2),L(1,3),L(1,4));
T12 = T(L(2,1),L(2,2),L(2,3),L(2,4));
T23 = T(L(3,1),L(3,2),L(3,3),L(3,4));
T34 = T(L(4,1),L(4,2),L(4,3),L(4,4));
T45 = T(L(5,1),L(5,2),L(5,3),L(5,4));
T56 = T(L(6,1),L(6,2),L(6,3),L(6,4));

T02 = T01*T12;
T03 = T02*T23;
T04 = T03*T34;
T05 = T04*T45;
T06 = T05*T56;
joint1 = T01*P0;
joint2 = T02*P0;
joint3 = T03*P0;
joint4 = T04*P0;
joint5 = T05*P0;
joint6 = T06*P0;
frame0x = [1;0;0;1];
frame0y = [0;1;0;1];
frame0z = [0;0;1;1];
frame1x = (T01*frame0x)';
frame1y = (T01*frame0y)';
frame1z = (T01*frame0z)';
frame2x = (T02*frame0x)';
frame2y = (T02*frame0y)';
frame2z = (T02*frame0z)';
frame3x = (T03*frame0x)';
frame3y = (T03*frame0y)';
frame3z = (T03*frame0z)';
frame4x = (T04*frame0x)';
frame4y = (T04*frame0y)';
frame4z = (T04*frame0z)';
frame5x = (T05*frame0x)';
frame5y = (T05*frame0y)';
frame5z = (T05*frame0z)';
frame6x = (T06*frame0x)';
frame6y = (T06*frame0y)';
frame6z = (T06*frame0z)';
frame1x = [joint1(1:3)';frame1x(1:3)];
frame1y = [joint1(1:3)';frame1y(1:3)];
frame1z = [joint1(1:3)';frame1z(1:3)];
frame2x = [joint2(1:3)';frame2x(1:3)];
frame2y = [joint2(1:3)';frame2y(1:3)];
frame2z = [joint2(1:3)';frame2z(1:3)];
frame3x = [joint3(1:3)';frame3x(1:3)];
frame3y = [joint3(1:3)';frame3y(1:3)];
frame3z = [joint3(1:3)';frame3z(1:3)];
frame4x = [joint4(1:3)';frame4x(1:3)];
frame4y = [joint4(1:3)';frame4y(1:3)];
frame4z = [joint4(1:3)';frame4z(1:3)];
frame5x = [joint5(1:3)';frame5x(1:3)];
frame5y = [joint5(1:3)';frame5y(1:3)];
frame5z = [joint5(1:3)';frame5z(1:3)];
frame6x = [joint6(1:3)';frame6x(1:3)];
frame6y = [joint6(1:3)';frame6y(1:3)];
frame6z = [joint6(1:3)';frame6z(1:3)];


plot3([joint2(1);joint1(1)],[joint2(2);joint1(2)],[joint2(3);joint1(3)],'r');hold on
plot3([joint3(1);joint2(1)],[joint3(2);joint2(2)],[joint3(3);joint2(3)],'b');hold on
plot3([joint4(1);joint3(1)],[joint4(2);joint3(2)],[joint4(3);joint3(3)],'m');hold on
plot3([joint5(1);joint4(1)],[joint5(2);joint4(2)],[joint5(3);joint4(3)],'c');hold on
plot3([joint6(1);joint5(1)],[joint6(2);joint5(2)],[joint6(3);joint5(3)],'k');hold on
plot3(joint1(1),joint1(2),joint1(3),'ko');hold on
plot3(joint2(1),joint2(2),joint2(3),'ko');hold on
plot3(joint3(1),joint3(2),joint3(3),'ko');hold on
plot3(joint4(1),joint4(2),joint4(3),'ko');hold on
plot3(joint5(1),joint5(2),joint5(3),'ko');hold on
plot3(joint6(1),joint6(2),joint6(3),'ko');hold on
grid on

str=sprintf('Standford Arm: theta1=%d,theta2=%d,d3=%d,theta4=%d,theta5=%d,theta6=%d',theta1*180/pi,theta2*180/pi,d3,theta4*180/pi,theta5*180/pi,theta6*180/pi);
title(str), xlabel('x'), ylabel('y'), zlabel('z'), legend('line1:joint1 to joint2','line2:joint2 to joint3','line3:joint3 to joint4','line4:joint4 to joint5','line5:joint5 to joint6','joints position')
plot3(frame1x(:,1),frame1x(:,2),frame1x(:,3),'r');hold on
plot3(frame1y(:,1),frame1y(:,2),frame1y(:,3),'g');hold on
plot3(frame1z(:,1),frame1z(:,2),frame1z(:,3),'k');hold on
plot3(frame2x(:,1),frame2x(:,2),frame2x(:,3),'r');hold on
plot3(frame2y(:,1),frame2y(:,2),frame2y(:,3),'g');hold on
plot3(frame2z(:,1),frame2z(:,2),frame2z(:,3),'k');hold on
plot3(frame3x(:,1),frame3x(:,2),frame3x(:,3),'r');hold on
plot3(frame3y(:,1),frame3y(:,2),frame3y(:,3),'g');hold on
plot3(frame3z(:,1),frame3z(:,2),frame3z(:,3),'k');hold on
plot3(frame4x(:,1),frame4x(:,2),frame4x(:,3),'r');hold on
plot3(frame4y(:,1),frame4y(:,2),frame4y(:,3),'g');hold on
plot3(frame4z(:,1),frame4z(:,2),frame4z(:,3),'k');hold on
plot3(frame5x(:,1),frame5x(:,2),frame5x(:,3),'r');hold on
plot3(frame5y(:,1),frame5y(:,2),frame5y(:,3),'g');hold on
plot3(frame5z(:,1),frame5z(:,2),frame5z(:,3),'k');hold on
plot3(frame6x(:,1),frame6x(:,2),frame6x(:,3),'r');hold on
plot3(frame6y(:,1),frame6y(:,2),frame6y(:,3),'g');hold on
plot3(frame6z(:,1),frame6z(:,2),frame6z(:,3),'k');hold on
axis_max = max([max(joint1),max(joint2),max(joint3),max(joint4),max(joint5),max(joint6)])+1;
axis_min = min([min(joint1),min(joint2),min(joint3),min(joint4),min(joint5),min(joint6)])-1;
axis_value = max([abs(axis_max), abs(axis_min)]);
axis([-axis_value,axis_value,-axis_value,axis_value,-axis_value,axis_value])
end