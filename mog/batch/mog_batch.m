function [foreground,background,model] = mog_batch(image,parameters)
%MOG Summary of this function goes here
% Applies the Mixture of Gaussians algorithm to create the foreground
% image. The update is done simultaneously for all the pixels, giving
% a significant improvement in speed
% Inputs:
%         image:              MxNxC
%         parameters:         struct
%             -ALPHA            1x1
%             -K                1x1
%             -T                1x1
%             -SIGMA0           1x1
%             -WEIGHT0          1x1
%         
% Outputs
%         foreground:         MxN
%         background:         MxNxC
%         models:             M*NxK+C*K+K
%             -weight         M*NxK
%             -mu             M*NxC*K
%             -sigma          M*NxK
persistent models;

M = size(image,1);
N = size(image,2);
C = size(image,3);
K = parameters.K;     

% We store the models in a big matrix:
%     K       C*K      K
% |weight_1  mu_1    sigma_1 |
% |weight_2  mu_2    sigma_2 |
% .
% .
% .
% |weight_MN  mu_MN    sigma_MN |
wIndexes = 1:K;
muIndexes= K+1:K+C*K;
sigmaIndexes = K+C*K+1:K+C*K+K;


foreground = ones(M,N);
background = zeros(M,N,C);

%====Main vectorized process====   
X = reshape(image,M*N,C); %M*NxC

%Initialization (first frame)
if isempty(models)
   models = modelInit_batch(X,parameters); 
end

prevWeight = models(:,wIndexes);
prevMu = models(:,muIndexes);
prevSigma = models(:,sigmaIndexes);

%Update model
[weight,mu,sigma] = update_batch(X,prevWeight,prevMu,prevSigma,parameters);

models(:,wIndexes) = weight;
models(:,muIndexes) = mu;
models(:,sigmaIndexes) = sigma;

%Sort weights/sigma
[gaussIndexesSorted,B] = sortGaussians(weight,sigma,parameters);

%Set the background to the weighted average of gaussians
%     bgWeights = weight(bgIndexes); %Bx1
%     bgMu = mu(:,bgIndexes); %CxB
%     background(m,n,:) = (bgMu*bgWeights)./(sum(bgWeights,1));

%See if the pixel matches a background gaussian (the index must be less
%than B)
[matchRes,~] = match_batch(X,mu,sigma); %M*Nx1
gaussCorresp = gaussIndexesSorted == repmat(matchRes,1,K); %M*NxK
[matchRow, matchCol] = find(gaussCorresp);
matchMask = matchRow.*(matchCol<=B(matchRow));

%Remove zeros
matchMask = matchMask(matchMask~=0);
%Set the foreground mask to 0 for the background pixels
foreground(matchMask) = 0;

%Other interesting output
% background = uint8(background);
model = models;
end