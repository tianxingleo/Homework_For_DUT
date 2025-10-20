/*

编写 C 程序，随机产生20个10以内的自然数，输出所有生成的随机数、每个随机数生成的次数，以及所有不重复的数。

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
  
int main() {  
    int numbers[20];						// 随机生成的20个数字   
    int count[10] = {0};					// 每个数字被生成的次数，初始都为0
	int rand_num;							// 每次生成的随机数值 
  
    //TODO
    int num;
    srand(time(0));            // 初始化随机数种子，必须在rand()之前执行
    // num = rand() % 100;        // 生成 0~99 之间的随机数

    for(int i=0;i<=19;i++){
        numbers[i]=rand() % 10;
    }

    for(int i=0;i<=19;i++){
        count[numbers[i]]+=1;
    }
    printf("随机生成的20个0~9的数：");
    for(int i=0;i<=19;i++){
        printf("%d ",numbers[i]);
    }
    printf("\n\n每个数生成的次数：");
    for(int i=0;i<=9;i++){
        printf("\n数字%d --- %d次",i,numbers[i]);
    }
    printf("\n\n不重复的数是：");
    for(int i=0;i<=9;i++){
        if(numbers[i]==1)
        printf("%d ",i);
    }

  
    return 0;  
}