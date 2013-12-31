% function [mu_bar,sigma_bar] = predict(mu,sigma,u,R)
% This function should perform the prediction step.
% Inputs:
%           mu(t-1)           3X1   
%           sigma(t-1)        3X3
%           u(t)              3X1
%           R                 3X3
% Outputs:   
%           mu_bar(t)         3X1
%           sigma_bar(t)      3X3
function [mu_bar,sigma_bar] = predict(mu,sigma,u,R)

mu_bar = mu + u; % the predicted mean is the previous mean plus the control received

vtdt = u(1)/cos(mu(3)); % do not receive the velocity or the delta_t, so compute it from u(1)

G = [1 0 -sin(mu(3))*vtdt;
     0 1 cos(mu(3))*vtdt;
     0 0 1];

sigma_bar = G*sigma*G' + R;

end