function [] = main(videoFile)
%MAIN Summary of this function goes here
%   Detailed explanation goes here
close all;
profile clear; profile on;

%Open pool
if matlabpool('size')>0
    matlabpool close
end
matlabpool open

%Read the video
videoObj = VideoReader(videoFile);
nFrames = videoObj.NumberOfFrames;

%For each frame
for i=1:nFrames
    tic;
    frame = read(videoObj,i);
    %Compute foreground
    [foreground,background] = mog_mex(double(frame),i);
    subplot(131)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(132)
    imshow(foreground,'InitialMagnification','fit');
    title('Foreground');
    subplot(133)    
    imshow(background,'InitialMagnification','fit');
    title('Background');
    t = toc
    
    %TO DO: blob detection and vehicle tracking
end

end

