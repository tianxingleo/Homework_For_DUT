clc;
clear;

syms x n

%% 第1题
f1 = sin(sin(x))/x - 1;
L1 = limit(f1, x, 0);

%% 第2题
f2 = tan(pi/4 + 1/n)^n;
L2 = limit(f2, n, inf);

%% 第3题
f3 = 1 / (1 / (1 + exp(x - 1)));

L3_left  = limit(f3, x, 1, 'left');
L3_right = limit(f3, x, 1, 'right');

%% 输出结果
disp('第1题极限结果：');
disp(L1);

disp('第2题极限结果：');
disp(L2);

disp('第3题左极限结果：');
disp(L3_left);

disp('第3题右极限结果：');
disp(L3_right);