function [] = main(videoFile)
%MAIN Summary of this function goes here
%   Detailed explanation goes here
close all;

%Open pool
if matlabpool('size')>0
    matlabpool close
end
matlabpool open
%Read the video
videoObj = VideoReader(videoFile);

nFrames = videoObj.NumberOfFrames;
profile clear; profile on;


M = videoObj.Height;
N = videoObj.Width;

%For each frame
for i=1:nFrames
    tic;
    frame = read(videoObj,i);
    %Compute foreground
    [foreground] = mog_mex(double(frame),i);
    subplot(121)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(122)
    imshow(foreground,'InitialMagnification','fit');
    title('Foreground');
    t = toc
end

end

