% function [c,outlier, nu, S, H] = associate(mu_bar,sigma_bar,z_i,M,Lambda_m,Q)
% This function should perform the maximum likelihood association and outlier detection.
% Note that the bearing error lies in the interval [-pi,pi)
%           mu_bar(t)           3X1
%           sigma_bar(t)        3X3
%           R                   3X3
%           Q                   2X2
%           z_i(t)              2X1
%           M                   2XN
%           Lambda_m            1X1
% Outputs: 
%           c(t)                1X1
%           outlier             1X1
%           nu^i(t)             2XN
%           S^i(t)              2X2XN
%           H^i(t)              2X3XN
function [c,outlier, nu, S, H] = associate(mu_bar,sigma_bar,z_i,M,Lambda_m,Q)

S = [];
H = [];
psi = [];
nu = [];
Z = [];
% go over all landmarks in the map M
for k = 1:size(M,2)
    % based on our predicted position, make a prediction of the measurement
    % that we should receive, based on the observation model, looking at
    % the kth landmark on the map.
    Z(:,k) = observation_model(mu_bar,M,k);
    % calculate the linearisation of the observation model around the
    % point that was predicted in the previous step
    H(:,:,k) = jacobian_observation_model(mu_bar,M,k,Z(:,k),1);
    S(:,:,k) = H(:,:,k)*sigma_bar*H(:,:,k)' + Q;
    nu(:,k) = z_i - Z(:,k);
    nu(2,k) = mod(nu(2,k)+pi,2*pi)-pi;

    psi(k) = det(2*pi*S(:,:,k))^(-1/2)*exp((-1/2)*nu(:,k)'*inv(S(:,:,k))*nu(:,k));
end

[cmag c] = max(psi); % c is the arg, cmag is the value of that maximal index

nu_i = nu(:,c);
S_i = S(:,:,c);
D_m = nu_i'*inv(S_i)*nu_i;
outlier = logical(D_m >= Lambda_m);

end