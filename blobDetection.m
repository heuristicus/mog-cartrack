function [] = blobDetection()
%BLOBDETECTION Summary of this function goes here
%   Detailed explanation goes here

foregroundDetector = vision.ForegroundDetector('NumGaussians', 3, ...
    'NumTrainingFrames', 1);

videoReader = vision.VideoFileReader('./datasets/visiontraffic.avi');
for i = 1:150
    frame = step(videoReader); % read the next video frame
    foreground = step(foregroundDetector, frame);
    subplot(121)
    imshow(foreground,'InitialMagnification','fit')
    
    %Clean
    se = strel('square', 3);
    filteredForeground = imopen(foreground, se);
    subplot(122)
    imshow(filteredForeground); title('Clean Foreground');
    
    %Extract blobs
    blobAnalysis = vision.BlobAnalysis('MinimumBlobArea', 150);
    blobAnalysis.AreaOutputPort = false;
    [centroid, bbox] = step(blobAnalysis, filteredForeground)

    pause(0.1)
end

end

