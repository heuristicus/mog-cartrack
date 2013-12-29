% function [S_bar] = predict(S,u,R)
% This function should perform the prediction step of MCL
% Inputs:
%           S(t-1)              4XM
%           v(t)                1X1
%           omega(t)            1X1
%           R                   3X3
%           delta_t             1X1
% Outputs:
%           S_bar(t)            4XM
function [S_bar] = predict(S,v,omega,R,delta_t)

% extract the number of particles
sdim = size(S,2);

% generate the motion for each particle based on the velocity and the angle
% of the particle at the previous time step. Pad the matrix so that it can
% be added to the S, which contains the weights of the particles as well.
u = [v * delta_t * cos(S(3,:));
     v * delta_t * sin(S(3,:));
     repmat(omega*delta_t,1,sdim); % all particles have the same angle transition
     zeros(1,sdim)]; % repeat zeros on the bottom of the matrix

% generate random noise and multiply it by the process noise covariance
rn = randn(sdim,3) * R;
% add a column of zeros and take the transpose to make a 4 x sdim matrix
noise = [rn zeros(sdim,1)]';

S_bar = S + u + noise;

end