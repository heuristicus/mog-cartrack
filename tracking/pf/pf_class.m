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
        % noise model inverse
        Qinv
        % number of particles
        M
        % size of the state vector
        N
        % keep track of the measurements received over time. There could be
        % a different number of measurements each timestep, so this is a
        % cell array where the measurements for each timestep are one cell,
        % and each measurement is a column of the matrix in the form [x y xvel yvel]'
        % the values xvel and yvel are not measured directly but are
        % computed from the previous measurement and the one received in
        % the current timestep
        measurements
        % keep track of the cluster centres in the cloud. There could be a
        % different number of centres each timestep, so this is a cell
        % array. Each cell contains the cluster means for a given timestep
        % in the form [x y xvel yvel; ...]' (columns correspond to
        % clusters)
        cluster_means
        % keep track of the number of steps taken
        stepnum
        vel_std
        particle_min_limit
    end
    
    methods
        function obj=pf_class(num_particles, process_model, measurement_model, centroids, bboxes, particle_min_limit, vel_std)
            % particle filter constructor. Process model should be a 4x4
            % matrix, measurement model should be a ? matrix.
            % particle_min_limit is the minimum percentage of the total
            % number of particles that can be assigned to any single
            % measurement. Its value should be between 0 and 1.
            
            % only initialise stuff if there are parameters passed. This is
            % required to create arrays of pf_class objects
            if nargin > 0
                % define the particle limit if one is not passed. Use 0.1
                % unless there care more than 10 measurements
                if nargin < 6
                    particle_min_limit = min(0.1, 1/size(centroids,1));
                end
                % define the standard deviation of the gaussian from which
                % velocity is sampled if the velocity from a measurement is
                % zero
                if nargin < 7
                    vel_std = 1;
                end
                
                % bbox is in a weird format sometimes - convert to double
                bboxes = double(bboxes);
                % Initialises the particle filter with the given number of
                % particles and the given process models. Particles are
                % initialised within the given bounding box bbox, which is
                % defined by the x,y of the top left corner and its width and
                % height.
                obj.R = process_model;
                obj.Q = measurement_model;
                obj.Qinv = inv(measurement_model);
                obj.N = 4; % four state components, x, y, and velocities in those directions
                obj.M = num_particles;
                obj.vel_std = vel_std;
                obj.particle_min_limit = particle_min_limit;
                
                % Initialise the object measurements with zero initial velocity
                obj.measurements = {[centroids zeros(size(centroids,1),2)]'};
                
                % Initialise particles in the filter. Since this is the
                % first initialisation we initialise all particles based on
                % the measurements
                obj.S = obj.init_particles(obj.measurements{1}, bboxes, obj.vel_std, obj.M);
                
                % Compute the cluster centres and the particles belonging
                % to them
                [idx] = kmeans(obj.S(1:2,:)', size(centroids,1));
                % Compute the mean of each cluster
                mn = [];
                for i=1:size(centroids,1)
                   cluster_particles = obj.S(1:4,idx==i);
                   mn = [mn mean(cluster_particles,2)];
                end
                obj.cluster_means = {mn};
                obj.stepnum = 1;
            end
        end
        function particles=init_particles(obj, measurements, bboxes, vel_std, init_num, gaussian_position)
            % initialise particles based on the measurements given. The
            % measurements are expected to be column vectors of the form
            % [x y xvel yvel]'. If xvel and yvel are not yet computed, then
            % set the velocities to zero and a velocity will be generated
            % from a zero mean gaussian with standard deviation of 1. If
            % the vel_std parameter is provided, that will be used as the
            % standard deviation instead. The init_num parameter defines
            % how many particles will be initialised with this function.
            % The gaussian_position variable should be set to zero to use a
            % uniform distribution within the bounding box to initialise
            % particles. If >1, the particles will be initialised using a
            % gaussian which has standard deviation of 
            
            if nargin < 6
                gaussian_position = 0;
            end
            
            % Initialise particles randomly based on the measurements
            % received and their corresponding bboxes. Currently, the
            % number of particles assigned to each box is proportional
            % to its size, with a limit on the minimum number assigned
            box_areas = prod(bboxes(:,3:4),2); % area = width * height
            total_box_area = sum(box_areas);
            box_proportions = box_areas/total_box_area;
            
            remaining_particles = init_num;
            % define the limit on the minimum number of particles
            min_particles = obj.particle_min_limit * init_num;
            particles = [];
            for i=1:size(measurements,2)
                % First, we make sure that the number of particles is
                % greater than the minimum, and then less than or equal
                % to the number of remaining particles
                nparticles = round(min(remaining_particles, max(box_proportions(i) * obj.M, min_particles)));
                % subtract the number of particles to initialise from this
                % centre from the total number to be initialised
                remaining_particles = remaining_particles - nparticles;
                % define the x y positions and the corresponding
                % directional velocities for each particle
                if gaussian_position
                    maxlen = max(bboxes(i,3), bboxes(i,4));
                    initpart = [randn(1,nparticles) * maxlen + measurements(1,i);
                        randn(1,nparticles) *maxlen + measurements(2,i);
                        randn(1,nparticles) * vel_std; % random velocity in x
                        randn(1,nparticles) * vel_std; % random velocity in y
                        ones(1,nparticles) * 1/obj.M]; % all particles in the whole set have the same weight
                else
                    initpart = [rand(1,nparticles) * bboxes(i,3) + bboxes(i,1);
                        rand(1,nparticles) * bboxes(i,4) + bboxes(i,2);
                        randn(1,nparticles) * vel_std; % random velocity in x
                        randn(1,nparticles) * vel_std; % random velocity in y
                        ones(1,nparticles) * 1/obj.M]; % all particles in the whole set have the same weight
                end
                
                % this is probably slow - fill up an initial zero matrix
                % instead
                particles = [particles initpart];
            end
        end
        function pf_step(obj, dt, centroids)
            obj.stepnum = obj.stepnum + 1;
            prev_measurements = obj.measurements{1, obj.stepnum - 1};
            % predict the motion of the particles based on their current
            % velocities and the time elapsed
            obj.pf_predict(dt);
            % use k-means clustering to find the clusters of particles
            % corresponding to different objects. The number of centres
            % correspond to the number of measurements that we receive.
            % This allows the cluster centres to be matched with the
            % measurements, and we can use this information to find those
            % measurements which are not yet represented in the filter.
            [idx, centres] = kmeans(obj.S(1:2,:)', size(centroids,1))
            
            obj.cluster_means(1,obj.stepnum) = {[centres]};
            
            % !!!!!THIS IS NOT CORRECT!!!!!
            % need to extract the centroid which corresponds to the one
            % which this filter is tracking
            matched_centroid = centroids(1,:); % FIX THIS
            if size(matched_centroid,2) ~= 1
                matched_centroid = matched_centroid';
            end
            last_measurement = obj.measurements(:,end);
            object_velocity = last_measurement(1:2) - matched_centroid;
            measurement = [matched_centroid;
                           object_velocity]
            
            obj.measurements{1,obj.stepnum} = measurement;
            
            obj.pf_weight(measurement)
            obj.pf_resample()
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
            
            % each particle is attempting to represent the motion of the
            % object, and so we do not have any observation model (?)
            % As a result, nu contains simply the differences between each
            % particle and the measurement of the position of the object
            % that has been received
            nu = msrep - obj.S(1:4,:);
            
            p = diag(normalisation*exp(-0.5*nu'*obj.Qinv*nu))';
            p = p/sum(p);
            obj.S(5,:)=p;
        end
        function pf_resample(obj)
            % cumulative sum of the particle weights
            cdf = cumsum(obj.S(5,:));
            % initial random value between 0 and 1/M
            r_0 = rand / obj.M;
            % initialise a new particle matrix in which to store selected
            % particles
            new_particles = zeros(5,obj.M);
            % loop over all particles and choose the particle to carry over
            % to the next timestep
            for m = 1 : obj.M
                % the new particle is the one corresponding to the index
                % in the cdf which exceeds the current random number
                new_particles(:,m) = obj.S(:,find(cdf >= r_0,1,'first'));
                % the random number is incremented by 1/M each time
                r_0 = r_0 + 1/obj.M;
            end
            % the new particles are all given a uniform weight
            new_particles(5,:) = 1/obj.M*ones(1,obj.M);
            % put the new particles into the object
            obj.S = new_particles;
        end
    end
end

