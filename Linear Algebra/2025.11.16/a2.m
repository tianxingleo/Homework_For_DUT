%验证2
n=randi(5,1)
%m=randi(10,1)
A_1=rand(n,n)
B=rand(n,n)
C_1=rand(n,n)
D=rand(n,n)
Matrix_1=[A_1,B;C_1,D]
det_1=det(Matrix_1)
det_2=det(A_1)*det(B)-det(B)*det(C_1)


A_2=diag(rand(1,n))
C_2=diag(rand(1,n))
Matrix_2=[A_2,B;C_2,D]
det_1=det(Matrix_2)
det_3=det(A_2*D-C_2*B)