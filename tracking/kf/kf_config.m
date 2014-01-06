function params = kf_config()
%KF_CONFIG Summary of this function goes here
%   Detailed explanation goes here
% Configuration file with the initial parameters to be set to
% the KF.

% Output:
%         params             struct
%            -R              6x6    
%            -Q              4x4
%            -sigma0         6x6
%            -dt             1x1
           
R = diag([0.3 0.3 0.1 0.1 0.1 0.1]);
Q = diag([0.1 0.1 0.1 0.1]);
sigma0 = diag([0.5 0.5 0.5 0.5 10.0 10.0]); %Unknown velocity => high variance
dt = 1; %1 frame
deltaM = 0.8; %Percentage of measurements that we think are valid

params = struct('R',R,'Q',Q,'sigma0',sigma0,'dt',dt,'deltaM',deltaM);

end
