clc; clear; close all;

%% 步骤 1: 生成满足条件的 10 阶随机矩阵
n = 10;
A = rand(n);       % 生成 10x10 的随机矩阵（元素在0-1之间）
A = A ./ sum(A);   % 归一化：每一列除以该列的和，使得各列和为 1

disp('各列之和（应全为1）：');
disp(sum(A));

disp('------------------------------------------------------');

disp('【方法一：使用内置 eig 函数】');

[V, D] = eig(A);           % V 是特征向量矩阵，D 是特征值对角矩阵
eigenvalues = diag(D);     % 提取特征值向量

% 找到模最大的特征值及其索引
[max_val, idx] = max(abs(eigenvalues));
lambda_1 = eigenvalues(idx);      % 最大特征值
vec_1 = V(:, idx);                % 对应的特征向量

% 为了方便对比，通常将特征向量归一化（例如让最大元素为1，或模为1）
vec_1 = vec_1 / max(vec_1); 

fprintf('内置函数求得的最大特征值: %.6f \n', lambda_1);
disp('对应的特征向量 (前5个元素):');
disp(vec_1(1:5)); % 仅显示前5个以便查看


disp('------------------------------------------------------');

%% 方法二：使用 幂法 (Power Method) 迭代计算
disp('【方法二：使用幂法 (Power Method)】');

x = ones(n, 1);    % 初始猜测向量 (非零即可)
max_iter = 100;    % 最大迭代次数
tol = 1e-6;        % 收敛精度

lambda_2 = 0;      % 初始化特征值变量

for k = 1:max_iter
    y = A * x;     % 迭代乘法
    
    % 取 y 中绝对值最大的分量作为特征值的近似
    [max_abs_y, loc] = max(abs(y)); 
    current_lambda = y(loc);
    
    % 归一化向量，准备下一次迭代
    x_new = y / current_lambda;
    
    % 判断是否收敛
    if norm(x_new - x, inf) < tol
        lambda_2 = current_lambda;
        x = x_new;
        break;
    end
    
    x = x_new;
    lambda_2 = current_lambda;
end

fprintf('幂法迭代求得的最大特征值: %.6f \n', lambda_2);
disp('对应的特征向量 (前5个元素):');
disp(x(1:5));

disp('------------------------------------------------------');

%% 结论观察
fprintf('观察结论：\n');
if abs(lambda_1 - 1) < 1e-4
    fprintf('1. 无论是哪种方法，最大特征值都非常接近 1。\n');
else
    fprintf('1. 计算结果显示最大特征值不为1\n');
end