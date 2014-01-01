function centroid = find_centroid(bbox)
%FIND_CENTROID compute the centre of a bounding box specified by 
% [x y width height]
%   Detailed explanation goes here
centroid = [mean([bbox(1) bbox(1) + bbox(3)]) mean([bbox(2) bbox(2) + bbox(4)])];
end

