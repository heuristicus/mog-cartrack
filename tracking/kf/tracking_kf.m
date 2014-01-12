function [trackedObjects] = tracking_kf(measurements,params,height,width)
%TRACKING_KF Summary of this function goes here
%   Detailed explanation goes here
% It performs the tracking of vehicles using a set
% of Kalman Filters. 
% 
% Input:
%             measurements            4xn
%             params                  struct
% Output:
%             trackedObjects          6xn

persistent filters; %Set of instances of the "kf_class", which represent a KF

n = size(measurements,2) %Number of measurements

display(sprintf('Number of Kalman Filters: %d',size(filters,1)));
%% 1.- Update previous Kalman Filters
outliers = ones(n,1); %Measurements that have not been matched
if ~isempty(filters)
   [filters,outliers] = updateKFs(filters,measurements); 
end
outliers
%% 2.- Create new Kalman Filters for the outliers
filters = createNewKFs(filters,outliers,measurements,params);

%% 3.- Delete old Kalman Filters (the object left the scene)
filters = deleteOldKFs(filters,height,width);

%% 4.- Output 
if ~isempty(filters)
    trackedObjects = zeros(size(filters(1).mu,1),size(filters,1)); %6xN
    for i=1:size(filters,1)
        trackedObjects(:,i) = filters(i).mu;
    end
else
    trackedObjects = [];
end
