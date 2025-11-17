// 编写 C 程序，从键盘输入一个不超过10位长整数，通过以下两种函数方法将其转换成字符串返回，在主程序输出转换结果。

// 函数声明：
// ​    void numberToString1 ( long num,  char str )    // 指针做函数参数
// ​    char numberToString2 ( long num)     // 指针做返回值（需动态分配堆内存）

// 范例：
// 请输入一个不超过10位的长整数：9876543210
// 方法1 转换后的字符串是：9876543210
// 方法2 转换后的字符串是：9876543210

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 通过交换首尾字符反转字符串
void reverseString(char *str)
{
    // TODO

}

// 将整数转换成字符串（指针做参数） 
void numberToString(long long num, char* str) {	
	// TODO：循环获取整数的末位数，并通过ASCII码将其转换成对应字符
	char temp[11];
    int sum=0;
    for(int i=0;num>0;i++){
        temp[i]=num%10+'0';
        num=num/10;
        sum++;
    }
    for(int i=0;i<sum;i++){
        str[sum-i-1]=temp[i];
    }
    str[sum] = '\0';
}

// 将整数转换成字符串（指针做返回值） 
char* numberToString2(long long num) {
	char *str = (char *)malloc(22 * sizeof(char));;                                      // 为转换后的字符串动态分配堆内存
    // TODO
    char temp[11];
    int sum=0;
    for(int i=0;num>0;i++){
        temp[i]=num%10+'0';
        num=num/10;
        sum++;
    }
    for(int i=0;i<sum;i++){
        str[sum-i-1]=temp[i];
    }
    str[sum] = '\0';

	return str;
}

int main()
{
	long long num;									// 保存输入的不超过10位的长整数

    // 方法1：指针做参数
	char str[11];									// 用字符数组保存转换后的字符串 
    // TODO
    printf("请输入一个不超过10位的长整数：");
    scanf("%lld",&num);
    numberToString(num,str);
    printf("方法1 转换后的字符串是：%s\n",str);
	
    // 方法2：指针做返回值
	char *pstr = NULL;								// 用字符指针指向转换后的的字符串
    // TODO
    printf("方法2 转换后的字符串是：%s",numberToString2(num));
    
	
	return 0;
}