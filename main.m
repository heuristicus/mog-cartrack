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
%timeModels = zeros(M*N,K+C*K+K,nFrames);

%Allocate figures
% figure, initial_handle=axes; %For the initial image and MoG
% figure, fore_handle = axes; %For the processed foreground
% figure, result_handle = axes; %For the result image

% if using the particle filter, initialise it with the models and particle
% numbers before starting the video
if filter
    params = pf_defaults();
    pf = pf_class(params.nparticles,params.process_noise, params.measurement_noise);
end

i=0;
%For each frame
handle=figure

% writerObj = VideoWriter('carvideo.avi');
% writerObj.FrameRate = 5;
% open(writerObj)

while ~isDone(videoObj)
    
    i = i+1;
    tic;
    frame = step(videoObj);
    %Compute foreground
    [foreground,background,model] = mog_batch(single(frame),parameters);
    %     profile viewer;
    %     pause;
    %timeModels(:,:,i) = model;

    t = toc;
    
    display(sprintf('Time MoG: %.3f',t));
    
    subplot(221)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(222)
    imshow(foreground,'InitialMagnification','fit');
    title('Foreground')
    %     title(sprintf('Foreground (t= %f s)',t));
    
    %% Morphology
    foreground = morphology(foreground);
    subplot(223)
    imshow(foreground);
    title('Processed foreground');
    
    %% Blob extraction
    %We output the bounding box and the centroid. Also, we filter those
    %blobs which are too small
    BLOB_SIZE_MIN = round((N/20)^2); %in pixels
    BLOB_SIZE_MAX = round((N/2)^2); %in pixels
    
    blobDetector = vision.BlobAnalysis('BoundingBoxOutputPort', true, 'CentroidOutputPort', true,...
        'AreaOutputPort', false,'MinimumBlobArea', BLOB_SIZE_MIN,'MaximumBlobArea',BLOB_SIZE_MAX,...
        'ExcludeBorderBlobs',true);
    [centroid,bbox] = step(blobDetector, logical(foreground)); %[Mx4,Mx2]
    
%         blobs = insertShape(frame,'Rectangle',[bbox],'Color','blue');
%         blobs = insertShape(blobs,'Circle',[centroid 2*ones(size(centroid,1),1)],'Color','green');
%         figure
%         imshow(blobs)
%     
    
    if filter
        [trackedObjects] = pf.pf_step(1, centroid, bbox);

    else
        if ~isempty(centroid)
            measurements = [double(centroid') ; double((bbox(:,3:4))')]; %4xM
            
            % Tracking of vehicles
            params = kf_config();
            [trackedObjects] = tracking_kf(measurements,params); %6xM
        else
            trackedObjects = [];
        end
    end
    
    if isempty(trackedObjects)
        processedFrame=frame;
    else
        %For displaying purposes, transform the centroid to the top-left
        %corner by subtracting the width and height
        modifiedCentres = trackedObjects(1:2,:)-trackedObjects(3:4,:)/2;
        processedFrame = insertShape(frame,'Rectangle',[modifiedCentres' trackedObjects(3:4,:)'],'Color','red');
        processedFrame = insertShape(processedFrame,'Circle',[trackedObjects(1:2,:)' 2 * ones(size(trackedObjects,2),1)],'Color','green');
        processedFrame = insertShape(processedFrame,'Line',[trackedObjects(1:2,:)' (trackedObjects(1:2,:) + trackedObjects(5:6,:)*5)'],'Color','green');
%         processedFrame =
%         insertMarker(processedFrame,pf.S(1:2,:)','o','Size',1); %Show
%         particles
    end
    
%     writeVideo(writerObj,processedFrame)
    
    %% Show the result
    subplot(224)
    imshow(processedFrame);
    title(sprintf('Tracked vehicles, frame %d',i));
    
    t2 = toc;
    display(sprintf('Time per frame: %.3f s',t2));
%     pause(0.1)
    pause;
end

%close(writerObj)

end

