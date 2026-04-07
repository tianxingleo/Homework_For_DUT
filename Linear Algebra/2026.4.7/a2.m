clc;
clear;
close all;

%% 上机作业2：画出下列方程所表示的图形

%% 1. 极坐标曲线 rho = 3cos(3theta)
theta = linspace(0, 2*pi, 2000);
rho = 3*cos(3*theta);

figure('Name','题目1：极坐标曲线');
polarplot(theta, rho, 'LineWidth', 2);
title('\rho = 3cos(3\theta)');
grid on;


%% 2. 参数方程
% x = 2(t + sin t)
% y = 2(cos t - 1), t ∈ [0, 2pi]
t = linspace(0, 2*pi, 2000);
x2 = 2*(t + sin(t));
y2 = 2*(cos(t) - 1);

figure('Name','题目2：参数方程曲线');
plot(x2, y2, 'LineWidth', 2);
title('x = 2(t + sin t),  y = 2(cos t - 1),  t \in [0, 2\pi]');
xlabel('x');
ylabel('y');
grid on;
axis equal;


%% 3. y = x^(2/3)
% 注意：为了避免负数的分数次幂在 MATLAB 中出现复数，
% 用 nthroot(x.^2, 3) 更稳妥
x3 = linspace(-10, 10, 2000);
y3 = nthroot(x3.^2, 3);

figure('Name','题目3：y = x^{2/3}');
plot(x3, y3, 'LineWidth', 2);
title('y = x^{2/3}');
xlabel('x');
ylabel('y');
grid on;


%% 4. y = x sin x, x ∈ [-10,10]
x4 = linspace(-10, 10, 2000);
y4 = x4 .* sin(x4);

figure('Name','题目4：y = x sin x');
plot(x4, y4, 'LineWidth', 2);
title('y = x sin x,  x \in [-10,10]');
xlabel('x');
ylabel('y');
grid on;