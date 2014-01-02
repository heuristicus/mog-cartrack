%% test kalman filter initialisation


%% overall test in a very simple environment
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

measurements = [x' y' widths' heights']; %6xN


process_noise = diag([0.3 0.3 0.1 0.1 0.1 0.1]);
%measurement_noise = diag([0.1 0.1 0.1 0.1]);
measurement_noise = diag([0.1 0.1 0.1 0.1]);
%Initial values
mu0 = [measurements(1,:),0,0]'; %We don't know the velocity initially
sigma0 = diag([0.5 0.5 0.5 0.5 10.0 10.0]); %So a high variance to it

dt = 1; %1 frame
% first measurement is the centroid
kf = kf_class(process_noise,measurement_noise,mu0,sigma0,dt);

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