function drawCenteredRectangle(data,color)
%DRAWCENTEREDRECTANGLE Summary of this function goes here
%   Detailed explanation goes here
display('asd');
x = data(1);
y = data(2);
w = data(3);
h = data(4);

x0 = x-w/2;
y0 = y-h/2;
rectangle('Position',[x0,y0,w,h],'EdgeColor',color);
end

