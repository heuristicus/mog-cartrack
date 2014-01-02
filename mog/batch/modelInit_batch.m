function [models] = modelInit_batch(X,parameters)
%MODELINIT Summary of this function goes here
%   Detailed explanation goes here
% It inits a pixels model with the default parameters:
% mu = X
% sigma = sigma0
% weight = 1/K;
% 
% Inputs
%         X:                  Cx1
%         parameters:         struct
%             -ALPHA            1x1
%             -K                1x1
%             -T                1x1
%             -SIGMA0           1x1
%             -WEIGHT0          1x1
%         
% Outputs
%         models:             M*NxK+C*K+K
%             -weight           M*NxK
%             -mu               M*NxC*K
%             -sigma            M*NxK

MN = size(X,1);

K = parameters.K;
SIGMA0= parameters.SIGMA0;

weight = (1/K)*ones(MN,K); %M*NxK
mu = repmat(X,1,K);  %M*NxC*K
sigma = SIGMA0*ones(MN,K);  %M*NxK

models = [weight,mu,sigma];
end

