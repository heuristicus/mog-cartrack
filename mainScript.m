close all;
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);


videoFile = 'viptraffic.avi';
filter = 0; %Kalman Filter
main(videoFile,filter);