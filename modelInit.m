function [weight,mu,sigma] = modelInit(X,K)
%MODELINIT Summary of this function goes here
%   Detailed explanation goes here
% Inputs
%         X:                  nx1
%         K:                  1x1
%         
% Outputs
%         weight:             Kx1
%         mu:                 nxK
%         sigma:              Kx1


SIGMA_DEF=100;

n = size(X,1);

weight = (1/K)*ones(K,1); %Uniform weights
mu = repmat(X,1,K);       %Current pixel value
sigma = SIGMA_DEF*ones(K,1); %Large sigma

end

