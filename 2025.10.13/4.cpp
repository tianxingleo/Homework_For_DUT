/*

编写 C 程序，求阶乘和。
对于一个正整数 n，输出1～n 的阶乘和： 1! + 2! + ... + n! 

例如：
请输入一个1-20之间的正整数: 10
1! + 2! + ... + 10! = 4037913

*/


#include <stdio.h>
int main(){
    unsigned long long   a,c=1,d=0;

        
    printf("请输入一个1-20之间的正整数: ");
    scanf("%llu",&a);
    if (a<=0||a>20){
        printf("输入错误");
    }
    else if(a==1){
        printf("1! = %d",a);
    }else if(a==2){
        printf("1! + 2! = 3");
    }else if(a==3){
        printf("1! + 2! +3！ = 9");
    }
    else {
        for (int e=a;e>=1;e--){
            for (int b=e;b>1;b--){
                c=c*b;
            }
        d=d+c;
        // printf("%d的阶乘是%llu\n",e,c);
        c=1;
    }
    printf("1! + 2! + ... + %llu! = %llu",a,d);
    }

    return 0;
}