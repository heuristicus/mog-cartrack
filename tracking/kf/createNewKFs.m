function filters = createNewKFs(filters,outliers,measurements,params)
%CREATENEWKFS Summary of this function goes here
%   Detailed explanation goes here
% It creates new Kalman Filters for each of the measurements
% that have not been tracked by any of the previous KF.

% Inputs:
%                 filters:            M_0x1 array of struct kf_class
%                 measurements:       4xn
%                 outliers:           nx1
%                 params:              struct 
%                     -Q
%                     -R
%                     -dt
%                     -sigma0
%                 
% Outputs:
%                 filters:            Mx1 array of struct kf_class
M_0 = size(filters,1); %Initial size of filters

% First, find the outliers
outIndexes = find(outliers);

% Allocate space for the new filters
M = M_0 + size(outIndexes,1);
filtersN = kf_class.empty(M,0);
if(~isempty(filters))
    filtersN(1:M_0) = filters;
end

for i=1:size(outIndexes)
   m_i = measurements(:,outIndexes(i));
   %Initialize at the bounding box defined by the measurement
   mu = [m_i ; 0 ;0]; %Initial zero velocity;
   %Add a new filter
   filtersN(M_0+i) = kf_class(params,mu);
   display('---Creating a new Kalman Filter---');
end
filters = filtersN';
end

