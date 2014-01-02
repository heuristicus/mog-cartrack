function [] = main(videoFile)
%MAIN Summary of this function goes here
%   Detailed explanation goes here

close all;

profile clear; profile on;

%Open pool
if matlabpool('size')>0
    matlabpool close
end
% matlabpool open

%Read the video
videoObj = vision.VideoFileReader(videoFile);

foregroundDetector = vision.ForegroundDetector('NumGaussians', 5, ...
    'NumTrainingFrames', 50);
%Get parameters
parameters = mog_configure();
i=0;
%For each frame
while ~isDone(videoObj)
    i = i+1;
    tic;
    frame = step(videoObj);
    %Compute foreground
    [foreground,background] = mog_batch(single(frame),i,parameters);
%     profile viewer;
%     pause;
    t = toc;

    subplot(131)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(132)
    imshow(foreground,'InitialMagnification','fit');
    title(sprintf('Foreground (t= %f s)',t));
    subplot(133)    
    tic
    foreground2 = step(foregroundDetector,frame);
    t2 = toc;
    imshow(foreground2,'InitialMagnification','fit');
    title(sprintf('Foreground MATLAB (t= %f s)',t2));

    pause(0.1);
    %TO DO: blob detection and vehicle tracking
end

end

