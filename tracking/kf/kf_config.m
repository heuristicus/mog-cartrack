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
           
R = diag([10 10 10 10 5 5]);%diag([5 5 5 5 0.5 0.5]);
Q = diag([15 15 15 15]);%diag([5 5 10 10]);
sigma0 = diag([5 5 5 5 100.0 100.0]); %Unknown velocity => high variance
dt = 1; %1 frame
deltaM = 0.99; %Percentage of measurements that we think are valid

params = struct('R',R,'Q',Q,'sigma0',sigma0,'dt',dt,'deltaM',deltaM);

end

