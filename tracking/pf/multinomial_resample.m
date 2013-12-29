% function S = multinomial_resample(S_bar)
% This function performs systematic re-sampling
% Inputs:   
%           S_bar(t):       4XM
% Outputs:
%           S(t):           4XM
function S = multinomial_resample(S_bar)
    nparticles = size(S_bar,2);
    cdf = cumsum(S_bar(4,:));
    rv = rand(1,nparticles);
    S = zeros(4,nparticles);
    for m = 1 : nparticles
        r_m = rv(m);
        i = find(cdf >= r_m,1,'first');
        S(:,m) = S_bar(:,i);
    end
    S(4,:) = (1/nparticles)*ones(1, nparticles);
    
end
