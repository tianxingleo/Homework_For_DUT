/*

编写 C 程序，用筛选法求素数（Prime），输出1000以内所有的素数/质数，并统计个数。

筛选法的基本思想：

先假设所有的数都是素数
然后从最小的素数开始，排除它的所有倍数（这些倍数一定是合数）
剩下未被排除的数就是素数

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1000  			// 定义范围上限

int main() {
    bool isPrime[MAX + 1];  // 布尔数组标记是否为素数
    int count = 0;          // 用于统计素数个数

    //TODO
    printf("1000以内的素数有：\n");

    for(int i=2;i<=MAX;i++ ){
        isPrime[i]=1;
    }

    for(int i=2;i<=MAX;i++ ){
        if (isPrime[i]==1){
            for(int a=i+1;a<=MAX;a++){
                if(a%i==0){
                    isPrime[a]=0;
                }
            }
        }
    }
	
    for(int i=2;i<=MAX;i++){
        if(isPrime[i]==1){
            printf(" %d ",i);
        }
    }

    for(int i=2;i<=MAX;i++){
        if(isPrime[i]==1){
            count+=1;
        }
    }

    printf("\n\n%d以内共有%d个素数",MAX,count);
	return 0;
}