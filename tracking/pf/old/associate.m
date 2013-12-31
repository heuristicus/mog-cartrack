% function [outlier,Psi] = associate(S_bar,z,W,Lambda_psi,Q)
%           S_bar(t)            4XM
%           z(t)                2Xn
%           W                   2XN
%           Lambda_psi          1X1
%           Q                   2X2
% Outputs: 
%           outlier             1Xn
%           Psi(t)              1XnXM
function [outlier,Psi] = associate(S_bar,z,W,Lambda_psi,Q)
    if isempty(z)
        outlier = [0];
        np = size(S_bar,2);
        Psi = S_bar(4,:);
    else
        % sizes for all the relevant bits
        nlandmarks = size(W,2);
        nobservations = size(z,2);
        nparticles = size(S_bar,2);
        
        % extract the diagonal of the inverse of Q. This is only valid if
        % the measurement noise matrix is diagonal
        qinvdiag = diag(inv(Q));
        % repeat the diagonal of Q to make a matrix that corresponds to the
        % size of the nu matrices that will be created
        bigQ=repmat(qinvdiag, [1 nlandmarks nparticles]);
        
        % precalculate the normalisation constant
        normalisation = 1/(2*pi*sqrt(det(Q)));
        Z=zeros(2,size(S_bar,2),nlandmarks);
        Psi = zeros(1,max(1,nobservations),nparticles);
        % precompute values for k so that they do not have to be recomputed
        for k=1:nlandmarks
            Z(:,:,k)=observation_model(S_bar,W,k);
        end
        
        % fix Z so that the dimensions correspond to the dimensions we will
        % use later in psi
        Z = permute(Z,[1 3 2]);
        
        for i=1:nobservations
            % find the innovations for all particles and all landmarks by
            % creating a matrix of the repeated actual observation of the
            % same size as that of all of the predicted observations
            nu(1,:,:) = z(1,i) - Z(1,:,:);
            nu(2,:,:) = z(2,i) - Z(2,:,:);
            %nu = repmat(z(:,i),[1,nlandmarks,nparticles]) - Z;
            % normalise the headings
            nu(2,:,:)=mod(nu(2,:,:)+pi,2*pi)-pi;
            % Because of our diagonality assumption, we can do a pointwise
            % multiplication instead of a normal matrix multiplication,
            % speeding things up a lot. Because we did a pointwise
            % multiplication, after doing the multiplication and taking the
            % exponent, we must sum the first dimension of psi. 
            % example: a = [1 2]' q=eye(2)
            %          a'*q*a is equivalent to sum(a.*diag(q).*a)
            % or in the 2D case, a = reshape(1:10,2,5)' q = eye(2), the
            % same holds, but this time we get a vector instead of a scalar
            % value. assume that each row of a is the innovation and the
            % columns represent different particles. In the 3d case, after
            % summing we get an nparticles x nlandmarks matrix, where each
            % column contains the likelihood for each landmark for each
            % particle
            psi = squeeze(exp(sum(-0.5.*nu.*bigQ.*nu,1)));
            % We are only interested in the landmark which maximises the
            % likelihood of the current observation for each particle
            Psi(1,i,:) = normalisation*max(psi,[],1);
        end
        % Check whether the mean value of each row of psi is an outlier or not
        outlier = mean(reshape(Psi, nobservations, nparticles),2) <= Lambda_psi;
    end
end