#include <stdio.h>

int main()
{
	char name[30];
	char sex[10];
	long long stuno;
	long long phone;

    // TODO
    printf("请输入姓名：");
    scanf("%s",name);
    printf("请输入性别：");
    scanf("%s",sex);
    printf("请输入学号：");
    scanf("%lld",&stuno);
    printf("请输入电话号码：");
    scanf("%lld",&phone);
    
    printf("你的姓名是：%s\n你的性别是：%s\n你的学号是：%lld\n你的电话号码是：%lld",name,sex,stuno,phone);
	return 0;
}
