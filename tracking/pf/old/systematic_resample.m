% function S = systematic_resample(S_bar)
% This function performs systematic re-sampling
% Inputs:   
%           S_bar(t):       4XM
% Outputs:
%           S(t):           4XM
function S = systematic_resample(S_bar)
    cdf = cumsum(S_bar(4,:));
    nparticles = size(S_bar,2);
    S = zeros(4,nparticles);
    r_0 = rand / nparticles;
    for m = 1 : nparticles
        S(:,m) = S_bar(:,find(cdf >= r_0,1,'first'));
        r_0 = r_0 + 1/nparticles;
    end
    S(4,:) = 1/nparticles*ones(1,nparticles);

end