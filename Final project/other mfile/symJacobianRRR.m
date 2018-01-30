function [qdd,J0,J1,J2,J3]=symJacobianRRR()
% symJacobianRRR: calculate symbolic Jacobian of RRR robotic arm

% symbolic parameters table
syms theta1 theta2 theta3 theta1dot theta2dot theta3dot L1 L2 L3 m1 m2 m3 init_theta1 init_theta2 init_theta3 I1 I2 I3 tau1 tau2 tau3 g f1 f2 f3 real;
P0 = [0;0;0;1]; % world frame origin
L=[...
0,		0,		0,		theta1;...
0,		L1,     0,		theta2;...
0,		L2,     0.		theta3;...
0,		L3,     0,		0			];
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

P1=P1(1:3);
P2=P2(1:3);
P3=P3(1:3);
P4=P4(1:3);

R01 = T01(1:3,1:3);
R02 = T02(1:3,1:3);
R03 = T03(1:3,1:3);
R04 = T04(1:3,1:3);
% z0 = [0;0;1];
% z1=T01(1:3,4);
% z2=T02(1:3,4);
% z3=T03(1:3,4);
% z4=T04(1:3,4);
% z01 = R01*z1;
% z02 = R02*z2;
% z03 = R03*z3;
% z04 = R04*z4;
z01=[0;0;1];
z02=[0;0;1];
z03=[0;0;1];
% Basic Jacobian
J0 = [	cross(z01,P1), 	cross(z01,P2), 	cross(z01,P3);...
        z01, 					z02, 					z03, 						]
J1 = [R01, zeros(3,3);zeros(3,3), R01]*J0
J2 = [R02, zeros(3,3);zeros(3,3), R02]*J0
J3 = [R03, zeros(3,3);zeros(3,3), R03]*J0



Ic1=diag([I1,I1,I1]);
Ic2=diag([I2,I2,I2]);
Ic3=diag([I3,I3,I3]);
Jv1=[diff(P1,theta1), diff(P1,theta2), diff(P1,theta3)];
Jv2=[diff(P2,theta1), diff(P2,theta2), diff(P2,theta3)];
Jv3=[diff(P3,theta1), diff(P3,theta2), diff(P3,theta3)];
Jw1=[z01, zeros(3,1),   zeros(3,1)];
Jw2=[z01, z02,          zeros(3,1)];
Jw3=[z01, z02,          z03       ];
M=m1*Jv1'*Jv1'+m2*Jv2'*Jv2'+m3*Jv3'*Jv3' + Jw1'*Ic1*Jw1+Jw2'*Ic2*Jw2+Jw3'*Ic3*Jw3;

m111=diff(M(1,1),theta1);
m112=diff(M(1,1),theta2);
m113=diff(M(1,1),theta3);
m121=diff(M(1,2),theta1);
m122=diff(M(1,2),theta2);
m123=diff(M(1,2),theta3);
m131=diff(M(1,3),theta1);
m132=diff(M(1,3),theta2);
m133=diff(M(1,3),theta3);
m211=diff(M(2,1),theta1);
m212=diff(M(2,1),theta2);
m213=diff(M(2,1),theta3);
m221=diff(M(2,2),theta1);
m222=diff(M(2,2),theta2);
m223=diff(M(2,2),theta3);
m231=diff(M(2,3),theta1);
m232=diff(M(2,3),theta2);
m233=diff(M(2,3),theta3);
m311=diff(M(3,1),theta1);
m312=diff(M(3,1),theta2);
m313=diff(M(3,1),theta3);
m321=diff(M(3,2),theta1);
m322=diff(M(3,2),theta2);
m323=diff(M(3,2),theta3);
m331=diff(M(3,3),theta1);
m332=diff(M(3,3),theta2);
m333=diff(M(3,3),theta3);

C=[...
m111/2, m122-m221/2, m133-m331/2;...
m211-m112/2, m222/2, m233-m332/2;...
m311-m113/2, (m323+m332-m233)/2, m333/2 ];

B=[...
m112, m113, m123+m132-m231;...
m212+m221-m122, m213+m231-m132, m223;...
m312+m321-m123, m313+m331-m133, m323+m332-m233 ];

F=[f1;f2;f3];
G=-(Jv1'*[0;m1*g;0]+Jv2'*[0;m2*g;0]+Jv3'*[0;m3*g;0]);
qdd=M\([tau1;tau2;tau3] - C*[theta1dot^2;theta2dot^2;theta3dot^2] - B*[theta1dot*theta2dot;theta1dot*theta3dot;theta2dot*theta3dot] - G - F );