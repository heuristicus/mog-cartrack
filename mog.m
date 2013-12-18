function [foreground] = mog(image)
%MOG Summary of this function goes here
%   Detailed explanation goes here
% Inputs:
%         image:              MxNxn
%         
% Outputs
%         foreground:         MxN

M = size(image,1);
N = size(image,2);
n = size(image,3);

K = 3;       %Number of Gaussians
T = 0.5;      %Background Threshold


models = repmat(struct('weight',[], 'mu', [], 'sigma',[]),M,N);

foreground = zeros(M,N);

parfor m=1:M
    for n=1:N        
        X = double(squeeze(image(m,n,:)));
        
        modelX = models(m,n);        
        prevWeight = modelX.weight;
        prevMu = modelX.mu;
        prevSigma = modelX.sigma;
        
        %Initialization (first frame)
        if(isempty(prevWeight) || isempty(prevMu) || isempty(prevSigma))
           [prevWeight, prevMu, prevSigma] = modelInit(X,K); 
        end
        
        %Update model
        [weight,mu,sigma] = update(X,prevWeight,prevMu,prevSigma);
        modelX.weight = weight;
        modelX.mu = mu;
        modelX.sigma = sigma;
        
        %Sort weights/sigma
        ratio = weight./sigma;
        [w,index] = sort(ratio,1,'descend');
        %Calculate B = number of background gaussians
        sum = cumsum(w);
        [~,B] = min(sum>T);
        bgIndexes = index(1:B);
        
        %See if the pixel matches a background gaussian
        matchingIndex = find(match(X,mu,sigma));
        matching = find(bgIndexes == matchingIndex);
        %No match => foreground
        if isempty(matching)
            foreground(m,n) = 1;
        end
    end    
end

end

