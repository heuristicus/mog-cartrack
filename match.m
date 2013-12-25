function [D] = match(X, mu, sigma)
%MATCH Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X:          Cx1
%             mu:         CxK
%             sigma:      Kx1
% Outputs:
%             match:      Kx1

%Compute Mahalanobis distance
K = size(mu,2);
delta = X(:,ones(K, 1)) - mu; %CxK
D = diag(delta'*delta)./sigma; %Mahalanobis distance^2 (faster)
end

