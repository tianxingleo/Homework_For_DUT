#include <stdio.h>

int main()
{
	char name[30];
	char sex[10];
	long long stuno;
	long long phone;

    // TODO
    printf("������������");
    scanf("%s",name);
    printf("�������Ա�");
    scanf("%s",sex);
    printf("������ѧ�ţ�");
    scanf("%lld",&stuno);
    printf("������绰���룺");
    scanf("%lld",&phone);
    
    printf("��������ǣ�%s\n����Ա��ǣ�%s\n���ѧ���ǣ�%lld\n��ĵ绰�����ǣ�%lld",name,sex,stuno,phone);
	return 0;
}
