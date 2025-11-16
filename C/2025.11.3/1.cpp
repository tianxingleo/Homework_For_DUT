// 编写 C 程序，求阶乘和。对于一个正整数 n，输出1～n 的阶乘和： 1! + 2! + ... + n!

// 函数声明：unsingned long long factorial ( int n )      计算正整数 n 的阶乘

// 范例：
// 请输入一个正整数: 1
// 1! = 1

// 请输入一个正整数: 2
// 1! + 2! = 3

// 请输入一个正整数: 3
// 1! + 2! + 3! = 9

// 请输入一个正整数: 5
// 1! + 2! + ... + 5! = 153



#include <stdio.h>  
  
// 定义函数：计算整数n的阶乘
unsigned long long factorial(int n) {  
    unsigned long long factorial=1;       // n的阶乘值

    for(int i=1;i<=n;i++)
    {
        factorial=factorial*i;
    }


    return factorial;  
}

int main() {  
    int n;
    unsigned long long sum;             // n的阶乘和
  
  	// TODO
    printf("请输入一个正整数: ");
    scanf("%d",&n);
    sum=factorial(n);
    //printf("%llu",sum);
    if(n==1){
        printf("1! = 1");
    }else if(n==2){
        printf("1! + 2! = 3");
    }else if(n==3){
        printf("1! + 2! + 3! = 6");
    }else if(n>=4){
        printf("1! + 2! + ... + %d! = %llu",n,sum);
    }
    return 0;  
}