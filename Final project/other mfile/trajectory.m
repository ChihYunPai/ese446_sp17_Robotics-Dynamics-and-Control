function [TimeLineTable]=CreatTimeTable()
TimeLineTable=[0,0,0,90;2,30,-10,70;4,45,130,-85;6,150,10,70;8,180,0,-90];
T=TimeLineTable(:,1);

joint1=spline(T,[0, TimeLineTable(:,2)', 0]);
joint2=spline(T,[0, TimeLineTable(:,3)', 0]);
joint3=spline(T,[0, TimeLineTable(:,4)', 0]);
Ts=min(T):.01:max(T);
% figure(1)
% plot(Ts,ppval(joint1,Ts),'r',Ts,ppval(joint2,Ts),'g',Ts,ppval(joint3,Ts),'b');hold on
% title('path trajectory plot');xlabel('Time (sec)');ylabel('\theta (degree)');legend('\theta_1','\theta_2','\theta_3');
% plot(T,TimeLineTable(:,2),'ro',T,TimeLineTable(:,3),'go',T,TimeLineTable(:,4),'bo');
TimeLineTable=[Ts',ppval(joint1,Ts)',ppval(joint2,Ts)',ppval(joint3,Ts)'];
end