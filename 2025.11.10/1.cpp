#include <stdio.h>
//#include<algorithm>
//#include<bits/stdc++.h>

// 方法1：交换两个字符的值
void swap1(char *p1, char *p2)
{
    // TODO
    char temp;
    temp = *p1;
    *p1=*p2;
    *p2=temp;
}

// 方法2：通过双重指针交换两个指针的值
void swap2(char** p1, char** p2)
{
    // TODO
    char *temp=*p1;
    *p1=*p2;
    *p2=temp;
    
}

int main()
{	
	char c1 = 'A';
	char c2 = 'B';
	
    // TODO
    
    swap1(&c1,&c2);
    printf("测试swap1\n交换前：c1=A, c2=B\n交换后：c1=%c, c2=%c",c1,c2);

    c1 = 'A';
	c2 = 'B';
    char *a1=&c1,*a2=&c2;
    swap2(&a1,&a2);
	
    printf("\n测试swap2\n交换前：c1=A, c2=B\n交换后：c1=%c, c2=%c",*a1,*a2);
	return 0; 
}