% function h = observation_model(x,M,j)
% This function is the implementation of the h function.
% The bearing should lie in the interval [-pi,pi)
% Inputs:
%           x(t)        3X1
%           M           2XN
%           j           1X1
% Outputs:  
%           h           2X1
function h = observation_model(x,M,j)

dx = M(1,j)-x(1);
dy = M(2,j)-x(2);
theta = atan2(dy,dx)-x(3);
normtheta = mod(theta+pi,2*pi)-pi;
h = [sqrt(dy^2 + dx^2);
     normtheta];

end