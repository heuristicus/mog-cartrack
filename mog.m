function [foreground,background] = mog(image,count)
%MOG Summary of this function goes here
%   Detailed explanation goes here
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

K = 3;       %Number of Gaussians
T = 0.7;      %Background Threshold

if isempty(models)
   models = repmat(struct('weight',zeros(K,1), 'mu', zeros(C,K), 'sigma',zeros(K,1)),M,N); 
end

foreground = zeros(M,N);
background = zeros(M,N,C);

for m=1:M
    for n=1:N        
        X = reshape(image(m,n,:),C,1);
        %Preallocate
        prevWeight = zeros(K,1);
        prevMu = zeros(C,K);
        prevSigma = zeros(K,1);
        
        modelX = models(m,n);        
        prevWeight = modelX.weight;
        prevMu = modelX.mu;
        prevSigma = modelX.sigma;
        
        %Initialization (first frame)
        if count==1
%         if(isempty(prevWeight) || isempty(prevMu) || isempty(prevSigma))
              [prevWeight, prevMu, prevSigma] = modelInit(X,K); 
        end
        
        %Update model
        [weight,mu,sigma] = update(X,prevWeight,prevMu,prevSigma);
        
        models(m,n).weight = zeros(K,1);
        models(m,n).mu = zeros(C,K);
        models(m,n).sigma = zeros(K,1);
        
        models(m,n).weight = weight;
        models(m,n).mu = mu;
        models(m,n).sigma = sigma;
        
        %Sort weights/sigma
        ratio = weight./sigma;
        [w,index] = sort(ratio,1,'descend');
        %Calculate B = number of background gaussians
        sumB = cumsum(w);
        [~,B] = min(sumB>T);
        bgIndexes = index(1:B);
        
        %Set the background to the most likely gaussian
        background(m,n,:) = models(m,n).mu(:,bgIndexes(1));
       
        %See if the pixel matches a background gaussian
        matchingIndex = find(match(X,mu,sigma));
        if isempty(matchingIndex)
            matchingIndex = -1;
        end
        matching = find(bgIndexes == matchingIndex(1),1);
        %No match => foreground
        if isempty(matching)
            foreground(m,n) = 1;
        end
    end    
end
background = uint8(background);

end