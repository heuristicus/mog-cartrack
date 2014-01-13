close all;
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);

%Configuration
videoFile = 'viptraffic.mp4'; %Input video file
filter = 0; %KF = 0, PF = 1
writeToFile = 0; %0 = no, 1 = yes
filename = 'visionKF'; %name of the output video file
verbose=0; %1 = display particles
RESIZE = 1; %1 = No resizing, 0.5 = image resized to a half, etc

%Execution
main(videoFile,filter,RESIZE,writeToFile,filename,verbose);