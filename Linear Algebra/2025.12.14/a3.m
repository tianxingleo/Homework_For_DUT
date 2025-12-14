clc; clear;
A = rand(5, 4);
disp('随机生成的4个5维向量 (列向量):');
disp(A);

[m, n] = size(A);
B = zeros(m, n);

for i = 1:n
    B(:, i) = A(:, i);
    for j = 1:i-1
        if norm(B(:, j)) > 1e-10
            proj = (dot(A(:, i), B(:, j)) / dot(B(:, j), B(:, j))) * B(:, j);
            B(:, i) = B(:, i) - proj;
        end
    end
end