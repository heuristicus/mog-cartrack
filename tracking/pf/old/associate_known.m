% function [outlier,Psi] = associate_known(S_bar,z,W,Lambda_psi,Q,known_associations)
%           S_bar(t)            4XM
%           z(t)                2Xn
%           W                   2XN
%           Lambda_psi          1X1
%           Q                   2X2
%           known_associations  1Xn
% Outputs: 
%           outlier             1Xn
%           Psi(t)              1XnXM
function [outlier,Psi] = associate_known(S_bar,z,W,Lambda_psi,Q,known_associations)

    nparticles = size(S_bar,2);
    nobservations = size(z,2);
    normalisation = 1/(2*pi*sqrt(det(Q)));
    qinv = inv(Q);
    zmat = repmat(z,1,nparticles);
    Psi = zeros(nobservations,nparticles);
    for i=1:nobservations
        obs_hypotheses = observation_model(S_bar,W,known_associations(i));
        nu = zmat - obs_hypotheses;
        size(nu)
        size(Psi)
        nu(2,:)=mod(nu(2,:)+pi,2*pi)-pi;
        Psi(i,:)=diag(normalisation*exp(-0.5*nu'*qinv*nu))';
    end
    prod(Psi,1)
    Psi = reshape(Psi,1,nobservations,nparticles);
end
