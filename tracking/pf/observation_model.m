% function h = observation_model(S,W,j)
% This function is the implementation of the observation model
% The bearing should lie in the interval [-pi,pi)
% Inputs:
%           S           4XM
%           W           2XN
%           j           1X1
% Outputs:  
%           h           2XM
function h = observation_model(S,W,j)

xdist = W(1,j)-S(1,:);
ydist = W(2,j)-S(2,:);
angle = atan2(ydist,xdist)-S(3,:);
normangle = mod(angle+pi, 2*pi) - pi;

h = [sqrt(xdist.^2 + ydist.^2); % euclidean distance
     normangle];

end