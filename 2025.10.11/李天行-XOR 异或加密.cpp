/*
加密过程
1. 输入明文，输入密钥
2. 用密钥对明文进行异或运算，得到密文
3. 输出密文

解密过程
1. 输入密文，输入密钥
2. 用密钥对密文进行异或运算，得到明文
3. 输出明文

*/

#include <stdio.h>

int main(){
    char MingWen[21]={0},MiWen[21]={0},Key[21]={0};
    
    printf("请输入明文字符串（二十个字节以内）:");
    scanf("%s",MingWen);
    printf("请输入密钥字符串（二十个字节以内,且与明文字符串相同长度）:");
    scanf("%s",Key);
    for(int i=0;i<=20;i++){
        Key[i]=Key[i]^MingWen[i];

    }
    printf("加密后的密文字符串为:%s\n",Key);


    return 0;

}