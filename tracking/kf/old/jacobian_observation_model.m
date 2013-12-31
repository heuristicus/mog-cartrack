% function H = jacobian_observation_model(mu_bar,M,j,z,i)
% This function is the implementation of the H function
% Inputs:
%           mu_bar(t)   3X1
%           M           2XN
%           j           1X1
%           z           1Xn
%           i           1X1
% Outputs:  
%           H           2X3
function H = jacobian_observation_model(mu_bar,M,j,z,i)

dx = mu_bar(1)-M(1,j);
dy = mu_bar(2)-M(2,j);

H=[dx/z(1) dy/z(1) 0;
   -dy/(z(1)^2) dx/(z(1)^2) -1];

end