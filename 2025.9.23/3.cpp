#include <stdio.h>

int main()
{
	char a, c;
	int b, d;
	
    printf("������һ���ַ���");
	scanf("%c", &a);
	b = a;
    printf("�ַ�%c��ASCII����%d\n",a,b);
    printf("������һ��ASCII��(0-127)��");
	scanf("%d", &d);
	c = d;
    printf("ASCII��%d��Ӧ���ַ���%c\n",d,c);

	// TODO

	return 0;
}
