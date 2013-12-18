function [] = main(videoFile)
%MAIN Summary of this function goes here
%   Detailed explanation goes here
close all;
%Read the video
videoObj = VideoReader(videoFile);

nFrames = videoObj.NumberOfFrames;
%For each frame
for i=1:nFrames
    frame = read(videoObj,i);
    %Compute foreground
    imshow(mog(frame),'InitialMagnification','fit');
    title(sprintf('Frame %d',i));
end

end

