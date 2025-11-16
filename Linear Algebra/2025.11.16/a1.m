%1 
disp(1)

A=rand(5,5)
B=rand(5,5)
C=rand(5,5)
D=rand(5,5)

A+B
A-B

%2
disp(2)

A*B+B*A

%3
disp(3)

det(A)
inv(A)
rank(A)

det(B)
inv(B)
rank(B)

%4
disp(4)

det(A*B)
inv(A*B)
rank(A*B)

det(A*B)
det(A)*det(B)

%5
(A*B)'
B'*A'

inv(A*B)
inv(B)*inv(A)

A*B
B*A
X=A'*C*B'