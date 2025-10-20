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
    int yanghui[n+1][n+1]={0};              // 二维数组存储杨辉三角形

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
        for(int b=1;b<=a;b++){//b为列数
            printf("%d ",yanghui[a][b]);
        }
        printf("\n");
    }

    return 0;
}