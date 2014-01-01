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
    end
    
    methods
        function obj=kf_class(process_model, measurement_model, mu, sigma)
            % constructor for the kalman filter
            obj.Q = measurement_model;
            obj.R = process_model;
            obj.mu = mu;
            obj.sigma = sigma;
        end
        function kf_step(obj)
            mu_bar = mu + u; % the predicted mean is the previous mean plus the control received
            
            vtdt = u(1)/cos(mu(3)); % do not receive the velocity or the delta_t, so compute it from u(1)
            
            G = [1 0 -sin(mu(3))*vtdt;
                0 1 cos(mu(3))*vtdt;
                0 0 1];
            
            sigma_bar = G*sigma*G' + R;
            
            K=sigma_bar*H_bar'*inv(S_bar);
            mu_bar = mu_bar+K*nu_bar;
            sigma_bar = sigma_bar - K*H_bar*sigma_bar;
            sigma_bar = (sigma_bar + sigma_bar')/2;
        end
    end
    
end

