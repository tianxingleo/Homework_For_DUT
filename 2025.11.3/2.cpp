// 编写 C 程序，验证 歌德巴赫猜想： 一个不小于 6 的偶数可以表示成两个素数之和。
// 函数声明：bool isPrime ( int num )    判断一个整数是否为素数
// 范例：
// 请输入一个不小于6的偶数: 33
// 输入错误，请输入一个不小于6的偶数

// 请输入一个不小于6的偶数: 66
// 66 = 5 + 61 = 7 + 59 = 13 + 53 = 19 + 47 = 23 + 43 = 29 + 37


#include <stdio.h>  
#include <stdbool.h>  
#include <vector>//这里也可以不使用vector，只不过用c的vla也可以，但是不安全
#include <math.h>
  
using namespace std;

void do_zhishubiao(vector<bool>&zhishubiao,int n){
    zhishubiao[0]=0;
    zhishubiao[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(zhishubiao[i]==1){
            for(int j=i*2;j<=n;j+=i){
                zhishubiao[j]=0;
            }
        }
    }
}

// isPrime函数判断num是否是素数，返回true/false  
bool isPrime(int num) {  
    
}
  
int main() {  
    int num;  
    int n;
    printf("请输入一个不小于6的偶数: ");
    scanf("%d",&n);
    if(n%2!=0||n<6){
        printf("输入错误，请输入一个不小于6的偶数");
        return 0;
    }
    vector<bool>zhishubiao(n+1,1);
    do_zhishubiao(zhishubiao,n);
    printf("%d",n);
    for(int i=2;i<=n/2;i++){
        if(zhishubiao[i]&&zhishubiao[n-i]){
            printf(" = %d + %d",i,n-i);
        }
    }

    return 0;  
}