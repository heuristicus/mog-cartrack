function [D] = mahalanobis_batch(X, mu, sigma)
%MATCH Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X:          M*NxC
%             mu:         M*NxC*K
%             sigma:      M*NxK
% Outputs:
%             D:          M*NxK

%Compute Mahalanobis distance
K = size(sigma,2);
MN = size(sigma,1);
C = size(X,2);

X_rep = repmat(X,1,K);
delta = X_rep- mu; %M*NxC*K
delta = delta.^2; %To compute delta'*delta;
D = zeros(MN,K);
%Loop over K distributions
for k=1:K
    indexes = (k-1)*C+1:k*C;
    D(:,k) = sum(delta(:,indexes),2);
end
end

