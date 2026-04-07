clc;
clear;
close all;

%% 上机作业3

%% 第1题
% 对于参数方程
% x = a(t - sin t)
% y = a(1 - cos t)
% 求 dy/dx, d2y/dx2

syms a t x y

xt = a*(t - sin(t));
yt = a*(1 - cos(t));

dx_dt = diff(xt, t);   % dx/dt
dy_dt = diff(yt, t);   % dy/dt

% 一阶导数 dy/dx = (dy/dt)/(dx/dt)
dy_dx = simplify(dy_dt / dx_dt);

% 二阶导数 d2y/dx2 = d/dt(dy/dx) / (dx/dt)
d2y_dx2 = simplify(diff(dy_dx, t) / dx_dt);

disp('第1题结果：')
disp('dy/dx = ')
pretty(dy_dx)

disp('d2y/dx2 = ')
pretty(d2y_dx2)


%% 第2题
% 求 e^y + xy - e^x = 0 所确定的隐函数 y = y(x) 的导数 dy/dx

syms y(x)

eq = exp(y) + x*y - exp(x) == 0;

% 对等式两边关于 x 求导
deq = diff(lhs(eq), x) - diff(rhs(eq), x);

% 解出 y'(x)
dydx = simplify(solve(deq, diff(y, x)));

disp('第2题结果：')
disp('dy/dx = ')
pretty(dydx)