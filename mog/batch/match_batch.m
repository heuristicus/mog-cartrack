function [D,distances] = match_batch(X, mu, sigma)
%MATCH Summary of this function goes here
%   Detailed explanation goes here
% It tries to match the current pixel value X with the K
% gaussians that model the image. The output is the 
% index of the most likely matched gaussian, or 0 if
% no gaussian has been properly matched (outside ~2.5 sigma).
% Inputs:
%             X:          M*NxC
%             mu:         M*NxC*K
%             sigma:      M*NxK
% Outputs:
%             match:      M*Nx1

%Compute Mahalanobis distance
D_TH = 2.5^2; %^2 to compare without using sqrt

distances = mahalanobis_batch(X,mu,sigma);
[minV, minI] = min(distances,[],2); %We pick the Minimum distance Gaussian
D = minI.*(minV<D_TH); %Mahalanobis distance^2 (faster)
%It outputs the index of the closest gaussian, given that it's close enough.
end

