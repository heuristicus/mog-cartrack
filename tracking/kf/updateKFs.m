function [filters,outliers] = updateKFs(filters,measurements)
%UPDATEKFS Summary of this function goes here
%   Detailed explanation goes here
% It updates the current Kalman Filters based on the received
% measurements. It also outpus an "outlier" vector which is
% 1 for each measurement that has not been used to update
% in any of the KF. 
% 
% Inputs:
%                 filters:            Mx1 array of struct kf_class
%                 measurements:       4xn
%                 
% Outputs:
%                 filters:            Mx1 array of struct kf_class
%                 outliers:           nx1

M = size(filters);
n = size(measurements,2);

outliers = ones(n,1);

for i=1:M
    kf = filters(i);
    outliers_i = kf.kf_step(measurements);
    %We AND with previous outliers so that only the ones common to all KF
    %remain
    outliers = outliers & outliers_i;    
end

end

