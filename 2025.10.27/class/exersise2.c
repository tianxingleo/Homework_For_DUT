/*Ѱ���������ֵ
  ���������������λ��*/
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
    /*׼�����ݿռ�*/
    int a[10],i,max=0,index=0,number;
    srand(time(0));
    //srand(1);
    /*��������*/
     for(i=0;i<10;i++)
         a[i]= rand()%100;
    /*�������*/
    printf("���ԭʼ����\n");
    for(i=0;i<10;i++)
         printf("%d  ",a[i]);

     /*�ҵ����ֵԪ�ؼ���λ��*/

    

     printf("\nmax = a[%d] = %d\n",index, max);

     /*�����ֵԪ�ط������*/


     /*�������*/
    printf("\n����仯������\n");
    for(i=0;i<10;i++)
         printf("%d  ",a[i]);

    return 0;
}
