classdef kf_class < handle
    %KF_CLASS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        % measurement model
        Q
        % process model
        R
        % mean of the gaussian
        mu
        % variance of the gaussian
        sigma
        % number of frames without updating
        noUpdateCounter
        NO_UPDATE_TIME_MAX = 10 %Max number of frames we allow not to update
        % time step
        dt
        % Threshold on the Mahalanobis distance
        lambdaM
    end
    
    methods
        function obj=kf_class(params,mu)
            % constructor for the kalman filter
            obj.Q = params.Q;
            obj.R = params.R;
            obj.mu = mu;
            obj.sigma = params.sigma0;
            obj.noUpdateCounter=0;
            obj.dt = params.dt;
            obj.lambdaM = chi2inv(params.deltaM,4);
        end
        function [outliers] = kf_step(obj,measurements)
            
            %----Predict Step----
            [mu_bar, sigma_bar] = obj.kf_predict(obj.mu, obj.sigma,obj.dt,obj.R);            
            %----Associate-----
            [outliers,S,nu] = obj.kf_associate(mu_bar,sigma_bar,measurements);            
            %----Update
            available = ~isempty(find(outliers==0,1)); %At least a measurement is not an outlier

            if(available)
                [obj.mu, obj.sigma] = obj.kf_update(mu_bar,sigma_bar,S,nu);
                obj.noUpdateCounter = 0; %Restart counter!!
            else
                obj.mu = mu_bar;
                obj.sigma = sigma_bar;
                obj.noUpdateCounter = obj.noUpdateCounter + 1;
            end
        end
        
        function [mu_bar, sigma_bar] = kf_predict(obj,mu,sigma,dt,R)
%         Predict step of the Standard Kalman Filter
%         We assume the following state vector:
%         x = [x,y, w, h, vx, vy]'
%         Inputs:
%                 mu:             6x1
%                 sigma:          6x6
%         Outputs:
%                 mu_bar:         6x1
%                 sigma_bar:      6x6
            A =[1 0 0  0  dt 0;
                0 1 0  0  0 dt;
                0 0 1  0  0 0;
                0 0 0  1  0 0;
                0 0 0  0  1 0;
                0 0 0  0  0 1];
            mu_bar = A*mu;
            sigma_bar = A*sigma*A' + R;                    
        end
        
        function [outliers,S,nu] = kf_associate(obj,mu_bar,sigma_bar,measurements)
%            Performs Mahimum Likelihood Association from the set of measurements
%            to the current Kalman Filter. 
%             Inputs:
%                     mu_bar:             6x1
%                     sigma_bar:          6x6
%                     measurements:       4xn    
%             Outputs:
%                     z:                  4x1
%                     outliers:           nx1            
            n = size(measurements,2);
            N = size(measurements,1); %Dimension
            
            H = obj.observation_model();
            S = H*sigma_bar*H'+obj.Q;
            Sinv = inv(S);
            
            zi_hat = H*mu_bar;
            norm = 1/( ((2*pi)^(N/2))*(det(S))^0.5 );
            
            phi = zeros(n,1); %Likelihood
            D   = zeros(n,1); %Mahalanobis Distance
            nus = zeros(N,n);
            for i=1:n %Possible factorization?
                zi = measurements(:,i);
                nus(:,i) = zi-zi_hat;
                D(i) = nus(:,i)'*Sinv*nus(:,i);
                phi(i) = norm*exp(-0.5*D(i));
            end
            outliers = D>obj.lambdaM;
            %Take the most likely measurement
            [~,iMax] = max(phi,[],1);
            nu = nus(:,iMax);
        end
        
        function [H] = observation_model(obj)
            H = [1 0 0 0 0 0;
                0 1 0 0 0 0;
                0 0 1 0 0 0;
                0 0 0 1 0 0];
        end
        
        function [mu,sigma] = kf_update(obj,mu_bar,sigma_bar,S,nu)
%         Update step of the Standard Kalman Filter
%         Inputs:
%                 mu_bar:             6x1
%                 sigma_bar:          6x6
%                 R:                  6x6
%                 z:                  4x1
%         Outputs:
%                 mu:                 6x1
%                 sigma:              6x6            
            
            H = obj.observation_model();
            K = sigma_bar*(H'/S);
            mu = mu_bar + K*nu;
            sigma = sigma_bar - K*H*sigma_bar;        
            sigma = (sigma + sigma')/2; %Make sigma symmetric
        end
    end
    
end

