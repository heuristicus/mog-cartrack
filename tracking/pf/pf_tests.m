%% test to see whether particles are correctly initialised within the bounding box specified
close all
clear all
bbox = [1 5 25 5]; 
centroid = find_centroid(bbox);
pf = pf_class(10,eye(4),eye(2), centroid, bbox);

figure
hold on
plot(pf.S(1,:),pf.S(2,:),'+')
plot(centroid(1), centroid(2), 'or')
axis_box(bbox)

%% test whether velocities are reasonably initialised
close all
clear all
bbox = [1 5 25 5];
centroid = find_centroid(bbox);
pf = pf_class(10,eye(4),eye(2), centroid, bbox);

figure
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
axis_box(bbox)

%% test whether the prediction step correctly moves particles on the plane

close all
clear all
bbox = [1 5 25 5];
centroid = find_centroid(bbox)
process_noise = diag([0.1 0.1 0.1 0.1]);

pf = pf_class(10,process_noise,eye(2), centroid, bbox);

figure
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
axis([-50 50 -50 50])

for i=1:20
    pf.pf_predict(1);

    quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
    axis([-50 50 -50 50])
    pause(0.1)
end    

%% test the step function and computation of centroid of the cloud
close all
clear all

measurements = [4.5,6.5;
                6,5];
nsteps = size(measurements, 1) + 1;

bbox = [1 5 5 5];
centroid = find_centroid(bbox);
process_noise = diag([0.1 0.1 0.1 0.1]);
measurement_noise = diag([0.1 0.1 0.1 0.1]);
% first measurement is the centroid
pf = pf_class(10,process_noise,measurement_noise, centroid, bbox);

for i = 1:nsteps
sprintf('=======step %d======', i)
figure
hold on
plot(pf.measurements(1,i), pf.measurements(2,i), 'go')
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
quiver(pf.cloud_mean(1,i), pf.cloud_mean(2,i), pf.cloud_mean(3,i), pf.cloud_mean(4,i),'r')
plot(pf.cloud_mean(1,i), pf.cloud_mean(2,i), 'ro')
axis([-5 15 -5 15])

% second measurement is the one received by the step function
pf.pf_step(1,measurements(i,:));
end

%% test the particle filter initialisation with blob detection output
close all
foregroundDetector = vision.ForegroundDetector('NumGaussians', 3, ...
    'NumTrainingFrames', 1);

videoReader = vision.VideoFileReader('viptraffic.avi');
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
    filledForeground = imfill(imdilate(foreground,se),'holes');

    filteredForeground = imopen(filledForeground, se);
    subplot(233)
    imshow(filteredForeground); title('Clean Foreground');
    
    subplot(235)
    imshow(filledForeground);title('Filled Foreground');
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
    pause
end