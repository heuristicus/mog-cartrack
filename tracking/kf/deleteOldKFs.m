function [filters] = deleteOldKFs(filters)
%DELETEKFS Summary of this function goes here
%   Detailed explanation goes here

% It deletes Kalman Filters from the "filters" set. This may occur
% in case the object that was being tracked left the scene, or 
% it was an spurious measurement that caused the algorithm to track it

% Input:
%                 filters:            M_0x1 array of struct kf_class
% Output:
%                 filters:            Mx1 array of struct kf_class
    
M_0 = size(filters,1);
filtersToRemove = zeros(M_0,1);

%We analyze the internal counter of consecutive frames along which
% we could not update the KF because we had no realiable measurement.
% If this number of frames exceeds a threshold, we delete the filter
for i=1:M_0
   kf = filters(i);
   filtersToRemove(i)= kf.noUpdateCounter >= kf.NO_UPDATE_TIME_MAX;
end

%Only preserve the ones that we do NOT delete
filters = filters(~filtersToRemove);

end

