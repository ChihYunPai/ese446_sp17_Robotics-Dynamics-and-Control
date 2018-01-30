syms theta1 theta2 d3 theta4 theta5 theta6 L1 L2 L4 L5 L6;
q = [theta1, theta2, d3, theta4, theta5, theta6]';
P0 = [0;0;0;1]; % world frame origin
% L: (6x4) Parameters table
L = sym('L',[6 4]);
%     \   alpha     a       d       theta  
% i    \____________________________________
L(1,:) = [0         0       L1      theta1];
L(2,:) = [-pi/2     0       L2      theta2];
L(3,:) = [pi/2      0       d3      0     ];
L(4,:) = [0         0       L4      theta4];
L(5,:) = [-pi/2     0       L5      theta5];
L(6,:) = [pi/2      0       L6      theta6];

T = @(alpha,a,d,theta)[
    cos(theta), 				-sin(theta),                  0, 				a;
 	sin(theta*cos(alpha)), 	cos(theta)*cos(alpha), 	-sin(alpha), 	-sin(alpha)*d;
 	sin(theta)*sin(alpha), 	cos(theta)*sin(alpha), 	 cos(alpha), 	 cos(alpha)*d;
                        0, 						0,            0, 				1	];

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

P1 = T01*P0;
P2 = T02*P0;
P3 = T03*P0;
P4 = T04*P0;
P5 = T05*P0;
P6 = T06*P0;

R01 = T01(1:3,1:3);
R02 = T02(1:3,1:3);
R03 = T03(1:3,1:3);
R04 = T04(1:3,1:3);
R05 = T05(1:3,1:3);
R06 = T06(1:3,1:3);

z = [0;0;1];
z01 = R01'*z;
z02 = R02'*z;
z03 = R03'*z;
z04 = R04'*z;
z05 = R05'*z;
z06 = R06'*z;

% Basic Jacobian 
J0 = [diff(P1(1:3),theta1), diff(P2(1:3),theta2), diff(P3(1:3),d3), diff(P4(1:3),theta4), diff(P5(1:3),theta5), diff(P6(1:3),theta6); z01, z02, 0, z04, z05, z06]
J1 = [R01, zeros(3,3);zeros(3,3), R01]*J0
J2 = [R02, zeros(3,3);zeros(3,3), R02]*J0
J3 = [R03, zeros(3,3);zeros(3,3), R03]*J0
J4 = [R04, zeros(3,3);zeros(3,3), R04]*J0
J5 = [R05, zeros(3,3);zeros(3,3), R05]*J0
J6 = [R06, zeros(3,3);zeros(3,3), R06]*J0
