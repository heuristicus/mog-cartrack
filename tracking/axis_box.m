function axis_box(bbox)
%CENTRE_AXIS set the axes of the plot based on the given bbox

axis([bbox(1) bbox(1) + bbox(3) bbox(2) bbox(2) + bbox(4)])

end

