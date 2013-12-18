function [D] = match(X, mu, sigma)
%MATCH Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X:          nx1
%             mu:         nxK
%             sigma:      Kx1
% Outputs:
%             match:      Kx1

%Compute Mahalanobis distance

K = size(mu,2);

Xrep = repmat(X,1,K); %nxK
delta = Xrep-mu;         %nxK

D = sqrt(diag(delta'*delta)./sigma); %Mahalanobis distance
end

