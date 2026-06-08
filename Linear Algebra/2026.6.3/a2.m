%% 微积分第二次上机作业 MATLAB 代码
% 说明：按顺序运行本脚本，即可得到作业题一、题二图像，以及题三、题四计算结果。
clear; clc; close all;

%% 作业题一：f(x)=x+|x| 的 Fourier 级数逼近
x = linspace(-pi, pi, 1000);
f = x + abs(x);
N_list = [1, 2, 3, 5];

figure('Name','作业题一 Fourier级数逼近');
subplot(3,2,1);
plot(x, f, 'LineWidth', 1.5); grid on;
title('原函数 f(x)=x+|x|'); xlabel('x'); ylabel('f(x)');

for k = 1:length(N_list)
    N = N_list(k);
    S = pi/2 * ones(size(x));
    for n = 1:N
        an = 2*((-1)^n - 1)/(pi*n^2);
        bn = 2*(-1)^(n+1)/n;
        S = S + an*cos(n*x) + bn*sin(n*x);
    end
    subplot(3,2,k+1);
    plot(x, f, '--', 'LineWidth', 1.2); hold on;
    plot(x, S, 'LineWidth', 1.5); grid on;
    title(['Fourier级数前 ', num2str(N), ' 项逼近']);
    xlabel('x'); ylabel('y');
    legend('原函数','Fourier逼近','Location','best');
end

%% 作业题二：曲面、空间曲线和交线
% 1. 绘制马鞍面 z=x^2-y^2，取 x,y 属于 [-4,4]
x = -4:0.1:4;
y = -4:0.1:4;
[X,Y] = meshgrid(x,y);
Z = X.^2 - Y.^2;
figure('Name','作业题二-1 马鞍面');
mesh(X,Y,Z); grid on;
title('马鞍面 z=x^2-y^2'); xlabel('x'); ylabel('y'); zlabel('z');

% 2. 绘制参数方程 x=2cos v, y=2sin v, z=3v, v属于[0,2pi]
v = linspace(0,2*pi,1000);
x = 2*cos(v);
y = 2*sin(v);
z = 3*v;
figure('Name','作业题二-2 空间曲线');
plot3(x,y,z,'LineWidth',1.5); grid on;
title('空间曲线 x=2cosv, y=2sinv, z=3v');
xlabel('x'); ylabel('y'); zlabel('z');

% 3. 绘制马鞍面 z=x^2-y^2 与平面 y=1 的交线
% 令 y=1，得到 z=x^2-1
x_line = -4:0.02:4;
y_line = ones(size(x_line));
z_line = x_line.^2 - 1;
figure('Name','作业题二-3 交线');
mesh(X,Y,Z); hold on; grid on;
plot3(x_line, y_line, z_line, 'r', 'LineWidth', 2.5);
title('马鞍面 z=x^2-y^2 与 y=1 的交线');
xlabel('x'); ylabel('y'); zlabel('z');
legend('马鞍面','交线 y=1, z=x^2-1','Location','best');

%% 作业题三：多元函数微分与极值
% 1. z=sqrt(x^2+y^2) 的全微分、二阶偏导数
syms xs ys dx dy real
zs = sqrt(xs^2 + ys^2);
zx  = simplify(diff(zs,xs));
zy  = simplify(diff(zs,ys));
zxx = simplify(diff(zs,xs,2));
zxy = simplify(diff(diff(zs,xs),ys));
zyy = simplify(diff(zs,ys,2));
dzs = zx*dx + zy*dy;

disp('作业题三-1：z=sqrt(x^2+y^2)');
disp('dz = '); disp(dzs);
disp('z_xx = '); disp(zxx);
disp('z_xy = z_yx = '); disp(zxy);
disp('z_yy = '); disp(zyy);

% 2. f(x,y)=x^4-8xy+2y^2-3 的极值
f = xs^4 - 8*xs*ys + 2*ys^2 - 3;
fx = diff(f,xs);
fy = diff(f,ys);
[solx, soly] = solve([fx==0, fy==0], [xs,ys], 'Real', true);

fxx = diff(f,xs,2);
fxy = diff(diff(f,xs),ys);
fyy = diff(f,ys,2);
D = simplify(fxx*fyy - fxy^2);

disp('作业题三-2：驻点与 Hessian 判别');
for k = 1:length(solx)
    x0 = solx(k); y0 = soly(k);
    f0 = simplify(subs(f,[xs,ys],[x0,y0]));
    D0 = simplify(subs(D,[xs,ys],[x0,y0]));
    fxx0 = simplify(subs(fxx,[xs,ys],[x0,y0]));
    fprintf('驻点 (%s, %s): f=%s, D=%s, fxx=%s\n', char(x0), char(y0), char(f0), char(D0), char(fxx0));
end

%% 作业题四：二重积分与三重积分
% 1. 计算 ∬_{x^2+y^2<=1} (x^2+y^2) dxdy
syms r theta rho phi real
I1 = int(int(r^2*r, r, 0, 1), theta, 0, 2*pi);
disp('作业题四-1：二重积分结果 I1 = '); disp(simplify(I1));

% 2. 球坐标下计算三重积分 ∭_D (x^2+y^2) dV
% D 为上半空间中半径 1 到 2 之间的半球壳：
% 1 <= rho <= 2, 0 <= phi <= pi/2, 0 <= theta <= 2pi
% x^2+y^2 = rho^2 sin^2(phi), dV = rho^2 sin(phi) d rho d phi d theta
I2 = int(int(int(rho^2*sin(phi)^2 * rho^2*sin(phi), rho, 1, 2), phi, 0, pi/2), theta, 0, 2*pi);
disp('作业题四-2：三重积分结果 I2 = '); disp(simplify(I2));
