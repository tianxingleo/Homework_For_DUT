姓名：____________ 学号：____________

# 一、第一次作业

## 1、极限

代码：

```matlab
syms x n

% 第1题
f1 = sin(sin(x))/x - 1;
L1 = limit(f1, x, 0)

% 第2题
f2 = tan(pi/4 + 1/n)^n;
L2 = limit(f2, n, inf)

% 第3题
f3 = 1/(1/(1+exp(x-1)));
L3_left = limit(f3, x, 1, 'left')
L3_right = limit(f3, x, 1, 'right')
```

结果：

- L1 = 0
- L2 = exp(2)
- L3\_left = 2，L3\_right = 2

## 2、图形绘制

代码：

```matlab
% 1. 极坐标曲线
theta = linspace(0, 2*pi, 2000);
rho = 3*cos(3*theta);
figure;
polarplot(theta, rho, 'LineWidth', 2);
title('\rho = 3cos(3\theta)');

% 2. 参数方程
t = linspace(0, 2*pi, 2000);
x2 = 2*(t + sin(t));
y2 = 2*(cos(t) - 1);
figure;
plot(x2, y2, 'LineWidth', 2);
title('x=2(t+sint), y=2(cost-1)');
axis equal; grid on;

% 3. y = x^(2/3)
x3 = linspace(-10, 10, 2000);
y3 = nthroot(x3.^2, 3);
figure;
plot(x3, y3, 'LineWidth', 2);
title('y = x^{2/3}'); grid on;

% 4. y = x*sin(x)
x4 = linspace(-10, 10, 2000);
y4 = x4 .* sin(x4);
figure;
plot(x4, y4, 'LineWidth', 2);
title('y = x sin x'); grid on;
```

结果：

![极坐标曲线](images/hw1_polar.png)

![参数方程](images/hw1_parametric.png)

![y=x^(2/3)](images/hw1_x23.png)

![y=xsinx](images/hw1_xsinx.png)

## 3、导数

代码：

```matlab
syms a t

% 第1题：参数方程求导
xt = a*(t - sin(t));
yt = a*(1 - cos(t));
dx_dt = diff(xt, t);
dy_dt = diff(yt, t);
dy_dx = simplify(dy_dt / dx_dt)
d2y_dx2 = simplify(diff(dy_dx, t) / dx_dt)

% 第2题：隐函数求导
syms y(x)
eq = exp(y) + x*y - exp(x) == 0;
deq = diff(lhs(eq), x) - diff(rhs(eq), x);
dydx = simplify(solve(deq, diff(y, x)))
```

结果：

- 第1题：dy/dx = sin(t)/(1-cos(t))，d^2y/dx^2 = -1/(a(1-cos(t))^2)
- 第2题：dy/dx = (exp(x)-y)/(exp(y)+x)

## 4、不定积分与定积分

代码：

```matlab
syms x

% 第1题：不定积分
I1 = int(x^3*exp(-x^2), x)
I2 = int(1/(x*sqrt(x^2+1)), x)

% 第2题：定积分
I3 = int(x/sin(x)^2, x, pi/4, pi/3)
vpa(I3, 10)
```

结果：

- ∫x^3 e^(-x^2) dx = -(x^2+1)e^(-x^2)/2
- ∫1/(x√(x^2+1)) dx = -atanh(1/√(x^2+1))
- ∫_{π/4}^{π/3} x/sin^2(x) dx ≈ 0.3834894942

## 5、分段函数积分

代码：

```matlab
syms t Q P0 f0 i0 t0 dP df m r real
assume(Q>0); assume(r>0);

% 正常情景
rate_N = Q*(P0 + f0 + i0);
C_N = simplify(int(rate_N, t, 0, 30))

% 受阻情景
P_D = piecewise(t < t0, P0, t >= t0, P0 + dP*exp(-(t-t0)/r));
f_D = piecewise(t < t0, f0, t >= t0, f0 + df);
i_D = piecewise(t < t0, i0, t >= t0, m*i0);
rate_D = Q*(P_D + f_D + i_D);
C_D = simplify(int(rate_D, t, 0, 30))

DeltaC = simplify(C_D - C_N)
```

结果：

