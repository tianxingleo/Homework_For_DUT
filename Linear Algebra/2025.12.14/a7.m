clc; clear;

a = 83;
b = 86;
c = 50;
d = 88;
e = 28;
f = 63;
g = 83;
h = 60;

A = [a, b, c, d, 3, 4;
     1, 2, 3, 4, 4, 3;
    12, 15, 22, 17, 5, 7;
     e, f, g, h, 8, 0];

[R, p] = rref(A);

disp('A 的列向量组的一个最大无关组为：');
disp(A(:, p));

disp('各列向量下标（即第几列是最大无关组）：');
disp(p);


disp('非最大无关组向量由最大无关组表示如下：');

num_cols = size(A, 2);
non_pivot_cols = setdiff(1:num_cols, p);

for j = 1:length(non_pivot_cols)
    target_col_idx = non_pivot_cols(j);
    coeffs = R(1:length(p), target_col_idx);
    
    fprintf('a%d = ', target_col_idx);
    first_term = true;
    
    for i = 1:length(p)
        coef = coeffs(i);
        if abs(coef) > 1e-10
            if ~first_term && coef > 0
                fprintf(' + ');
            elseif coef < 0
                fprintf(' - '); 
                coef = abs(coef);
            elseif first_term
                 if coef < 0
                    fprintf('-');
                    coef = abs(coef);
                 end
            end
            
            fprintf('%.4f * a%d', coef, p(i));
            first_term = false;
        end
    end
    fprintf('\n');
end