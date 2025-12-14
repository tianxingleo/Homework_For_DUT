% 1. 定义二次型对应的矩阵 A
A = [1,   1.5, 0; 
     1.5, -1,  1; 
     0,   1,   1];

% 2. 计算特征值 (Eigenvalues)
lambda = eig(A);

% 3. 显示特征值结果
disp('该矩阵的特征值为：');
disp(lambda);

% 4. 自动判断正定性
if all(lambda > 0)
    disp('结论：该二次型为【正定】 (Positive Definite)');
elseif all(lambda < 0)
    disp('结论：该二次型为【负定】 (Negative Definite)');
elseif any(lambda > 0) && any(lambda < 0)
    disp('结论：该二次型为【不定】 (Indefinite)');
elseif any(lambda == 0) && all(lambda >= 0)
    disp('结论：该二次型为【半正定】 (Positive Semi-definite)');
else
    disp('结论：该二次型为【半负定】 (Negative Semi-definite)');
end