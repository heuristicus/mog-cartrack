%% test to see whether particles are correctly initialised within the bounding box specified
close all
bbox = [1 5 25 5];
pf = pf_class(100,eye(2),eye(2),[1 5]', bbox);

figure
xy = pf.S(1:2,:);
plot(xy(1,:),xy(2,:),'+')

%% test the particle filter initialisation with blob detection output
close all
foregroundDetector = vision.ForegroundDetector('NumGaussians', 3, ...
    'NumTrainingFrames', 1);

videoReader = vision.VideoFileReader('visiontraffic.avi');
figure
for i = 1:200
    i
    frame = step(videoReader); % read the next video frame
    subplot(231)
    imshow(frame)
    foreground = step(foregroundDetector, frame);
    subplot(232)    
    imshow(foreground,'InitialMagnification','fit')
        
    %Clean
    se = strel('square', 3);
    filteredForeground = imopen(foreground, se);
    subplot(233)
    imshow(filteredForeground); title('Clean Foreground');
    
    %Extract blobs
    blobAnalysis = vision.BlobAnalysis('MinimumBlobArea', 150);
    %blobAnalysis.AreaOutputPort = false;
    [area, centroid, bbox] = step(blobAnalysis, filteredForeground);
    bboxes = insertShape(frame, 'Rectangle', bbox, 'Color', 'green');
    
    % initialise multiple particle filters to see whether particles are
    % correctly distributed
    if i >= 125
        % define an array of particle filter objects
%         pfs = pf_class.empty(size(bbox,1),0);
%         for j = 1:size(bbox,1)
%             pfs(j) = pf_class(10, eye(2), eye(2), centroid(j,:), bbox(j,:));
%             % extract x y coordinates of particles and make circles by
%             % adding a radius
%             xy = pfs(j).S(1:2,:);
%             circ = [xy;
%                     ones(1,pfs(j).M) * 0.5]'
%             size(circ)
%             % draw a circle for each particle
%             circ = insertShape(frame, 'Circle', circ, 'Color', 'red');
% 
%         end
        pf = pf_class(10,eye(2),eye(2),centroid(1,:), bbox(1,:));
        xy = pf.S(1:2,:);
        bbox
        centroid
        circ = [xy;
            ones(1,pfs(j).M) * 0.5]'
        subplot(235)
        circles = insertShape(frame, 'Circle', circ, 'Color', 'red');
        imshow(circles)
    end
    
    subplot(234)
    imshow(bboxes)
    pause(0.1)
end