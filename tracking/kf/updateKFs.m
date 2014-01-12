function [filters,outliers] = updateKFs(filters,measurements)
%UPDATEKFS Summary of this function goes here
%   Detailed explanation goes here
% It updates the current Kalman Filters based on the received
% measurements. It also outpus an "outlier" vector which is
% 1 for each measurement that has not been used to update
% in any of the KF. 
% 
% Inputs:
%                 filters:            Mx1 array of struct kf_class
%                 measurements:       4xn
%                 
% Outputs:
%                 filters:            Mx1 array of struct kf_class
%                 outliers:           nx1

M = size(filters);        %Number of filters
n = size(measurements,2); %Number of measurements
N = size(measurements,1); %Dimension of measurement vector

outliersT = ones(M,n);
outliers = ones(n,1);

phiT = zeros(n,M);
nuT = zeros(n,M,N);
ST = zeros(N,N,M);

if isempty(measurements) 
    for i=1:M
        kf = filters(i);
        nu = [];
        S = [];
        outlier = 1;
        kf.kf_step(S,nu,outlier);
    end    
else
    %First, make a one-to-one correspondence between filters and measurements
    for i=1:M
        kf = filters(i);

        [mu_bar, sigma_bar] = kf.kf_predict(kf.mu, kf.sigma,kf.dt,kf.R);
        H = kf.observation_model();
        S = H*sigma_bar*H'+kf.Q;
        ST(:,:,i) = S;
        Sinv = inv(S);
        z_hat = H*mu_bar;
        norm = 1/( ((2*pi)^(N/2))*(det(S))^0.5 );
        D   = zeros(n,1); %Mahalanobis Distance
        for j=1:n
            zj = measurements(:,j);
            nuT(j,i,:) = zj-z_hat; %4x1
            nu = reshape(nuT(j,i,:),4,1);
            D(j) = nu'*Sinv*nu;
            phiT(j,i) = norm*exp(-0.5*D(j));
        end
        outliersT(i,:) = D>kf.lambdaM;
        %We AND with previous outliers so that only the ones common to all KF
        %remain
        outliers = outliers & outliersT(i,:)';
    end

    %Get correspondances and update corresponding filters
    [phiMax,maxFilters] = max(phiT,[],2); %nx1 Gives best filter for each measurement
    [phiMax2,maxMeasurements] = max(phiT,[],1);%Mx1 Gives best measuremente for each filter

    for i=1:M
        kf = filters(i);
        idx = find(i==maxFilters, 1);
        if ~isempty(idx) %The filter is the most likely for a measurement
            bestFilterMeasurement = maxMeasurements(i);%The best measurement for the filter            
            if maxFilters(bestFilterMeasurement) == i %Update only if this is best measurement for best filter
                S = reshape(ST(:,:,i),N,N);
                nu = reshape(nuT(bestFilterMeasurement,i,:),N,1);
                outlier = 0;
                kf.kf_step(S,nu,outlier);
            end
        else
            nu = [];
            S = [];
            outlier = 1;
            kf.kf_step(S,nu,outlier);
        end

        outliers = outliers & outliersT(i,:)';
    end
end
    
end


