classdef pf_class < handle
    %PF_CLASS Summary of this class goes here
    %  Class which encompasses the particle filter allowing multiple
    %  instances to be initialised. The constructor allows the definition
    %  of the noise models, as well as the number of particles and the
    %  initial values passed to the filter.
    
    properties
        % Individual particles. Each represents the state of the system,
        % and so S is a matrix of N+1xM, where N is the number of state
        % variables and M is the number of particles. The final row of the
        % matrix is the weight for each particle.
        S
        % Process noise model
        R 
        % Measurement noise model
        Q
        % number of particles
        M
        % size of the state vector
        N
    end
    
    methods
        function obj=pf_class(num_particles, process_model, measurement_model, bbox)
            % particle filter constructor. Process model should be a 4x4
            % matrix, measurement model should be a ? matrix.
            
            % only initialise stuff if there are parameters passed. This is
            % required to create arrays of pf_class objects
            if nargin > 0
                % bbox is in a weird format sometimes - convert to double
                bbox = double(bbox);
                % Initialises the particle filter with the given number of
                % particles and the given process models. Particles are
                % initialised within the given bounding box bbox, which is
                % defined by the x,y of the top left corner and its width and
                % height.
                obj.R = process_model;
                obj.Q = measurement_model;
                obj.N = 4; % four state components, x, y, and velocities in those directions
                obj.M = num_particles;
                % initialise particles randomly within the bounding box
                % specified
                obj.S = [rand(1,obj.M) * bbox(3) + bbox(1);
                         rand(1,obj.M) * bbox(4) + bbox(2);
                         randn(1,obj.M); % random velocity in x
                         randn(1,obj.M); % random velocity in y
                         ones(1,obj.M) * 1/obj.M]
                     obj.S
                % initialise particles normally distributed around the mean
                % with variance 1
                %             obj.S = [(randn(obj.N,obj.M) + 1).* repmat(mu,1,obj.M);
                %                      ones(1,obj.M)*1/obj.M];
            end
        end
        function pf_predict(obj, dt)
            % Use this to predict the next state for each particle based on
            % its current state. Assuming that we have no information other
            % than the current state of the filter based on the observation
            % we made in the previous frame.
            
            % propagate particles based on their current position, the two velocity
            % components and the time elapsed. We assume that the velocity
            % is modified only by the noise.
            obj.S(1:2,:) = [obj.S(1,:) + obj.S(3,:) * dt;
                            obj.S(2,:) + obj.S(4,:) * dt];
                            obj.S
            % generate random noise and multiply it by the process noise covariance
            rn = randn(obj.M,4) * obj.R;
            % add a column of zeros and take the transpose to make a 4xM matrix
            noise = [rn zeros(obj.M,1)]';
            obj.S = obj.S + noise;
        end
    end
end

