clc;
clear;
close all;

%% 上机作业4 第3题
syms t Q P0 f0 i0 t0 dP df m r real
assume(Q>0);
assume(r>0);

%% 正常情景
rate_N = Q*(P0 + f0 + i0);
C_N = simplify(int(rate_N, t, 0, 30));

disp('正常情景月度总成本 C_N = ');
pretty(C_N)

%% 受阻情景：分段函数
P_D = piecewise(t < t0, P0, t >= t0, P0 + dP*exp(-(t-t0)/r));
f_D = piecewise(t < t0, f0, t >= t0, f0 + df);
i_D = piecewise(t < t0, i0, t >= t0, m*i0);

rate_D = Q*(P_D + f_D + i_D);
C_D = simplify(int(rate_D, t, 0, 30));

disp('受阻情景月度总成本 C_D = ');
pretty(C_D)

%% 成本增量
DeltaC = simplify(C_D - C_N);

disp('成本增量 DeltaC = C_D - C_N = ');
pretty(DeltaC)