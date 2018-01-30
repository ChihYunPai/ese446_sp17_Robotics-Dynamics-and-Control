g=9.81;
m1=20;
m2=15;
m3=10;
I1=.5;
I2=.2;
I3=.1;
L1=4;
L2=3;
L3=2;
syms q1 q2 q3 q1dot q2dot q3dot real;
syms tau1 tau2 tau3 f1 f2 f3 real;

theta1=q1;
theta2=q2;
theta3=q3;
theta1dot=q1dot;
theta2dot=q2dot;
theta3dot=q3dot;

M =[...
     I1 + I2 + I3 + m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))^2 + L1^2*m2*sin(theta1)^2 - L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)), I2 + I3 - m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1)) - L1^2*m2*cos(theta1)*sin(theta1) + L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)), I3;...
 I2 + I3 - L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L2*m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)),                                                                                                                            I2 + I3 + L2^2*m3*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2))^2 - L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)), I3;...
                                                                                                                                                                                                                                                              I3,                                                                                                                                                                                                                                                                                                                                       I3, I3];
C =[...
 m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1)) + L1^2*m2*cos(theta1)*sin(theta1) - (L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)))/2 + (L2*m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)))/2, (L2*m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)))/2 - (L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)))/2 - L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)), 0;...
                                                            (L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))^2)/2 - L2^2*m3*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2))^2 + L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + (L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)))/2,                                                                                           (L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))^2)/2 - L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) - (L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)))/2, 0;...
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            0,                                                                                                                                                                                                                                                                                                                                                                                                                       0, 0];
 B =[...
                                                               L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))^2 - L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + 2*L2*m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)), 0, 0;...
 L2^2*m3*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1))^2 - L2^2*m3*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2))^2 + L2*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1))*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L2*m3*(L2*(cos(theta1)*sin(theta2) + cos(theta2)*sin(theta1)) + L1*sin(theta1))*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)), 0, 0;...
                                                                                                                                                                                                                                                                                                                                                                                                         0, 0, 0];
 G =[...
 - g*m3*(L2*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2)) + L1*cos(theta1)) - L1*g*m2*cos(theta1);...
                                           -L2*g*m3*(cos(theta1)*cos(theta2) - sin(theta1)*sin(theta2));...
                                                                                                      0];
 qdd=M\([tau1;tau2;tau3] - C*[theta1dot^2;theta2dot^2;theta3dot^2] - B*[theta1dot*theta2dot;theta1dot*theta3dot;theta2dot*theta3dot] - G - F )