- C\_N = 30Q(P0+f0+i0)
- C\_D = Q(P0+f0+i0)\*t0 + Q(P0+f0+df+m\*i0)\*(30-t0) + Q\*dP\*r\*(1-exp(-(30-t0)/r))
- DeltaC = Q\*(df+(m-1)\*i0)\*(30-t0) + Q\*dP\*r\*(1-exp(-(30-t0)/r))

---

# 二、第二次作业

## 1、Fourier级数逼近

题目：f(x)=x+|x|，x∈[-π,π]，画出原函数及Fourier级数前1、2、3、5项的逼近。

代码：

```matlab
x = linspace(-pi, pi, 1000);
f = x + abs(x);
N_list = [1, 2, 3, 5];

figure;
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
```

结果：

![Fourier级数逼近](images/hw2_fourier.png)

## 2、曲面、空间曲线和交线

代码：

```matlab
% (1) 马鞍面 z=x^2-y^2
x = -4:0.1:4; y = -4:0.1:4;
[X,Y] = meshgrid(x,y);
Z = X.^2 - Y.^2;
figure; mesh(X,Y,Z); grid on;
title('马鞍面 z=x^2-y^2');

% (2) 空间曲线 x=2cosv, y=2sinv, z=3v
v = linspace(0, 2*pi, 1000);
figure; plot3(2*cos(v), 2*sin(v), 3*v, 'LineWidth', 1.5); grid on;
title('空间曲线 x=2cosv, y=2sinv, z=3v');

% (3) 马鞍面与y=1的交线
x_line = -4:0.02:4;
z_line = x_line.^2 - 1;
figure; mesh(X,Y,Z); hold on; grid on;
plot3(x_line, ones(size(x_line)), z_line, 'r', 'LineWidth', 2.5);
title('马鞍面与y=1的交线');
legend('马鞍面','交线 y=1, z=x^2-1');
```

结果：

![马鞍面](images/hw2_saddle.png)

![空间曲线](images/hw2_helix.png)

![交线](images/hw2_intersection.png)

## 3、多元函数微分与极值

代码：

```matlab
syms x y dx dy real

% (1) z=sqrt(x^2+y^2) 的全微分与二阶偏导
z = sqrt(x^2 + y^2);
zx = simplify(diff(z,x))
zy = simplify(diff(z,y))
zxx = simplify(diff(z,x,2))
zxy = simplify(diff(diff(z,x),y))
zyy = simplify(diff(z,y,2))
dz = zx*dx + zy*dy

% (2) f(x,y)=x^4-8xy+2y^2-3 的极值
f = x^4 - 8*x*y + 2*y^2 - 3;
fx = diff(f,x); fy = diff(f,y);
[solx, soly] = solve([fx==0, fy==0], [x,y], 'Real', true);
fxx = diff(f,x,2); fxy = diff(diff(f,x),y); fyy = diff(f,y,2);
D = simplify(fxx*fyy - fxy^2);
for k = 1:length(solx)
    x0 = solx(k); y0 = soly(k);
    f0 = simplify(subs(f,[x,y],[x0,y0]));
    D0 = simplify(subs(D,[x,y],[x0,y0]));
    fxx0 = simplify(subs(fxx,[x,y],[x0,y0]));
    fprintf('驻点 (%s, %s): f=%s, D=%s, fxx=%s\n', ...
        char(x0), char(y0), char(f0), char(D0), char(fxx0));
end
```

结果：

全微分：dz = x/√(x^2+y^2) dx + y/√(x^2+y^2) dy

二阶偏导数：z\_xx = y^2/(x^2+y^2)^(3/2)，z\_xy = -xy/(x^2+y^2)^(3/2)，z\_yy = x^2/(x^2+y^2)^(3/2)

极值：驻点为(0,0)、(2,4)、(-2,-4)。其中(0,0)处D=-64<0为鞍点；(2,4)和(-2,-4)处D=128>0、f\_xx=48>0，均为极小值点，极小值为-19。

## 4、二重积分与三重积分

代码：

```matlab
syms r theta rho phi real

% (1) 二重积分
I1 = int(int(r^2*r, r, 0, 1), theta, 0, 2*pi)

% (2) 三重积分（球坐标）
I2 = int(int(int(rho^2*sin(phi)^2 * rho^2*sin(phi), ...
    rho, 1, 2), phi, 0, pi/2), theta, 0, 2*pi)
simplify(I2)
```

结果：

- I1 = π/2
- I2 = 124π/15
