function [J0, J1, J2, J3]=numJacobianRRR(theta1,theta2,theta3,L1,L2,L3,P0)
% numJacobian: calculate numerical Jacobian of RRR robotic arm
% inputs: 
%           theta1, theta2, theta3: angles (in radius)
%           L1, L2, L3: links legnths (in meters)
%           P0: world frame origin
            
if nargin<7, P0=[0;0;0;1];end
if nargin<6, L3=2;end
if nargin<5, L2=3;end
if nargin<4, L1=4;end
if nargin<3, theta3=30;end
if nargin<2, theta2=20;end
if nargin<1, theta1=10;end
% numerical parameters table
L=[...
0,		0,		0,		theta1;...
0,		L1,		0,		theta2;...
0,		L2,		0.		theta3;...
0,		L3,		0,		0			];

T = @(alpha,a,d,theta)[
    cos(theta),				-sin(theta),			0,				a;
 	sin(theta*cos(alpha)), 	cos(theta)*cos(alpha), 	-sin(alpha), 	-sin(alpha)*d;
 	sin(theta)*sin(alpha), 	cos(theta)*sin(alpha),	cos(alpha),		cos(alpha)*d;
                        0, 						0,	0, 				1				];

T01 = T(L(1,1),L(1,2),L(1,3),L(1,4));
T12 = T(L(2,1),L(2,2),L(2,3),L(2,4));
T23 = T(L(3,1),L(3,2),L(3,3),L(3,4));
T34 = T(L(4,1),L(4,2),L(4,3),L(4,4));

T02 = T01*T12;
T03 = T02*T23;
T04 = T03*T34;

P1 = T01*P0;
P2 = T02*P0;
P3 = T03*P0;
P4 = T04*P0;

R01 = T01(1:3,1:3);
R02 = T02(1:3,1:3);
R03 = T03(1:3,1:3);
R04 = T04(1:3,1:3);

z = [0;0;1];
z01 = R01'*z;
z02 = R02'*z;
z03 = R03'*z;
z04 = R04'*z;

% Basic Jacobian
J0 = [	cross(z01,P1(1:3)), 	cross(z01,P2(1:3)), 	cross(z01,P3(1:3));...
        z01, 					z02, 					z03, 						];
J1 = [R01, zeros(3,3);zeros(3,3), R01]*J0;
J2 = [R02, zeros(3,3);zeros(3,3), R02]*J0;
J3 = [R03, zeros(3,3);zeros(3,3), R03]*J0;