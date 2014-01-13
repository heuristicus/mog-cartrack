function [parameters] = pf_defaults()
%PF_DEFAULTS Return a struct containing default particle filter parameters
%

% noise on x y boxw boxh xv yv
process_noise = diag([10 10 5 5 5 5]);
% noise on x and y measurements
measurement_noise = diag([5 5 5 5]);
nparticles = 3000;

parameters = struct('process_noise',process_noise,'measurement_noise',measurement_noise,'nparticles',nparticles);

end

