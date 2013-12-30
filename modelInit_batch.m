function [weight,mu,sigma] = modelInit_batch(X,K)
%MODELINIT Summary of this function goes here
%   Detailed explanation goes here
% Inputs
%         X:                  Cx1
%         K:                  1x1
%         
% Outputs
%         weight:             M*NxK
%         mu:                 M*NxC*K
%         sigma:              M*NxK

MN = size(X,1);

SIGMA_DEF=(30/255).^2;

weight = (1/K)*ones(MN,K); %M*NxK
mu = repmat(X,1,K);  %M*Nx(C*K)
sigma = SIGMA_DEF*ones(MN,K);  %M*NxK

end

