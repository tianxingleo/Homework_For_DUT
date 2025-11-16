#include <stdio.h>

int main()
{
	char a, c;
	int b, d;
	
    printf("请输入一个字符：");
	scanf("%c", &a);
	b = a;
    printf("字符%c的ASCII码是%d\n",a,b);
    printf("请输入一个ASCII码(0-127)：");
	scanf("%d", &d);
	c = d;
    printf("ASCII码%d对应的字符是%c\n",d,c);

	// TODO

	return 0;
}
