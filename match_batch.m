function [D,distances] = match_batch(X, mu, sigma)
%MATCH Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X:          M*NxC
%             mu:         M*NxC*K
%             sigma:      M*NxK
% Outputs:
%             match:      M*Nx1

%Compute Mahalanobis distance
D_TH = 6.25; %2.5^2;

distances = mahalanobis_batch(X,mu,sigma);

[minV, minI] = min(distances./sigma,[],2); %We pick the Minimum distance Gaussian
D = minI.*(minV<D_TH); %Mahalanobis distance^2 (faster)
%It outputs the index of the closes gaussian, given that it's close enough.
end

