function [] = main(videoFile,filter,resize,writeToFile,filename,verbose)
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
% array for the processing times
tms=[];

%Get parameters
parameters = mog_configure();
K = parameters.K;
BLOB_SIZE_MIN = round((N/20)^2); %in pixels
BLOB_SIZE_MAX = round((N/2)^2); %in pixels

% if using the particle filter, initialise it with the models and particle
% numbers before starting the video
if filter
    params = pf_defaults();
    pf = pf_class(params.nparticles,params.process_noise, params.measurement_noise);
end

i=0;

%For each frame
figure;
if writeToFile
    writerObj = VideoWriter(filename);
    writerObj.FrameRate = 5;
    open(writerObj)
end
%To store processing time
timeMoG = zeros(nFrames,1);
timeFilter = zeros(nFrames,1);
totalTime = zeros(nFrames,1);

while ~isDone(videoObj)
    i = i+1;
    totalTic = tic;
    
    frame = step(videoObj);
    if resize ~= 1
       frame = imresize(frame,resize); 
    end

    %Compute foreground
    mogTic = tic;
    [foreground0,model] = mog_batch(single(frame),parameters);
    timeMoG(i) = toc(mogTic);
    
    %Apply morphology
    foreground = morphology(foreground0);

    tic;
    %% Blob extraction
    %We output the bounding box and the centroid. Also, we filter those
    %blobs which are too small
    
    blobDetector = vision.BlobAnalysis('BoundingBoxOutputPort', true, 'CentroidOutputPort', true,...
        'AreaOutputPort', false,'MinimumBlobArea', BLOB_SIZE_MIN,'MaximumBlobArea',BLOB_SIZE_MAX);
    [centroid,bbox] = step(blobDetector, logical(foreground)); %[Mx4,Mx2]
    
    %% Tracking using a filter
    
    if filter %Particle Filter
        filterTic = tic;
        [trackedObjects] = pf.pf_step(1, centroid, bbox);
        timeFilter(i) = toc(filterTic);
    else    %Kalman Filter
        if ~isempty(centroid)
            filterTic = tic;
            measurements = [double(centroid') ; double((bbox(:,3:4))')]; %4xM
            
            % Tracking of vehicles
            params = kf_config();
            [trackedObjects] = tracking_kf(measurements,params,M,N); %6xM
            timeFilter(i) = toc(filterTic);
        else
            trackedObjects = [];
        end
    end
    totalTime(i) = toc(totalTic);
    
    %% Display
    if isempty(trackedObjects)
        processedFrame=frame;
    else
        
        %For displaying purposes, transform the centroid to the top-left
        %corner by subtracting the width and height
        modifiedCentres = trackedObjects(1:2,:)-trackedObjects(3:4,:)/2;
        
        if filter && verbose
            processedFrame = insertMarker(frame,pf.S(1:2,:)','o','Size',1,'color','blue'); %Show particles
        else
            processedFrame = frame;
        end
        processedFrame = insertShape(processedFrame,'Rectangle',[modifiedCentres' trackedObjects(3:4,:)'],'Color','red');
        processedFrame = insertShape(processedFrame,'Circle',[trackedObjects(1:2,:)' 2 * ones(size(trackedObjects,2),1)],'Color','green');
        processedFrame = insertShape(processedFrame,'Line',[trackedObjects(1:2,:)' (trackedObjects(1:2,:) + trackedObjects(5:6,:)*5)'],'Color','green');

    end
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
    title(sprintf('Tracked vehicles, frame %d/%d',i,nFrames));
    pause(0.1);
    
    %% Write processed frame to video file
    if writeToFile 
        %Somehow, the image ends up with negative values
        processedFrame = processedFrame.*(processedFrame>0);
        tmp = processedFrame>1;
        processedFrame(tmp) = 1;
        writeVideo(writerObj,processedFrame)
    end

        
end

%% Display useful info
display(sprintf('Total time: %.4f s',mean(totalTime)));
display(sprintf('MoG time: %.4f s',mean(timeMoG)));
display(sprintf('Filter time: %.4f s',mean(timeFilter)));

if(writeToFile)
    close(writerObj)
end

end

