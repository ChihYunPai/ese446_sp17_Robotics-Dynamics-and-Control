function []=RRR_arm(theta1,theta2,theta3,init_theta1,init_theta2,init_theta3,L1,L2,L3,m1,m2,m3,I1,I2,I3,P0)
% Inputs: 
%           theta1, theta2, theta3: angles to rotate (in degree)
%           init_theta1, init_theta2, init_theta3: initial angles (in
%           degree)
%           L1, L2, L3: links length (in meters)
%           m1, m2, m3: links mass .(in kg)
%           I1, I2, I3: Inertia (in kg-m^2)
%           P0: world frame origin

% Use robot manipulator initial angles of 10,20, and 30 degrees respectively.
% Use individual link lengths of 4, 3, and 2 meters respectively.
% Use individual link masses of 20, 15, and 10 kg respectively.
% Use a-axis inertial values of 0.5, 0.2, and 0.1 kg-m2 respectively.

% default parameters
g=9.81;
if nargin<16, P0 = [0;0;0;1];end        % world frame origin
if nargin<15, I3=.1;end                 %(kg-m2)
if nargin<14, I2=.2;end 				%(kg-m2)
if nargin<13, I1=.5;end 				%(kg-m2)
if nargin<12, m3=10;end 				%(kg)
if nargin<11, m2=15;end 				%(kg)
if nargin<10, m1=20;end 				%(kg)
if nargin<9, L3=2;end   				%(meters)
if nargin<8, L2=3;end   				%(meters)
if nargin<7, L1=4;end   				%(meters)
if nargin<6, init_theta3=30;end	 %(degrees)
if nargin<5, init_theta2=20;end  %(degrees)
if nargin<4, init_theta1=10;end  %(degrees)
if nargin<3, theta3=0;end		 %(degrees)
if nargin<2, theta2=0;end		 %(degrees)
if nargin<1, theta1=0;end		 %(degrees)
init_theta=[init_theta1;init_theta2;init_theta3]*pi/180;
theta=[theta1;theta2;theta3]*pi/180;

% calculate symbolic Jacobian
symJacobianRRR();
% calculate numerical Jacobian
numJacobianRRR();
% plot position of RRR 

if any(theta)
    plotNum=20;
    dtheta=theta/plotNum;
    for itr=1:plotNum+1
        current_theta=init_theta+(itr-1)*dtheta;
        plotRRR(current_theta(1),current_theta(2),current_theta(3),L1,L2,L3,P0);
        drawnow
    end
else
    plotRRR(init_theta(1),init_theta(2),init_theta(3),L1,L2,L3,P0);
end
end