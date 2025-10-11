/*
李天行-XOR 异或加密


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
//加密
    char MiWen[20]={0},Key[21]={0};
    unsigned char MingWen[20]={0};
    char MiWen_1[20]={0},Key_1[21]={0};
    unsigned char MingWen_1[20]={0};
    
    printf("请输入明文字符串（二十个字节以内）:");
    scanf("%s",MingWen);
    printf("请输入密钥字符串（二十个字节以内）:");
    scanf("%s",Key);
    for(int i=0;i<=20;i++){
        MiWen[i]=Key[i]^MingWen[i];

    }
    printf("加密后的密文字符串为（Hex）:");
    for(int i=0;i<=20;i++){
        printf("%02X ",MiWen[i]);   //这一步是因为发现可能有/0不能用普通 ASCII 文本输出，于网络搜索中发现应用十六进制输出密文
    }

//解密
    for(int i=0;i<=20;i++){
        scanf("%X",&MiWen_1[i]);
    }

    for(int i=0;i<=20;i++){
        MingWen_1[i]=Key[i]^MiWen_1[i];

    }

    for(int i=0;i<=20;i++){
        printf("%c",MingWen_1[i]);   
    }


    


    return 0;

}