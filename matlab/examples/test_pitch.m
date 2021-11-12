function [f0_LHS, f0_SRH]=test_pitch()

% [x,fs] = audioread('roy_noisy.wav');
x = randn(2048,1);
fs = 8000;
t = (0:size(x,1)-1)/fs;

winLength = round(0.03*fs);
overlapLength = round(0.015*fs);
% tic
[f0_LHS,idx] = pitch(x,fs,'Method','LHS','WindowLength',winLength,'OverlapLength',overlapLength, 'MedianFilterLength', 5);
% toc

% tic
[f0_SRH,idx] = pitch(x,fs,'Method','SRH','WindowLength',winLength,'OverlapLength',overlapLength, 'MedianFilterLength', 5);



% toc

% tf0 = idx/fs;
% 
% figure(1)
% 
% stem(tf0,f0_LHS)
% hold on
% stem(tf0,f0_SRH, 'r')
% xlabel('Time (s)')
% ylabel('Pitch (Hz)')
% title('Pitch Estimations')
% axis tight