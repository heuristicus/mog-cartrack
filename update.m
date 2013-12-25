function [weight, mu, sigma] = update(X, weight, mu, sigma)
%UPDATE Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X (pixel value):    Cx1
%             weight:             Kx1
%             mu:                 CxK
%             sigma:              Kx1
% Outputs:
%             weight:             Kx1
%             mu:                 CxK
%             sigma:              Kx1             

K = size(weight,1);
C = size(X,1);

ALPHA = 0.01;
D_TH = 6.25; %2.5^2;
SIGMA0 = 100;
PRIOR_WEIGHT = ALPHA;

%Check which distribution matches the pixel value
D = match(X,mu,sigma); %Kx1
D_in = D<D_TH;

%Update weights, mu and sigma
% rho = zeros(K,1);
sigmaInv = 1./sigma;
sigmaInv = sigmaInv(:,ones(K,1));

%Vectorization over K gaussians
det_Q = sigma.^C; %Kx1 (Sigma is a diagonal matrix with equal elements)
X_rep = X(:,ones(K,1)); %CxK
nu = X_rep-mu;
rho = (ALPHA*(1./( (2*pi)^(C/2)*(det_Q).^.5))).*(exp(-0.5*sum((nu.^2).*sigmaInv',1)))';

weight = weight + ALPHA*(D_in - weight);
rho_rep = (rho(:,ones(C,1)))'; %CxK

mu = (1-rho_rep).*mu + rho_rep.*X_rep;

sigma = (1-rho).*sigma + rho.*diag(nu'*nu);

if all(D_in == 0) %No matches
   [value, index] = min(D);
   mu(:,index) = X;
   sigma(index)= SIGMA0;
   weight(index) = PRIOR_WEIGHT;    
end

%Re-normalize weights
weight = weight./sum(weight,1);
end