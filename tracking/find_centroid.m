function centroid = find_centroid(bboxes)
%FIND_CENTROID compute the centres of bounding boxes specified by 
% [x y width height;
%  ...]
centroid = [mean([bboxes(:,1) bboxes(:,1) + bboxes(:,3)],2) mean([bboxes(:,2) bboxes(:,2) + bboxes(:,4)],2)];
end

