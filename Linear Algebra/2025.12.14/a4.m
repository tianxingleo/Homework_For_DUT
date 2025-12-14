clc; clear;
x0 = [15; 9; 6];

P = [0.7, 0.2, 0.1; 
     0.2, 0.7, 0.1; 
     0.1, 0.1, 0.8];

x1 = P * x0;
disp('一年后各行业人数 (万人):');
disp(x1);

x2 = P * x1;
disp('两年后各行业人数 (万人):');
disp(x2);

[V, D] = eig(P);
[~, idx] = max(abs(diag(D)));
steady_state = V(:, idx);
steady_state = steady_state / sum(steady_state) * sum(x0);

disp('若干年后 (稳态) 各行业人数 (万人):');
disp(steady_state);