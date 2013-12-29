function [] = blobDetection()
%BLOBDETECTION from the matlab guides at
% http://www.mathworks.co.uk/products/computer-vision/examples.html?file=/products/demos/shipping/vision/videotrafficgmm.html
% http://www.mathworks.co.uk/help/vision/examples/detecting-cars-using-gaussian-mixture-models.html
%   Detailed explanation goes here

foregroundDetector = vision.ForegroundDetector('NumGaussians', 3, ...
    'NumTrainingFrames', 1);

videoReader = vision.VideoFileReader('visiontraffic.avi');
figure
for i = 1:200
    frame = step(videoReader); % read the next video frame
    subplot(221)
    imshow(frame)
    foreground = step(foregroundDetector, frame);
    subplot(222)    
    imshow(foreground,'InitialMagnification','fit')
        
    %Clean
    se = strel('square', 3);
    filteredForeground = imopen(foreground, se);
    subplot(223)
    imshow(filteredForeground); title('Clean Foreground');
    
    %Extract blobs
    blobAnalysis = vision.BlobAnalysis('MinimumBlobArea', 150);
    %blobAnalysis.AreaOutputPort = false;
    [area, centroid, bbox] = step(blobAnalysis, filteredForeground)
    bboxes = insertShape(frame, 'Rectangle', bbox, 'Color', 'green');
    
    subplot(224)
    imshow(bboxes)
    pause(0.1)
end

end

