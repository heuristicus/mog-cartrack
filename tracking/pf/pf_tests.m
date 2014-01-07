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

%% overall test in a very simple environment
close all
clear all

bbox = [0 0 2.5 2.5];
centroid = find_centroid(bbox);
x = linspace(centroid(1),10,10);
y = linspace(centroid(2),10,10);

measurements = [x' y'];
nsteps = size(measurements, 1) + 1;



process_noise = diag([0.3 0.3 0.2 0.2]);
measurement_noise = diag([0.1 0.1 1 1]);
%measurement_noise = diag([0.1 0.1]);
% first measurement is the centroid
pf = pf_class(100,process_noise,measurement_noise, centroid, bbox);

figure
for i = 1:nsteps
sprintf('=======step %d======', i)
clf
hold on
pf.measurements
plot(pf.measurements{1,i}(1), pf.measurements{1,i}(2), 'go')
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:), pf.S(4,:))
quiver(pf.cluster_means{1,i}(1), pf.cluster_means{1,i}(2), pf.cluster_means{1,i}(3), pf.cluster_means{1,i}(4),'r')
plot(pf.cloud_mean(1,i), pf.cloud_mean(2,i), 'ro')
axis([0 max(x) 0 max(y)])
% the filter is initialised using the first measurement, so use the i+1th
% measurement at each timestep
pf.pf_step(1,measurements(i+1,:));
pause(1)
end

%% testing k-means functionality
close all
clear all
N=10;
cluster = [randn(N,2);
           randn(N,2) + 10];



[idx, centres] = kmeans(cluster, 2, 'replicates', 4)

plot(cluster(idx==1,1),cluster(idx==1,2),'r.','MarkerSize',12)
hold on
plot(cluster(idx==2,1),cluster(idx==2,2),'b.','MarkerSize',12)
plot(centres(:,1),centres(:,2),'kx','MarkerSize',12)
plot(centres(:,1),centres(:,2),'ko','MarkerSize',12)

%% test particle filter initialisation with multiple measurements
clear all
close all
bboxes = [0 0 1 1;
          4 4 5 5];

measurements = find_centroid(bboxes);

process_noise = diag([0.3 0.3 0.2 0.2]);
measurement_noise = diag([0.1 0.1 1 1]);

pf = pf_class(150, process_noise, measurement_noise, measurements, bboxes);

figure
hold on
quiver(pf.S(1,:),pf.S(2,:),pf.S(3,:),pf.S(4,:))
for i=1:size(bboxes,1)
    %                 row------|
    %         timestep------v  v v----------column
    % plot(pf.cluster_means{1}(i,1),pf.cluster_means{1}(i,2),'ro')
    plot(pf.cluster_means{1}(1,i),pf.cluster_means{1}(2,i),'ro')
    quiver(pf.cluster_means{1}(1,i), pf.cluster_means{1}(2,i), pf.cluster_means{1}(3,i), pf.cluster_means{1}(4,i), 0,'color','r')
    
    plot(measurements(i,1),measurements(i,2),'go');
end

%% test particle filter with multiple measurements in multiple steps

clear all
close all

initial_bboxes = [0 0 1 1;
                  4 4 5 5];
      
centroids = find_centroid(initial_bboxes);

nsteps = 7;
% each pair of rows corresponds to a set of x,y measurements for a given
% object over the timesteps
meas_tmp = zeros(size(centroids,1) * 2, nsteps);
for i=1:size(centroids,1)
     % starting index of the row to fill in the meas_tmp matrix
     j = (i - 1) * 2 + 1;
     meas_tmp(j, :) = linspace(centroids(i,1),centroids(i,1) + 3,nsteps);
     meas_tmp(j + 1, :) = linspace(centroids(i,2),centroids(i,1) + 3,nsteps);
end


% group up measurements at each timestep by reshaping the columns of the
% meas_tmp matrix
for i=1:size(meas_tmp,2)
    measurements{1,i} = reshape(meas_tmp(:,i), 2, size(centroids,1))';
end

% construct bboxes corresponding to measurements. Assume their size does
% not change
bboxes{1,1} = initial_bboxes;
for i = 2:nsteps
    prevmeas = measurements{1,i-1};
    meas = measurements{1,i};
    vel = meas - prevmeas;
    addmat = [vel zeros(size(centroids,1),2)];
    bboxes{1,i} = bboxes{1,i - 1} + addmat;
    %bboxes{1,i};
end

process_noise = diag([0.3 0.3 0.1 0.1 0.3 0.3]);
measurement_noise = diag([0.3 0.3]);

pf = pf_class(200, process_noise, measurement_noise, measurements{1}, bboxes{1});

figure
for j=1:nsteps
    fprintf('--------timestep %d\n--------', j);
    clf
    hold on
    fprintf('plotting particles with velocities\n');
    quiver(pf.S(1,:),pf.S(2,:),pf.S(5,:),pf.S(6,:))
    for i=1:size(bboxes{j},1)
        fprintf('plotting bboxes and cluster means for object %d\n', i);
        rectangle('position', bboxes{j}(i,:))
        %                 row------|
        %         timestep------v  v v----------column
        % plot(pf.cluster_means{j}(i,1),pf.cluster_means{1}(i,2),'ro')
        plot(pf.cluster_means{j}(1,i),pf.cluster_means{j}(2,i),'ro')
        quiver(pf.cluster_means{j}(1,i), pf.cluster_means{j}(2,i), pf.cluster_means{j}(5,i), pf.cluster_means{j}(6,i), 0,'color','r')
        %Plot measurements
        plot(measurements{j}(i,1),measurements{j}(i,2),'go');
    end
    axis([0 15 0 15])
    pf.pf_step(1, measurements{j+1},bboxes{j+1});
    pause
end

%%

% xstart ystart bboxw bboxh xend yend nsteps startstep
def = [3 3 1 1 6 6 6 0;
       7 8 2 2 10 10 6 0;
       5 3 2 2 7 0 3 3];


nsteps = max(def(:,7));
nobjects = size(def,1);
measurements = zeros(max(def(:,7)),2*size(def,1))
% deal with each row in turn
for i=1:size(def,1)
    j = (i - 1)*2 + 1; % index the first column of measurements for this object
    bbox = create_bbox(def(i,1), def(i,2), def(i,3), def(i,4))
    measurements(def(i,8) + 1:def(i,8)+def(i,7), j:j+1) = [linspace(def(i,1), def(i,5), def(i,7))' linspace(def(i,2), def(i,6), def(i,7))']
end

for i=1:nsteps
   rw = reshape(measurements(i,:), 2, nobjects)'
end


%% test the particle filter initialisation with blob detection output
close all
foregroundDetector = vision.ForegroundDetector('NumGaussians', 3, ...
    'NumTrainingFrames', 1);

videoReader = vision.VideoFileReader('viptraffic.avi');

pf = pf_class(1000, process_noise, measurement_noise);

process_noise = diag([0.3 0.3 0.2 0.2]);
measurement_noise = diag([0.1 0.1]);

figure
for i = 1:200
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
    
    subplot(234)
    imshow(bboxes)
    
    pf.pf_step(1,centroid,bbox);
    
    pause(0.1)
end