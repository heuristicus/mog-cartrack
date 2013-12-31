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
D_TH = 6.25; %2.5^2;

delta = X(:,ones(K, 1)) - mu; %CxK
D = (diag(delta'*delta)./sigma)<D_TH; %Mahalanobis distance^2 (faster)
end

