function [weight, mu, sigma] = update(X, weight, mu, sigma)
%UPDATE Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X (pixel value):    nx1
%             weight:             Kx1
%             mu:                 nxK
%             sigma:              Kx1
% Outputs:
%             weight:             Kx1
%             mu:                 nxK
%             sigma:              Kx1             

K = size(weight,1);
n = size(X,1);

ALPHA = 0.01;
D_TH = 2.5;
SIGMA0 = 100;
PRIOR_WEIGHT = ALPHA;

%Check which distribution matches the pixel value
D = match(X,mu,sigma); %Kx1
D_in = D<D_TH;

%Update weights, mu and sigma
rho = zeros(K,1);
for k=1:K
    Q = sigma(k)*eye(n);
    nu = X-mu(:,k);
    rho(k) = ALPHA*(1/( (2*pi)^(n/2)*(det(Q))^.5 )*exp(-0.5*nu'*(Q\(nu))));    
end
weight = weight + ALPHA*(D_in - weight);
rho_rep = repmat(rho',n,1); %nxK
X_rep = repmat(X,1,K);

mu = (1-rho_rep).*mu + rho_rep.*X_rep;

sigma = (1-rho).*sigma + rho.*diag((X_rep-mu)'*(X_rep-mu));

if all(D_in == 0) %No matches
   [value, index] = min(D,1);
   mu(:,index) = X;
   sigma(index)= SIGMA0;
   weight(index) = PRIOR_WEIGHT;    
end

%Re-normalize weights
weight = weight/sum(weight,1);
end

