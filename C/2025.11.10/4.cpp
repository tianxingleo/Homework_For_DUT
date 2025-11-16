// 编写 C 程序，通过 transMatrix 函数将一个N 阶矩阵进行转置（以对角线为轴翻转），并使用函数 printMatirx 函数打印矩阵转置前后的值。

// 要求：在函数内部使用指针来操作数组元素

// 函数声明：
// ​    void transMatrix(int (*arr)[N])        // 参数 arr 是指针数组
// ​    void printMatrix(int (*arr)[N])        // 同上

// 范例：
// 转置前的矩阵：
// 11   12   13   14
// 21   22   23   24
// 31   32   33   34
// 41   42   43   44

// 转置后的矩阵：
// 11   21   31   41
// 12   22   32   42
// 13   23   33   43
// 14   24   34   44


#include <stdio.h>
#define N 4

// 转置矩阵 
void transMatrix(int (*arr)[N])
{
    // TODO
    int temp=0;
    for(int i=0;i<=N-1;i++){
        for(int j=0;j<=i;j++){
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
}

// 打印数组
void printMatrix(int (*arr)[N])
{
	// TODO
    for(int i=0;i<=N-1;i++){
        for(int j=0;j<=N-1;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
}

int main()
{
	int matrix[N][N] = {
        {11, 12, 13, 14}, 
        {21, 22, 23, 24}, 
        {31, 32, 33, 34}, 
        {41, 42, 43, 44}
    };
	
	// TODO
    printf("转置前的矩阵：\n");
    printMatrix(matrix);

    transMatrix(matrix);
    printf("\n转置后的矩阵：\n");
    printMatrix(matrix);
	
	return 0;
}