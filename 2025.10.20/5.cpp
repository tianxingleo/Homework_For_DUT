/*

编写 C 程序，输出杨辉三角形的前 N 行。

杨辉三角形的构造遵循以下规则：

第一行只有数字1。
从第二行开始，每一行的第一个和最后一个数字都是1，其余每个数字都是上一行相邻两数之和。

*/

#include <stdio.h>

int main() {

    
    int n;
    // TODO：提示输入杨辉三角形的行数n
    printf("请输入杨辉三角形的行数n: ");
    scanf("%d",&n);
    long long yanghui[n+1][n+1]={0};              // 二维数组存储杨辉三角形，保证可以输出较多行数

    // TODO
    for(int a=1;a<=n;a++){//a为行数
        for(int b=1;b<=a;b++){//b为列数
            if(b==1||b==a){
                yanghui[a][b]=1;
            }else{
                yanghui[a][b]=yanghui[a-1][b-1]+yanghui[a-1][b];
            }
        }
    }

    for(int a=1;a<=n;a++){//a为行数
        for(int c=(n+1-a)*4/2.0;c>=1;c--){
            printf(" ");//计算需要预留的空格数，使杨辉三角居中
        }
        for(int b=1;b<=a;b++){//b为列数
            printf("%4lld ",yanghui[a][b]); //控制数字宽度
        }
        printf("\n");
    }

    return 0;
}