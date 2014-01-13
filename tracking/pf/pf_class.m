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
        % repeated diagonals of Qinv, used in a scalar multiplication to
        % speed thing up
        bigQ
        % number of particles
        total_particles
        % number of particles which are resampled from the original
        % posterior, not from the measurements
        resampled_particles
        % number of particles initialised from the measurements at each
        % timestep
        measurement_particles
        % keep track of the measurements received over time. There could be
        % a different number of measurements each timestep, so this is a
        % cell array where the measurements for each timestep are one cell,
        % and each measurement is a column of the matrix in the form [x y xvel yvel]'
        % the values xvel and yvel are not measured directly but are
        % computed from the previous measurement and the one received in
        % the current timestep
        measurements
        % keep track of the bboxes received over time
        bboxes
        % keep track of the cluster centres in the cloud. There could be a
        % different number of centres each timestep, so this is a cell
        % array. Each cell contains the cluster means for a given timestep
        % in the form [x y xvel yvel; ...]' (columns correspond to
        % clusters)
        cluster_means
        % keep track of the number of steps taken
        stepnum
        % the standard deviation of the velocity assigned to particles when
        % initialising them.
        vel_std
        % the minimum percentage of the number of particles being
        % initialised which can be assigned to a single measurement.
        particle_min_limit
        % the normalisation constant used when reweighting particles
        normalisation
        initialised
        %To decide whether to use systematic(0) or stratified(1) resampling
        resampling = 0;
    end
    
    methods
        function obj=pf_class(num_particles, process_model, measurement_model, centroids, bboxes, particle_min_limit, vel_std, measurement_particle_prop)
            % particle filter constructor. Process model should be a 4x4
            % matrix, measurement model should be a ? matrix.
            % particle_min_limit is the minimum percentage of the total
            % number of particles that can be assigned to any single
            % measurement. Its value should be between 0 and 1.
            % vel_std is the standard deviation which defines the spread of
            % the gaussian used to initialise the velocity of particles
            % measurement_particle_prop defines the proportion of particles
            % to be reinitialised onto the measurements at the beginning of
            % each timestep in order to allow the addition of new objects
            
            % only initialise stuff if there are parameters passed. This is
            % required to create arrays of pf_class objects
            if nargin > 0
                % define the particle limit if one is not passed. Use 0.1
                % unless there care more than 10 measurements
                if nargin < 6
                    if nargin > 4
                        particle_min_limit = min(0.1, 1/size(centroids,1));
                    else
                        particle_min_limit = 0.1;
                    end
                    
                end
                % define the standard deviation of the gaussian from which
                % velocity is sampled if the velocity from a measurement is
                % zero
                if nargin < 7
                    vel_std = 10;
                end
                
                if nargin < 8
                    measurement_particle_prop = 0.3;
                end
                
                
                % Initialises the particle filter with the given number of
                % particles and the given process models. Particles are
                % initialised within the given bounding box bbox, which is
                % defined by the x,y of the top left corner and its width and
                % height.
                obj.R = process_model;
                obj.Q = measurement_model;
                obj.Qinv = inv(measurement_model);
                obj.normalisation = 1/(((2*pi)^2)*sqrt(det(obj.Q)));
                obj.total_particles = num_particles;
                obj.measurement_particles = round(measurement_particle_prop * obj.total_particles);
                obj.resampled_particles = obj.total_particles - obj.measurement_particles;
                obj.vel_std = vel_std;
                obj.particle_min_limit = particle_min_limit;
                obj.bigQ=repmat(diag(obj.Qinv),1,obj.total_particles);
                
                % if we are not passed any centroids or bboxes, just
                % initialise the parameters, not the particles. Indicate
                % the non-initialised state by the initialised flag
                if nargin < 4
                    obj.initialised = 0;
                    obj.measurements{1,1} = [];
                    obj.bboxes{1,1} = [];
                    obj.cluster_means{1,1} = [];
                else
                    % bbox is in a weird format sometimes - convert to double
                    bboxes = double(bboxes);
                    % Initialise the object measurements with zero initial velocity
                    obj.measurements{1,1} = [centroids zeros(size(centroids,1),2)]';
                    obj.bboxes{1,1} = bboxes;
                    
                    % Initialise particles in the filter. Since this is the
                    % first initialisation we initialise all particles based on
                    % the measurements
                    obj.S = obj.init_particles(obj.measurements{1}, bboxes, obj.total_particles, obj.vel_std);
                    
                    % Compute the cluster centres and the particles belonging
                    % to them
                    [idx] = kmeans(obj.S(1:2,:)', size(centroids,1));
                    % Compute the mean of each cluster
                    mn = [];
                    for i=1:size(centroids,1)
                        cluster_particles = obj.S(1:6,idx==i);
                        mn = [mn mean(cluster_particles,2)];
                    end
                    obj.cluster_means{1,1} = mn;
                    obj.initialised = 1;
                end
                obj.stepnum = 1;
            end
        end
        function particles=init_particles(obj, measurements, bboxes, init_num, vel_std, gaussian_position)
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
            % particles. If >0, the particles will be initialised using a
            % gaussian which has standard deviation of vel_std
            
            if nargin < 6
                gaussian_position = 0;
            end
            
            bboxes = double(bboxes);
            
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
                if i == size(measurements,2)
                    nparticles = remaining_particles;
                else
                    nparticles = round(min(remaining_particles, max(box_proportions(i) * init_num, min_particles)));
                end
                % subtract the number of particles to initialise from this
                % centre from the total number to be initialised
                remaining_particles = remaining_particles - nparticles;
                % define the x y positions and the corresponding
                % directional velocities for each particle, as well as the
                % width and height of the bounding box for that particle,
                % which we obtain from the measurement
                if gaussian_position
                    maxlen = max(bboxes(i,3), bboxes(i,4));
                    initpart = [randn(1,nparticles) * maxlen + measurements(1,i);
                                randn(1,nparticles) *maxlen + measurements(2,i);
                                bboxes(i,3) * ones(1,nparticles);
                                bboxes(i,4) * ones(1,nparticles)];
                else
                    initpart = [rand(1,nparticles) * bboxes(i,3) + bboxes(i,1);
                                rand(1,nparticles) * bboxes(i,4) + bboxes(i,2);
                                bboxes(i,3) * ones(1,nparticles);
                                bboxes(i,4) * ones(1,nparticles);];
                end
                
                % if the velocities are nonzero for this measurement (i.e.
                % it has been seen before and we have updated the
                % velocities), then we initialise the particles with
                % velocities close to that initial velocity. Otherwise, we
                % define a random velocity.
                % ???? maybe better to skip those measurements which have
                % already been seen and just work on new ones?
                if sum(measurements(3:4,i)) == 0
                    initpart = [initpart;
                                % velocities randomly selected
                                vel_std*randn(1,nparticles);
                                vel_std*randn(1,nparticles);
                                ones(1,nparticles) * 1/obj.total_particles];
                else
                    initpart = [initpart;
                                % velocities based on previous value
                                vel_std*randn(1,nparticles) + measurements(3,i);
                                vel_std*randn(1,nparticles) + measurements(4,i);
                                ones(1,nparticles) * 1/obj.total_particles];
                end
               
                % this is probably slow - fill up an initial zero matrix
                % instead
                particles = [particles initpart];
            end
        end
        function trackedObjects=pf_step(obj, dt, centroids, bboxes)
            
            bboxes = double(bboxes); % stupid bbox format
            obj.stepnum = obj.stepnum + 1;
            reinitialised = 0;
            
            % if there are no measurements received, there is nothing left
            % to track
            % this is an incorrect assumption if multiple things are
            % occluded!
            if isempty(centroids) || isempty(bboxes)
                obj.bboxes{1,obj.stepnum} = [];
                obj.measurements{1,obj.stepnum} = [];
                obj.initialised = 0;
                trackedObjects=[];
                return
            end
            
            if obj.initialised == 0
                obj.S = obj.init_particles([centroids zeros(size(centroids,1),2)]', bboxes, obj.total_particles, obj.vel_std);
                reinitialised = 1;
                obj.initialised = 1;
            end
            
            % initialise M particles on all of the measurements received in
            % the PREVIOUS timestep. In the first timestep this is not
            % necessary as all particles are initialised in this way
            % regardless.
            if obj.stepnum > 2 && reinitialised ~= 1
                prev_measurements = obj.measurements{1, obj.stepnum - 1};
                prev_bboxes = obj.bboxes{1, obj.stepnum -1};
                part = obj.init_particles(prev_measurements, prev_bboxes, obj.measurement_particles,obj.vel_std);
                obj.S = [obj.S part];
            end
            
            % predict the motion of the particles based on their current
            % velocities and the time elapsed
            obj.pf_predict(dt);
            
            % reweight the particles according to their proximity to the
            % nearest measurement
            obj.pf_weight([centroids,bboxes(:,3),bboxes(:,4)]);        
            
            obj.bboxes{1,obj.stepnum} = bboxes;
            obj.measurements{1,obj.stepnum} = [centroids zeros(size(centroids,1),2)]';
            
            obj.pf_resample(obj.resampling,size(centroids,1));

            % compute clusters using kmeans - these should correspond to
            % the number of objects in the scene
            [idx] = kmeans(obj.S(1:2,:)', size(centroids,1),'emptyaction','singleton','replicates',5);
            % Compute the mean of each cluster
            mn = [];
            for i=1:size(centroids,1)
                cluster_particles = obj.S(1:6,idx==i);
                %For some strange reason, kmeans creates clusters with no
                %particles => don't take them into consideration.
                if ~isempty(cluster_particles) 
                    mn = [mn mean(cluster_particles,2)];
                end
            end
            obj.cluster_means{1,obj.stepnum} = mn;
            trackedObjects = mn;
        end
        function pf_predict(obj, dt)
            % Use this to predict the next state for each particle based on
            % its current state. Assuming that we have no information other
            % than the current state of the filter based on the observation
            % we made in the previous frame.
            
            % propagate particles based on their current position, the two velocity
            % components and the time elapsed. We assume that the velocity
            % is modified only by the noise.
            obj.S(1:2,:) = [obj.S(1,:) + obj.S(5,:) * dt;
                            obj.S(2,:) + obj.S(6,:) * dt];
            % generate random noise and multiply it by the process noise covariance
            rn = randn(obj.total_particles,6) * obj.R;
            % add a column of zeros and take the transpose to make a 5xM matrix
            noise = [rn zeros(obj.total_particles,1)]';
            % add the noise to each particle
            obj.S = obj.S + noise;
        end
        function pf_weight(obj, centroids)
            % after prediction, we compare the values of all the new
            % particles against the measurements that were received and
            % weight them accordingly. Each particle is weighted according
            % to the closest measurement. The closest measurement is the
            % one which has the lowest absolute error. The velocity is not
            % considered in the computation since we do not really know how
            % to match measurements from the previous timestep
            
            % minmat will contain the minimum error for each particle on
            % the first row, and the corresponding measurement index in the
            % second. The last two rows contain the values which correspond
            % to the innovation in x and y
            minmat = [10000 * ones(1,obj.total_particles);
                      -1 * ones(5,obj.total_particles)];

            for i=1:size(centroids,1)
                % super simple distance computation - essentially the
                % city-block distance. We don't care about the actual
                % distance, only need to know which particles are closest
                xydist = obj.S(1:4,:) - repmat(centroids(i,:)',1,obj.total_particles);
                distances=sum(abs(xydist),1);
                smaller = distances < minmat(1,:);
                
                % replace the values in minmat with the new smallest index
                % and value if the computed distance is smaller.
                minmat(:,smaller==1) = [distances(:,smaller==1);
                                        i * ones(1,size(find(smaller),2));
                                        xydist(:,smaller==1)];
            end
            
            nu = minmat(3:6,:); %4xM
            % reweight the particles in the cloud based on their
            % probability having made the measurement provided.
            p = obj.normalisation*exp(sum(-0.5*nu.*obj.bigQ.*nu,1))';
            
            ps = sum(p);
            % if the weights are all zero, then assign everything to be
            % uniformly weighted
            if ps < 1e-10
                p=ones(1,size(obj.S,2))/obj.total_particles;
            else
                p = p/ps;
            end
            obj.S(7,:)=p;
        end
        function pf_resample(obj,type, nCentroids)
            if type %Stratified resampling
                 %First, get clusters
                  % compute clusters using kmeans - these should correspond to
                % the number of objects in the scene
                [idx] = kmeans(obj.S(1:2,:)', nCentroids,'emptyaction','singleton','replicates',5);
                % Compute the mean of each cluster
                new_particles = [];
                for i=1:nCentroids
                    cluster_particles = obj.S(:,idx==i)
                    if ~isempty(cluster_particles);
                        new_particles = [new_particles obj.systematic_resampling(cluster_particles)];
                    end
                end
                %Check size due to rounding errors
                if size(new_particles,2) > obj.resampled_particles
                    %Take the first "total_particles"
                    new_particles = new_particles(:,1:obj.resampled_particles); 
                elseif size(new_particles,2) < obj.resampled_particles
                    diff = obj.resampled_particles -size(new_particles,2)
                    %Repeat the first "resampled_particles-diff" particles
                    new_particles = [new_particles(:,1:diff) new_particles];
                end
                obj.S = new_particles;  
            else %Systematic resampling
                obj.S = obj.systematic_resampling(obj.S);
            end
        end
        
        function new_particles = systematic_resampling(obj,particles)
            cdf = cumsum(particles(7,:));
            nParticles = obj.resampled_particles;
            % initial random value between 0 and 1/resampled_particles. Do
            % not use 1/total_particles, because that would mean that
            % particles at the end of the list are skipped each time
            r_0 = rand / nParticles;
            % initialise a new particle matrix in which to store selected
            % particles.
            new_particles = zeros(7,nParticles);
            % loop over all particles and choose the particle to carry over
            % to the next timestep
            for m = 1 : nParticles
                % the new particle is the one corresponding to the index
                % in the cdf which exceeds the current random number
                new_particles(:,m) = obj.S(:,find(cdf >= r_0,1,'first'));
                % the random number is incremented by 1/M each time
                r_0 = r_0 + 1/nParticles;
            end
            % the new particles are all given a uniform weight according to
            % the total number of particles which will be in the set
            new_particles(7,:) = 1/obj.total_particles*ones(1,nParticles);
        end
    end
end

