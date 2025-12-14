clc; clear;

A = sparse(rand(100));
A = A + A'; 

k = 5;
sigma = 'lm';

d = eigs(A, k, sigma);

disp('矩阵 A (100x100) 模最大的 5 个特征值：');
disp(d);