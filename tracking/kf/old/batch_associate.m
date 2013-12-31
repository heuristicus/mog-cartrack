% function [c,outlier, nu_bar, H_bar] = batch_associate(mu_bar,sigma_bar,z,M,Lambda_m,Q)
% This function should perform the maximum likelihood association and outlier detection.
% Note that the bearing error lies in the interval [-pi,pi)
%           mu_bar(t)           3X1
%           sigma_bar(t)        3X3
%           R                   3X3
%           Q                   2X2
%           z(t)                2Xn
%           M                   2XN
%           Lambda_m            1X1
% Outputs: 
%           c(t)                1Xn
%           outlier             1Xn
%           nu_bar(t)           2nX1
%           H_bar(t)            2nX3
function [c,outlier, nu_bar, H_bar] = batch_associate(mu_bar,sigma_bar,z,M,Lambda_m,Q)


nu_bar = [];
H_bar = [];
c = [];
outlier = [];
for i=1:size(z,2)
%     Z = [];
%     H = [];
%     S = [];
%     nu = [];
%     D = [];
%     psi = [];
%     for k=1:size(M,2)
%         Z(:,k) = observation_model(mu_bar,M,k);
%         H(:,:,k) = jacobian_observation_model(mu_bar,M,k,Z(:,k),1);
%         S(:,:,k) = H(:,:,k)*sigma_bar*H(:,:,k)' + Q;
%         nu(:,k) = z(:,i) - Z(:,k);
%         nu(2,k) = mod(nu(2,k)+pi,2*pi)-pi;
%         D(k) = nu(:,k)'*inv(S(:,:,k))*nu(:,k);
%         psi(k) = det(2*pi*S(:,:,k))^(-1/2)*exp((-1/2)*D(k));
%     end
    [maxind outl nuu ss hh] = associate(mu_bar, sigma_bar, z(:,i),M,Lambda_m,Q);
    
    c(i) = maxind;
    outlier(i) = outl;
    nu_bar = [nu_bar nuu(:,maxind)'];
    H_bar = [H_bar hh(:,:,maxind)'];
end
H_bar = H_bar';
nu_bar = nu_bar';
end