function [] = main(videoFile)
%MAIN Summary of this function goes here
%   Detailed explanation goes here

close all;

profile clear; profile on;

%Read the video
videoObj = vision.VideoFileReader(videoFile); %To get the frames (better for MoG)
videoInfoObj = VideoReader(videoFile); %To get video info

%Get video information
nFrames = videoInfoObj.NumberOfFrames;
img0 = read(videoInfoObj);
M = size(img0,1);
N = size(img0,2);
C = size(img0,3);

foregroundDetector = vision.ForegroundDetector('NumGaussians', 5, ...
    'NumTrainingFrames', 50);
%Get parameters
parameters = mog_configure();
K = parameters.K;

%Allocate memory for all the models in a 3D array.
timeModels = zeros(M*N,K+C*K+K,nFrames);

i=0;
%For each frame
while ~isDone(videoObj)
    i = i+1;
    tic;
    frame = step(videoObj);
    %Compute foreground
    [foreground,background,model] = mog_batch(single(frame),parameters);
%     profile viewer;
%     pause;
    timeModels(:,:,i) = model;
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

