clc;
clear;
close all;

%% 上机作业4

syms x

%% 1. 求不定积分
I1 = int(x^3*exp(-x^2), x);
I2 = int(1/(x*sqrt(x^2+1)), x);

disp('第1题结果：')
disp('∫ x^3*e^(-x^2) dx = ')
pretty(I1)

disp('∫ 1/(x*sqrt(x^2+1)) dx = ')
pretty(I2)

%% 2. 求定积分
I3 = int(x/sin(x)^2, x, pi/4, pi/3);

disp('第2题结果：')
disp('∫_{pi/4}^{pi/3} x/sin^2(x) dx = ')
disp(vpa(I3, 10))   % 显示数值近似

disp('精确结果为：')
pretty(simplify(I3))