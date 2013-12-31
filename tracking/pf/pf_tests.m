%% test to see whether particles are correctly initialised within the bounding box specified
close all
clear all
bbox = [1 5 25 5];
pf = pf_class(10,eye(4),eye(2), bbox);

figure
plot(pf.S(1,:),pf.S(2,:),'+')

%% test whether velocities are reasonably initialised
close all
clear all
bbox = [1 5 25 5];
pf = pf_class(10,eye(4),eye(2), bbox);

figure
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))

%% test whether the prediction step correctly moves particles on the plane

close all
clear all
bbox = [1 5 25 5];
process_noise = diag([0.1 0.1 0.1 0.1]);
pf = pf_class(10,process_noise,eye(2), bbox);

figure
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
axis([-50 50 -50 50])

for i=1:20
    pf.pf_predict(1);

    quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
    axis([-50 50 -50 50])
    pause(0.1)
end    

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
        pfs = pf_class.empty(size(bbox,1),0);
        circ = [];
        for j = 1:size(bbox,1)
            j
            pfs(j) = pf_class(10, eye(4), eye(2), bbox(j,:));
            % extract x y coordinates of particles and make circles by
            % adding a radius
            xy = pfs(j).S(1:2,:);
            tmpcirc = [xy;
                       ones(1,pfs(j).M) * 0.5]';
            circ = [circ;
                    tmpcirc];
        end
        circles = insertShape(frame, 'Circle', circ, 'Color', 'red');
        subplot(235)
        imshow(circles)
    end
    
    subplot(234)
    imshow(bboxes)
    pause(0.1)
end