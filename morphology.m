function [foregroundOut] = morphology(foregroundIn)
%MORPHOLOGY Summary of this function goes here
%   Detailed explanation goes here
% Applies morphological operations to get a better
% foreground

%Create a structuring element
element = strel('square',3); %3x3 kernel
element2 = strel('square',5); %3x3 kernel

%Dilation to connect components
foregroundOut = imdilate(foregroundIn,element);
%Filling holes (fix problems with front glass)
foregroundOut = imfill(foregroundOut);
%Erosion to remove noise
foregroundOut = imerode(foregroundOut,element);
% foregroundOut = imerode(foregroundOut,element);
% 
% %Final opening
% foregroundOut = imopen(foregroundIn,element);


end

