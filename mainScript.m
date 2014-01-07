close all;
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);


videoFile = 'viptraffic.avi';
filter = 1; %Kalman Filter
main(videoFile,filter);