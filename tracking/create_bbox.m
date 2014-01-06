function [bbox] = create_bbox(x, y, width, height)
% x and y define the centre of the bbox

bbox = [x - width/2 y - height/2 width height];
end

