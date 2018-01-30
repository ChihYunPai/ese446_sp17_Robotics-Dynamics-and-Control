function plotRRR(theta1,theta2,theta3,L1,L2,L3,P0)
% default parameters setting
if nargin<7, P0=[0;0;0;1];end
if nargin<6, L3=2;end
if nargin<5, L2=3;end
if nargin<4, L1=4;end
if nargin<3, theta3=0;end
if nargin<2, theta2=0;end
if nargin<1, theta1=0;end

% L: (6x4) Parameters table
L = zeros(4,4); 
%     \   alpha     a		d 		theta  
% i    \____________________________________
L(1,:) = [0     	0		0 		theta1];
L(2,:) = [0         L1		0		theta2];
L(3,:) = [0         L2		0		theta3];
L(4,:) = [0         L3		0 		0     ];

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

T02 = T01*T12;
T03 = T02*T23;
T04 = T03*T34;
joint1 = T01*P0;
joint2 = T02*P0;
joint3 = T03*P0;
joint4 = T04*P0;
% frame0x = [1;0;0;1];
% frame0y = [0;1;0;1];
% frame0z = [0;0;1;1];
% frame1x = (T01*frame0x)';
% frame1y = (T01*frame0y)';
% frame1z = (T01*frame0z)';
% frame2x = (T02*frame0x)';
% frame2y = (T02*frame0y)';
% frame2z = (T02*frame0z)';
% frame3x = (T03*frame0x)';
% frame3y = (T03*frame0y)';
% frame3z = (T03*frame0z)';
% frame4x = (T04*frame0x)';
% frame4y = (T04*frame0y)';
% frame4z = (T04*frame0z)';
% frame1x = [joint1(1:3)';frame1x(1:3)];
% frame1y = [joint1(1:3)';frame1y(1:3)];
% frame1z = [joint1(1:3)';frame1z(1:3)];
% frame2x = [joint2(1:3)';frame2x(1:3)];
% frame2y = [joint2(1:3)';frame2y(1:3)];
% frame2z = [joint2(1:3)';frame2z(1:3)];
% frame3x = [joint3(1:3)';frame3x(1:3)];
% frame3y = [joint3(1:3)';frame3y(1:3)];
% frame3z = [joint3(1:3)';frame3z(1:3)];
% frame4x = [joint4(1:3)';frame4x(1:3)];
% frame4y = [joint4(1:3)';frame4y(1:3)];
% frame4z = [joint4(1:3)';frame4z(1:3)];

hold off
figure(1)
theta1=sprintf('%d',round(theta1*180/pi));
theta2=sprintf('%d',round(theta2*180/pi));
theta3=sprintf('%d',round(theta3*180/pi));
str=sprintf('(%s,%s,%s)',theta1,theta2,theta3);

plot3([joint2(1);joint1(1)],[joint2(2);joint1(2)],[joint2(3);joint1(3)],'b','LineWidth',2);hold on
plot3([joint3(1);joint2(1)],[joint3(2);joint2(2)],[joint3(3);joint2(3)],'b','LineWidth',2);hold on
plot3([joint4(1);joint3(1)],[joint4(2);joint3(2)],[joint4(3);joint3(3)],'b','LineWidth',2);hold on
plot3(joint1(1),joint1(2),joint1(3),'ko',joint2(1),joint2(2),joint2(3),'ko',joint3(1),joint3(2),joint3(3),'ko',joint4(1),joint4(2),joint4(3),'ko');hold on
grid on
% plot3(frame1x(:,1),frame1x(:,2),frame1x(:,3),'r');hold on
% plot3(frame1y(:,1),frame1y(:,2),frame1y(:,3),'g');hold on
% plot3(frame1z(:,1),frame1z(:,2),frame1z(:,3),'k');hold on
% plot3(frame2x(:,1),frame2x(:,2),frame2x(:,3),'r');hold on
% plot3(frame2y(:,1),frame2y(:,2),frame2y(:,3),'g');hold on
% plot3(frame2z(:,1),frame2z(:,2),frame2z(:,3),'k');hold on
% plot3(frame3x(:,1),frame3x(:,2),frame3x(:,3),'r');hold on
% plot3(frame3y(:,1),frame3y(:,2),frame3y(:,3),'g');hold on
% plot3(frame3z(:,1),frame3z(:,2),frame3z(:,3),'k');hold on
% plot3(frame4x(:,1),frame4x(:,2),frame4x(:,3),'r');hold on
% plot3(frame4y(:,1),frame4y(:,2),frame4y(:,3),'g');hold on
% plot3(frame4z(:,1),frame4z(:,2),frame4z(:,3),'k');hold on
title({'RRR arm: (\theta_1, \theta_2, \theta_3)=',str,'(degrees)'}), xlabel('x'), ylabel('y'), zlabel('z');
legend('line1:joint1 to joint2','line2:joint2 to joint3','line3:joint3 to joint4','joints position');
axis_max = (max(P0(1:3))+sum([L1,L2,L3]))+1;
axis_min = (min(P0(1:3))-sum([L1,L2,L3]))-1;
axis_value = max([abs(axis_max), abs(axis_min)]);
axis([-axis_value, axis_value, -axis_value, axis_value, -axis_value, axis_value])
end