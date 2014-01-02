function [gaussIndexesSorted, B] = sortGaussians(weight,sigma,parameters)
%SORTGAUSSIANS Summary of this function goes here
%   Detailed explanation goes here
% It sorts the gaussians according to the ratio weight/sigma
% 
% Inputs:
%         weight                 M*NxK
%         sigma                  M*NxK
%         parameters:         struct
%             -ALPHA            1x1
%             -K                1x1
%             -T                1x1
%             -SIGMA0           1x1
%             -WEIGHT0          1x1
% Outputs:
%         gaussIndexSorted       M*NxK
%         B                      M*Nx1

MN = size(weight,1);
K  = parameters.K;
T  = parameters.T;

ratio = weight./sigma; %M*NxK
initialGaussIndexes = repmat(1:K,MN,1); %1 2 ... K, repeated M*Nx1

[~,ix2] = sort(ratio,2,'descend'); %M*NxK
%Now we apply this ordering to the "weight" matrix
%// ix2 is the index along dimension 2, and we want dimension 1 to remain unchanged
ix1 = repmat((1:size(ratio,1))', [1 size(ratio,2)]); %//'
%// Convert to linear index equivalent of the reordering of the sort() call
ix = sub2ind(size(ratio), ix1, ix2);
%// And apply it
wSorted = weight(ix);
gaussIndexesSorted = initialGaussIndexes(ix);

%Calculate B = number of background gaussians
sumB = cumsum(wSorted,2);
%This calculates the index of the min value of sumB such that
%it is greater than T. To do that, I sum 1 if sumB is NOT greater
%than T => the "min" function will return the index of the first
%element for which we sum 0 (sumB>T).
[~,B] = min(sumB+(sumB<=T),[],2); %M*Nx1

end
