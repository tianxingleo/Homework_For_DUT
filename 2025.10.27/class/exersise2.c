/*寻找数组最大值
  将其放在数组最后的位置*/
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
    /*准备数据空间*/
    int a[10],i,max=0,index=0,number;
    srand(time(0));
    //srand(1);
    /*生成数据*/
     for(i=0;i<10;i++)
         a[i]= rand()%100;
    /*输出数据*/
    printf("输出原始序列\n");
    for(i=0;i<10;i++)
         printf("%d  ",a[i]);

     /*找到最大值元素及其位置*/

    

     printf("\nmax = a[%d] = %d\n",index, max);

     /*将最大值元素放在最后*/


     /*输出数据*/
    printf("\n输出变化后序列\n");
    for(i=0;i<10;i++)
         printf("%d  ",a[i]);

    return 0;
}
