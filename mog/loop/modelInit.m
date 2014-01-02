function [weight,mu,sigma] = modelInit(X,K)
%MODELINIT Summary of this function goes here
%   Detailed explanation goes here
% Inputs
%         X:                  Cx1
%         K:                  1x1
%         
% Outputs
%         weight:             Kx1
%         mu:                 CxK
%         sigma:              Kx1


SIGMA_DEF=100;
onesK = ones(K,1);

weight = (1/K);
weight = weight(:,onesK)'; %Uniform weights
mu = X(:,onesK);   %nxK    %Current pixel value
sigma = SIGMA_DEF(:,onesK)'; %Large sigma

end

