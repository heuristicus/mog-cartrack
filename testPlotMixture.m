%Create some gaussians
close all;
clear variables;

%% 3D case
mu = [0.2 0.5 0.5;
      0.6 0.7 0.1;
      0.8 0.2 0.3];  
sigma=[0.005, 0.01, 0.01]';
weight = [0.3,0.5,0.2]';

plotMixture(mu,sigma,weight,1);

%% 1D case
mu = [0.2, 0.6, 0.8]';
sigma=[0.02, 0.04, 0.04]';
weight = [0.3,0.5,0.2]';

plotMixture(mu,sigma,weight,1);
