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
        % keep track of the measurements received over time
        measurements
        % keep track of the cloud means of the particle cloud
        cloud_mean
    end
    
    methods
        function obj=pf_class(num_particles, process_model, measurement_model, centroid, bbox)
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
                         ones(1,obj.M) * 1/obj.M];
                     centroid
                if size(centroid, 2) ~= 1
                    centroid = centroid';
                end
                centroid
                obj.measurements = centroid;
                obj.cloud_mean = mean(obj.S(1:4,:), 2);
            end
        end
        function pf_step(obj, dt, centroids)
            % predict the motion of the particles based on their current
            % velocities and the time elapsed
            obj.pf_predict(dt);
            obj.cloud_mean = [obj.cloud_mean mean(obj.S(1:4,:),2)];
            
            % !!!!!THIS IS NOT CORRECT!!!!!
            % need to extract the centroid which corresponds to the one
            % which this filter is tracking
            matched_centroid = centroids(1,:); % FIX THIS
            if size(matched_centroid,2) ~= 1
                matched_centroid = matched_centroid';
            end
            matched_centroid
            last_measurement = obj.measurements(:,end)
            object_velocity = last_measurement - matched_centroid
            measurement = [matched_centroid;
                           object_velocity];
            
            obj.measurements = [obj.measurements matched_centroid];
            
            obj.pf_weight(measurement)
            obj.pf_resample()
            
            % !!!!!THIS IS NOT CORRECT!!!!!
            
            
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
            % generate random noise and multiply it by the process noise covariance
            rn = randn(obj.M,4) * obj.R;
            % add a column of zeros and take the transpose to make a 5xM matrix
            noise = [rn zeros(obj.M,1)]';
            % add the noise to each particle
            obj.S = obj.S + noise;
        end
        function pf_weight(obj, measurement)
            % reweight the particles in the cloud based on their
            % probability having made the measurement provided.
            normalisation = 1/(2*pi*sqrt(det(obj.Q)));
            % repeat the measurement made so that all particles can be
            % compared
            msrep = repmat(measurement,1,obj.M);
            p = zeros(1,obj.M);
            
            % each particle is attempting to represent the motion of the
            % object, and so we do not have any observation model (?)
            % As a result, nu contains simply the differences between each
            % particle and the measurement of the position of the object
            % that has been received
            nu = msrep - obj.S(1:4,:);

            p = diag(normalisation*exp(-0.5*nu'*(obj.Q\nu)))'
            p = p/sum(p)
            obj.S(5,:)=p;
        end
        function pf_resample(obj)
            [val, ind] = max(obj.S(5,:))
            obj.S(1:4,:) = repmat(obj.S(1:4,ind),1,obj.M);
        end
    end
end

