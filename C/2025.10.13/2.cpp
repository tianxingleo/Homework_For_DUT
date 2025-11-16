/*

编写 C 程序，用 穷举法 和 迭代法（辗转相除法）求两个正整数的最大公约数。

例如：
请输入两个正整数：517 893
517和893的最大公约数是（穷举法）：47
517和893的最大公约数是（迭代法）：47

*/

/*

//穷举法
#include <stdio.h>
int main()
{
    int a,b,c;
    printf("请输入两个正整数：");
    scanf ("%d %d",&a,&b);
    for(int d=1;d<=a&&d<=b;d++)
    {
        if(a%d==0&&b%d==0)
        {
            c=d;
        }
    }
    printf("%d和%d的最大公约数是（穷举法）：%d",a,b,c);
    return 0;
}

*/

//迭代法
#include <stdio.h>
int main(){
    printf("请输入两个正整数：");
    int a,b,c,m,n,r=1;
    scanf("%d %d",&a,&b);
    m=a;n=b;
    if (b>a){
        c=a;a=b;b=c;
    }
    for(;;){
        r=a%b;
        if (r==0){
            break;
        }else{
            a=b;b=r;
        }
    }
    printf("%d和%d的最大公约数是（穷举法）：%d",m,n,b);
}