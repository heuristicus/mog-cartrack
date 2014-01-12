function [] = main(videoFile,filter)
%MAIN Summary of this function goes here
%   Detailed explanation goes here
profile clear; profile on;

%Read the video
tic;
videoObj = vision.VideoFileReader(videoFile); %To get the frames (better for MoG)
tv1 = toc;
tic;
videoInfoObj = VideoReader(videoFile); %To get video info
tv2 = toc;
display(sprintf('Time 1: %.3f s, Time 2: %.3f s',tv1,tv2));

%Get video information
nFrames = videoInfoObj.NumberOfFrames;
img0 = read(videoInfoObj);
M = size(img0,1);
N = size(img0,2);
C = size(img0,3);
RESIZE = 1; %1 = No resizing, 0.5 = image resized to a half
% array for the processing times
tms=[];

%Get parameters
parameters = mog_configure();

% if using the particle filter, initialise it with the models and particle
% numbers before starting the video
if filter
    params = pf_defaults();
    pf = pf_class(params.nparticles,params.process_noise, params.measurement_noise);
end

i=0;

%For each frame
figure;
% writerObj = VideoWriter('carvideo.avi');
% writerObj.FrameRate = 5;
% open(writerObj)

while ~isDone(videoObj)
    i = i+1;
%     tic;
    frame = step(videoObj);
    if RESIZE ~= 1
       frame = imresize(frame,RESIZE); 
    end

    %Compute foreground
    [foreground0] = mog_batch(single(frame),parameters);

% 
%     t = toc;
%     
%     display(sprintf('Time MoG: %.3f',t));
    
    foreground = morphology(foreground0);

    tic;
    %% Blob extraction
    %We output the bounding box and the centroid. Also, we filter those
    %blobs which are too small
    BLOB_SIZE_MIN = round((N/20)^2); %in pixels
    BLOB_SIZE_MAX = round((N/2)^2); %in pixels
    
    blobDetector = vision.BlobAnalysis('BoundingBoxOutputPort', true, 'CentroidOutputPort', true,...
        'AreaOutputPort', false,'MinimumBlobArea', BLOB_SIZE_MIN,'MaximumBlobArea',BLOB_SIZE_MAX);
    [centroid,bbox] = step(blobDetector, logical(foreground)); %[Mx4,Mx2]
    
%         blobs = insertShape(frame,'Rectangle',[bbox],'Color','blue');
%         blobs = insertShape(blobs,'Circle',[centroid 2*ones(size(centroid,1),1)],'Color','green');
%         figure
%         imshow(blobs)
%     
    %tic;
    if filter
        [trackedObjects] = pf.pf_step(1, centroid, bbox);

    else
        if ~isempty(centroid)
            measurements = [double(centroid') ; double((bbox(:,3:4))')]; %4xM
            
            % Tracking of vehicles
            params = kf_config();
            [trackedObjects] = tracking_kf(measurements,params,M,N); %6xM
        else
            trackedObjects = [];
        end
    end
        size(trackedObjects)
%     tfilter = toc;
%     fprintf('Filter time: %.3f\n',tfilter);
%     tms = [tms tfilter];
    
    if isempty(trackedObjects)
        processedFrame=frame;
    else
        %For displaying purposes, transform the centroid to the top-left
        %corner by subtracting the width and height
        modifiedCentres = trackedObjects(1:2,:)-trackedObjects(3:4,:)/2;
        
        if filter
            processedFrame = insertMarker(frame,pf.S(1:2,:)','o','Size',1,'color','blue'); %Show particles
        else
            processedFrame = frame;
        end
        processedFrame = insertShape(processedFrame,'Rectangle',[modifiedCentres' trackedObjects(3:4,:)'],'Color','red');
        processedFrame = insertShape(processedFrame,'Circle',[trackedObjects(1:2,:)' 2 * ones(size(trackedObjects,2),1)],'Color','green');
        processedFrame = insertShape(processedFrame,'Line',[trackedObjects(1:2,:)' (trackedObjects(1:2,:) + trackedObjects(5:6,:)*5)'],'Color','green');

    end
    
%     writeVideo(writerObj,processedFrame)
    
    % Show the result
    figure(1);
    subplot(221)
    imshow(frame);
    title(sprintf('Frame %d',i));
    subplot(222)
    imshow(foreground0,'InitialMagnification','fit');
    title('Foreground')
    % Morphology
    subplot(223)
    imshow(foreground);
    title('Processed foreground');
    subplot(224)
    imshow(processedFrame);
    title(sprintf('Tracked vehicles, frame %d',i));
%     profile viewer
    pause(0.1)
    
    
end

fprintf('average processing time per frame: %.3f s\n', mean(tms));

%close(writerObj)

end

