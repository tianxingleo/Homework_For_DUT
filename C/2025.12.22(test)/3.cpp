#include <stdio.h>
#define N 2
#define M 3
#define K 4
void printMatrix( int  a[][M]);
int main()
{   
    int a[N][M]={{1,2,3},{4,5,6}},b[M][K]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  	int c[N][K];   
/*计算矩阵乘法C=A×B */
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            int temp=0;
            for(int k=0;k<M;k++){
                temp+=a[i][k]*b[k][j];
            }
            c[i][j]=temp;
        }
    }

    printMatrix(c);

    /*调用函数输出结果*/
     return 0;   
}

void printMatrix( int  a[][K]){
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
