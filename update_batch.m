function [weight, mu, sigma] = update_batch(X, weight, mu, sigma,alpha)
%UPDATE Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%             X (pixel value):    M*NxC
%             weight:             M*NxK
%             mu:                 M*NxC*K
%             sigma:              M*NxK
% Outputs:
%             weight:             M*NxK
%             mu:                 M*NxC*K
%             sigma:              M*NxK         

K = size(weight,2);
C = size(X,2);
MN = size(X,1);

SIGMA0 = (30/255).^2;
PRIOR_WEIGHT = alpha;

%Check which distribution matches the pixel value
[D,distances] = match_batch(X,mu,sigma); %M*Nx1, M*NxK

for k=1:K
   weightK = weight(:,k);    %M*Nx1
   muK = mu(:,(k-1)*C+1:k*C);%M*NxC
   sigmaK = sigma(:,k);      %M*Nx1
   
   M = D == k; %Matching     %M*Nx1, boolean
   
   nu = X-muK;       %M*NxC
   product = sum(nu.*nu,2);
   detQ = sigmaK.^C; %M*Nx1
   sigmaInv = 1./sigmaK; %M*Nx1
   rho = alpha;%*M.*( 1./((2*pi)^(C/2)*detQ.^0.5 ) ).*exp(-0.5*sigmaInv.*product) ; %M*Nx1
   rho_rep = rho;%repmat(rho,1,C);
   
   weight(:,k) = (1-alpha)*weightK + alpha*M;
   mu(:,(k-1)*C+1:k*C) = (1-rho_rep).*muK + rho_rep.*X;
   sigma(:,k) = (1-rho).*sigmaK + rho.*product;   
end

%If no match was found, set the least likely gaussian to a default
isMatch = D~=0;
[~, minI] = min(distances, [], 2); %Get closest gaussian

indexesSigma = sub2ind(size(sigma), 1:length(minI), minI');
sigma(indexesSigma) = (1-isMatch')*SIGMA0+ isMatch'.*sigma(indexesSigma);

indexesWeight = sub2ind(size(weight), 1:length(minI), minI');
weight(indexesWeight) = (1-isMatch')*PRIOR_WEIGHT+isMatch'.*weight(indexesWeight);

%This case is really tricky
indexesMuPre = sub2ind(size(mu), 1:length(minI), (minI'-1)*C+1);%?x1
indexesMu = zeros(1,C*size(indexesMuPre,2));
for c=1:C
    indexesMu(1,(c-1)*MN+1:c*MN)=indexesMuPre+(c-1)*MN;
end
% indexesMu =[indexesMuPre,indexesMuPre+MN, indexesMuPre+2*MN];

X_res = reshape(X, MN*C,1);
isMatchRep = repmat(isMatch',1,C);

mu(indexesMu) = (1-isMatchRep).*X_res'+isMatchRep.*mu(indexesMu);

%========

%Re-normalize weights
wSum = sum(weight,2);
weight = weight./wSum(:,ones(K,1));
end