// 编写 C 程序，从键盘分别输入两个字符串，通过 mystrcat  函数将其合并成一个字符串（类似 strcat 库函数），并输出合并后的字符串；再通过 mystrlen 函数计算合并后的字符串长度（类似 strlen 库函数）并输出。

// 函数声明：
// ​    char* mystrcat ( char *dest, const char *src )
// ​    dest 是第一个字符串的指针，src 是第二个字符串的指针，将 src 合并到 dest 之后；返回值是合并后的字符串的指针

// ​    int mystrlen ( char *str )
// ​    str 是字符串的指针；返回值是字符串的长度​    int mystrlen ( char *str )
// ​    str 是字符串的指针；返回值是字符串的长度

// 范例：
// 输入第一个字符串：hello,
// 输入第二个字符串：world!
// 合并后的字符串是：hello,world!
// 合并后的字符串长度是：12


#include <stdio.h>
#include <string.h>

// 合并两个字符串并返回合并后的字符串指针 
char* mystrcat(char *dest, const char *src) 
{ 	
	char *result = dest;
    // TODO
    strcat(dest,src);

	
	return result;
}

// 通过计数器或头尾指针的差值计算字符串长度
int mystrlen(char *str)
{
	int length;
    // TODO
    length=strlen(str);
	
	return length;
}

int main()
{
	char str1[300];			        // 第一个字符串，要有足够的空间以存储合并后的内容
	char str2[100];			        // 第二个字符串
	char *result;					// 指向合并后的字符串 
	int length;						// 合并后的字符串长度 	
	
    // TODO
    printf("输入第一个字符串：");
    scanf("%s",str1);
    printf("输入第二个字符串：");
    scanf("%s",str2);
    result= mystrcat(str1,str2);
    length= mystrlen(str1);
    printf("合并后的字符串是：%s",result);
    printf("\n合并后的字符串长度是：%d",length);


    return 0;
}