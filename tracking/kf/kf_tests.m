%% Test the KF for a single object-single measurement tracking
close all
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);

initialCentroid = [0,0];
initialWidth = 2;
initialHeight = 2;

N = 20;
L = 10;
x = linspace(initialCentroid(1),L,N); %1xN
y = linspace(initialCentroid(2),L,N); %1xN
widths = initialWidth*ones(1,N); %1xN
heights = initialHeight*ones(1,N); %1xN

measurements = [x' y' widths' heights']; %6xN

mu0 = [x(1),y(1),widths(1),heights(1),0,0]';
params = kf_config();
% first measurement is the centroid
kf = kf_class(params,mu0);

figure
for i = 1:N
    sprintf('=======step %d======', i)
    clf
    hold on

    z = measurements(i,:)';
    kf.kf_step(z);

    %Draw measurement
    drawCenteredRectangle(z(1:4),'g'); %Bounding box
    plot(z(1),z(2),'go'); %Centroid

    %Draw estimated state
    quiver(kf.mu(1),kf.mu(2),kf.mu(5),kf.mu(6));
    plot(kf.mu(1), kf.mu(2), 'ro');
    axis([0 max(x) 0 max(y)])

    display(sprintf('Velocity: (%.2f, %.2f) pixels/frame',kf.mu(5),kf.mu(6)));
    pause
end

%====================================================================================
%% Same as before but with the tracking_kf() function
close all
clear all

initialCentroid = [0,0];
initialWidth = 2;
initialHeight = 2;

N = 20;
L = 10;
x = linspace(initialCentroid(1),L,N); %1xN
y = linspace(initialCentroid(2),L,N); %1xN
widths = initialWidth*ones(1,N); %1xN
heights = initialHeight*ones(1,N); %1xN

measurements = [x' y' widths' heights']; %4xN

params = kf_config();
figure
for i = 1:N
    sprintf('=======step %d======', i)
    clf
    hold on

    z = measurements(i,:)'; %4x1
    trackedObjects = tracking_kf(z,params);

    %Draw measurement
    drawCenteredRectangle(z(1:4),'g'); %Bounding box
    plot(z(1),z(2),'go'); %Centroid

    %Draw estimates state
    quiver(trackedObjects(1,:),trackedObjects(2,:),trackedObjects(5,:),trackedObjects(6,:)); %Velocity
    plot(trackedObjects(1,:),trackedObjects(2,:), 'ro');
    axis([0 max(x) 0 max(y)])
    pause
end


%% Two objects tracking (clearly separated)
close all; clc;
s=dbstatus; %To clear all without clearing breakpoints
save('myBreakpoints.mat', 's');
clear all
load('myBreakpoints.mat');
dbstop(s);

initialCentroid1 = [2,2];
initialCentroid2 = [8,8];

initialWidth = 2;
initialHeight = 2;

N = 20;
L = 10;
% First Blob
x1 = reshape(linspace(initialCentroid1(1),L,N),1,1,N); %1x1xN
y1 = reshape(initialCentroid1(2)*ones(1,N),1,1,N); %1x1xN
% Second Blob
x2 = reshape(linspace(initialCentroid2(1),0,N),1,1,N);%1x1xN
y2 = reshape(initialCentroid2(2)*ones(1,N),1,1,N); %1x1xN

widths = initialWidth*ones(1,1,N); %1x1xN
heights = initialHeight*ones(1,1,N); %1x1xN

measurements = zeros(4,2,N);
measurements(1,1,:) = x1;
measurements(2,1,:) = y1;
measurements(3,1,:) = widths;
measurements(4,1,:) = heights;
measurements(1,2,:) = x2;
measurements(2,2,:) = y2;
measurements(3,2,:) = widths;
measurements(4,2,:) = heights;

params = kf_config();
figure
for i = 1:N
    display(sprintf('=======step %d======', i));
    clf; %Clear current figure
    hold on

    z = measurements(:,:,i); %4xn
    trackedObjects = tracking_kf(z,params);

    %Draw measurement
    for j=1:size(z,2)
        drawCenteredRectangle(z(:,j),'g'); %Bounding box
        plot(z(1,j),z(2,j),'go'); %Centroid
    end

    display('Velocities:')
    trackedObjects(5:6,:)
    %Draw estimates state
    quiver(trackedObjects(1,:),trackedObjects(2,:),trackedObjects(5,:),trackedObjects(6,:),0); %Velocity
    plot(trackedObjects(1,:),trackedObjects(2,:), 'ro');
    axis([0 L 0 L])
    pause
end


%% 1 object leaving


