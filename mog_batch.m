function [foreground,background] = mog_batch(image,count,alpha)
%MOG Summary of this function goes here
% Applies the Mixture of Gaussians algorithm to create the foreground
% image
% Inputs:
%         image:              MxNxC
%         
% Outputs
%         foreground:         MxN
%         background:         MxNxC
persistent models;

M = size(image,1);
N = size(image,2);
C = size(image,3);

K = 5;       %Number of Gaussians
T = 0.7;      %Background Threshold

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

if isempty(models)
   models = zeros(M*N,K+C*K+K);
end
foreground = ones(M,N);
background = zeros(M,N,C);

%====Main vectorized process====   
    X = reshape(image,M*N,C); %M*NxC

    prevWeight = models(:,wIndexes);
    prevMu = models(:,muIndexes);
    prevSigma = models(:,sigmaIndexes);
    
    %Initialization (first frame)
    if count==1
          [prevWeight, prevMu, prevSigma] = modelInit_batch(X,K); 
    end
    %Update model
    [weight,mu,sigma] = update_batch(X,prevWeight,prevMu,prevSigma,alpha);

    models(:,wIndexes) = weight;
    models(:,muIndexes) = mu;
    models(:,sigmaIndexes) = sigma;

    %Sort weights/sigma
    ratio = weight./sigma; %M*NxK
    initialGaussIndexes = repmat(1:K,M*N,1); %1 2 3 4 5, repeated M*Nx1
    
    [~,ix2] = sort(ratio,2,'descend'); %M*NxK
    %Now we apply this ordering to the "weight" matrix
    %// ix2 is the index along dimension 2, and we want dimension 1 to remain unchanged
    ix1 = repmat((1:size(ratio,1))', [1 size(ratio,2)]); %//'
    %// Convert to linear index equivalent of the reordering of the sort() call
    ix = sub2ind(size(ratio), ix1, ix2);
    %// And apply it
    wSorted = weight(ix);
    gaussIndexesSorted = initialGaussIndexes(ix);
    
    %Calculate B = number of background gaussians
    sumB = cumsum(wSorted,2);
    %This calculates the index of the min value of sumB such that
    %it is greater than T. To do that, I sum 1 if sumB is NOT greater
    %than T => the "min" function will return the index of the first
    %element for which we sum 0 (sumB>T).
    [~,B] = min(sumB+(sumB<=T),[],2); %M*Nx1
    
    %Set the background to the weighted average of gaussians
%     bgWeights = weight(bgIndexes); %Bx1
%     bgMu = mu(:,bgIndexes); %CxB
%     background(m,n,:) = (bgMu*bgWeights)./(sum(bgWeights,1));

    %See if the pixel matches a background gaussian
    matchRes = match_batch(X,mu,sigma); %M*Nx1
    gaussCorresp = gaussIndexesSorted == repmat(matchRes,1,K); %M*NxK
    [matchRow, matchCol] = find(gaussCorresp);
    matchMask = matchRow.*(matchCol<=B(matchRow));
    
    %Remove zeros
    matchMask = matchMask(matchMask~=0);
    
    foreground(matchMask) = 0;

% background = uint8(background);

end