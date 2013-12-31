% function S_bar = weight(S_bar,Psi,outlier)
%           S_bar(t)            4XM
%           outlier             1Xn
%           Psi(t)              1XnXM
% Outputs: 
%           S_bar(t)            4XM
function S_bar = weight(S_bar,Psi,outlier)
    np = reshape(Psi, size(Psi,2), size(Psi,3));
    % find and set all outlier rows to 1 - this ignores the value that was
    % previously assigned to that measurement
    x = find(outlier);
    if ~isempty(x)
        np(x,:) = 1;
    end
    pr = prod(np);
    % normalise so that all of the weights sum to 1
    pr = pr/sum(pr);    
    S_bar(4,:) = pr;
end