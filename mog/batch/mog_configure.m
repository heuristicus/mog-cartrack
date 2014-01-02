function [parameters] = mog_configure()
%CONFIGURE Summary of this function goes here
%   Detailed explanation goes here
% It configures the parameters of the MoG
% Outputs:
%       parameters              struct
%             -ALPHA            1x1
%             -K                1x1
%             -T                1x1
%             -SIGMA0           1x1
%             -WEIGHT0          1x1

ALPHA   = 0.01;          %Learning rate
K       = 5;             %Number of gaussians
T       = 0.7;           %Fraction of background over foreground
SIGMA0  = (30/255).^2;   %Initial variance
WEIGHT0 = ALPHA;         %Initial weight

parameters = struct('ALPHA',ALPHA,'K',K,'T',T,'SIGMA0',SIGMA0,'WEIGHT0',WEIGHT0);
end

