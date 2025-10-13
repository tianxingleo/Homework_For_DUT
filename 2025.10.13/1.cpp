/*
编写 C 程序，提示用户输入一个正整数n，求 n 的阶乘。
注：如果输入的值错误，提示重新输入n

请输入一个整数(0-20):-3
输入错误，请重新输入

请输入一个整数(0-20):21
输入错误，请重新输入

请输入一个整数(0-20):5
5的阶乘是: 120
*/

#include <stdio.h>
int main(){
    long long int  a,c=1;
    while (1){
        
    printf("请输入一个整数(0-20):");
    scanf("%d",&a);
    if (a<0||a>20){
        printf("输入错误，请重新输入");
    }
    else if(a==0){
        printf("%d",a);
        break;
    }
    else {
        for(int b=a;b>1;b--){
            c=c*b;

        }
        printf("%lld",c);
        break;
    }
}
    return 0;
}