classdef pf_class
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
        function obj=pf_class(num_particles, process_model, measurement_model, mu, bbox)
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
                % mu is assumed to be a column vector - N is number of rows.
                if size(mu,1) < 2
                    mu = mu';
                end
                obj.N = size(mu,1);
                obj.M = num_particles;
                % initialise particles randomly within the bounding box
                % specified
                obj.S = [rand(1,obj.M) * bbox(3) + bbox(1);
                    rand(1,obj.M) * bbox(4) + bbox(2);
                    ones(1,obj.M) * 1/obj.M];
                % initialise particles normally distributed around the mean
                % with variance 1
                %             obj.S = [(randn(obj.N,obj.M) + 1).* repmat(mu,1,obj.M);
                %                      ones(1,obj.M)*1/obj.M];
            end
        end
    end
end

