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
        % time step
        dt
    end
    
    methods
        function obj=kf_class(process_model, measurement_model, mu, sigma,dt)
            % constructor for the kalman filter
            obj.Q = measurement_model;
            obj.R = process_model;
            obj.mu = mu;
            obj.sigma = sigma;
            obj.noUpdateCounter=0;
            obj.dt = dt;
        end
        function kf_step(obj,measurements)
            
            %----Predict Step----
            [mu_bar, sigma_bar] = obj.kf_predict(obj.mu, obj.sigma,obj.dt,obj.R);            
            %----Check if available measurement---
            % TODO
            
            %----Update
            available = 1;
            if(available)
                [obj.mu, obj.sigma] = obj.kf_update(mu_bar,sigma_bar,obj.Q,measurements);
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
        
        function [mu,sigma] = kf_update(obj,mu_bar,sigma_bar,Q,z)
%         Update step of the Standard Kalman Filter
%         Inputs:
%                 mu_bar:             6x1
%                 sigma_bar:          6x6
%                 R:                  6x6
%                 z:                  4x1
%         Outputs:
%                 mu:                 6x1
%                 sigma:              6x6            
            H = [1 0 0 0 0 0;
                 0 1 0 0 0 0;
                 0 0 1 0 0 0;
                 0 0 0 1 0 0];
             
            K = sigma_bar*(H'/(H*sigma_bar*H'+Q));
            mu = mu_bar + K*(z-H*mu_bar);
            sigma = sigma_bar - K*H*sigma_bar;        
            sigma = (sigma + sigma')/2; %Make sigma symmetric
        end
    end
    
end

