function [] = main(videoFile,filter)
%MAIN Summary of this function goes here
%   Detailed explanation goes here
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

%Allocate figures
% figure, initial_handle=axes; %For the initial image and MoG
% figure, fore_handle = axes; %For the processed foreground
% figure, result_handle = axes; %For the result image


i=0;
%For each frame
while ~isDone(videoObj)
    close all;
    
    i = i+1;
    tic;
    frame = step(videoObj);
    %Compute foreground
    [foreground,background,model] = mog_batch(single(frame),parameters);
%     profile viewer;
%     pause;
    timeModels(:,:,i) = model;
    t = toc;

    display(sprintf('Time MoG: %.3f',t));
    
    figure;
    subplot(121)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(122)
    imshow(foreground,'InitialMagnification','fit');
    title('Foreground')
%     title(sprintf('Foreground (t= %f s)',t));
    
    %% Morphology
    foreground = morphology(foreground);
    figure;
    imshow(foreground);
    title('Processed foreground');
    
    %% Blob extraction    
    %We output the bounding box and the centroid. Also, we filter those
    %blobs which are too small
    BLOB_SIZE_MIN = 100; %in pixels
    blobDetector = vision.BlobAnalysis('BoundingBoxOutputPort', true, 'CentroidOutputPort', true,...
        'AreaOutputPort', false,'MinimumBlobArea', BLOB_SIZE_MIN);
    [centroid,bbox] = step(blobDetector, logical(foreground)); %[Mx4,Mx2]
    
    if ~isempty(centroid)
        measurements = [double(centroid') ; double((bbox(:,3:4))')]; %4xM

        %% Tracking of vehicles
        switch filter
            case 0 % Kalman Filter
                params = kf_config();
                [trackedObjects] = tracking_kf(measurements,params); %6xM
            case 1 % Particle Filter            
        end
        %For displaying purposes, transform the centroid to the top-left
        %corner by subtracting the width and height
        trackedObjects(1:2,:) = trackedObjects(1:2,:)-trackedObjects(3:4,:)/2; 
        %% Display over the image
        %Bounding box
        processedFrame = insertShape(frame,'Rectangle',(trackedObjects(1:4,:))','Color','red');
        %Centroid 

        %Velocity
    else %No vehicles => just show frame
        processedFrame = frame;
    end    
    %% Show the result
    figure;
    imshow(processedFrame);
    title(sprintf('Tracked vehicles, frame %d',i));
    
    t2 = toc;
    display(sprintf('Time per frame: %.3f s',t2));
    pause;
end

end

