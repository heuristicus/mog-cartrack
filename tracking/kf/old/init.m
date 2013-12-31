% function [mu,sigma,R,Q,Lambda_M] = init()
% This function initializes the parameters of the filter.
% Outputs:
%			mu(0):			3X1
%			sigma(0):		3X3
%			R:				3X3
%			Q:				2X2
function [mu,sigma,R,Q,Lambda_M] = init()
mu = [0;0;0]; % initial estimate of state
sigma = 1e-10*diag([1 1 1]); % initial covariance matrix
delta_m = 0.999;

% map_03
% runlocalization_track('so_o3_ie.txt', 'map_o3.txt',1,1,1,2)
% laser scanner accuracy 1cm, 1degree, odometry has unmodelel noise of 1cm
% and 1 degree per step
R = [0.01^2 0 0;
     0 0.01^2 0;
     0 0 degtorad(1)^2];
Q = [0.01^2 0;
     0 degtorad(1)^2];
% map_pent
% runlocalization_track('so_pb_10_outlier.txt', 'map_pent_big_10.txt',1,1,1,2)
% R = [0.01^2 0 0;
%      0 0.01^2 0;
%      0 0 degtorad(1)^2];
% Q = [0.2^2 0;
%      0 0.2^2];
% map_pent_big
% runlocalization_track('so_pb_40_no.txt', 'map_pent_big_40.txt',1,1,1,2)
% R = [1^2 0 0;
%      0 1^2 0;
%      0 0 1^2];
% Q = [0.1^2 0;
%      0 0.1^2];
% delta_m = 1;

Lambda_M = chi2inv(delta_m,2);
end