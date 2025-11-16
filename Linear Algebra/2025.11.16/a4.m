%1
T = readtable('data.xlsx')
T.Properties.VariableNames = {'面积', '卧室', '卫生间', '楼层', '建造年', '距中心', '学区评分', '交通评分', '环境评分', '房价'};
disp(T)

A=table2array(T(1:8,1:9))
b=table2array(T(:,10))

%2
x=b\A

%3
x=A'*b\(A'*A)

%4
disp("不一致")
rank(A)
A(:,2)=A(:,3)
rank(A)
disp("rank不变，结果稳定")