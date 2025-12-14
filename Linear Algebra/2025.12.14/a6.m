clc; clear;

n = 5;
A = rand(n);
B = rand(n);
C = rand(n);
b = rand(n, 1);

x_direct = A \ b;

det_A = det(A);
x_cramer = zeros(n, 1);

for i = 1:n
    Ai = A;
    Ai(:, i) = b;
    x_cramer(i) = det(Ai) / det_A;
end

disp('直接求解结果 (列1) 与 克莱姆法则结果 (列2) 对比：');
disp([x_direct, x_cramer]);

error_val = norm(x_direct - x_cramer);
disp('两种方法的误差范数：');
disp(error_val);