close all;
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);


videoFile = 'viptraffic.mp4';
filter = 0; %KF = 0, PF = 1
writeToFile = 0;
filename = 'visionKF';
verbose=0;
RESIZE = 1;%1 = No resizing, 0.5 = image resized to a half
main(videoFile,filter,RESIZE,writeToFile,filename,verbose);