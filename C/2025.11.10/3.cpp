// 编写 C 程序，从键盘输入一个正整数 n（n<=10），随机生成 n 个1~100以内的正整数，在 invertArray 函数内用指针将所有数值反转，通过 printArray 函数打印反转前后的数值。

// 要求：在函数内部使用指针来操作数组元素

// 函数声明：
// ​    void invertArray ( int *arr, int size);        // 第一个参数是数组首元素的地址，第二个参数是数组的长度
// ​    void printArray ( int *arr, int size);          // 同上

// 范例：
// 请输入一个1-10之间的正整数: 9
// 随机生成的数: 29 49 92 80 28 15 21 97 64
// 反转后的数是: 64 97 21 15 28 80 92 49 29


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 反转数组
void invertArray(int *arr, int size)
{
    // TODO
    for(int i=0;i<=(size-1)/2;i++){
        int *a=&arr[i],*b=&arr[size-1-i];
        int temp=*a;
        *a=*b;
        *b=temp;
    }
}

// 打印数组
void printArray(int *arr, int size)
{
    // TODO
    for(int i=0;i<=size-1;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int N;                 // 随机数的个数
    srand(time(0));	       // 设置随机数种子 
    
    // TODO
    printf("请输入一个1-10之间的正整数: ");
    scanf("%d",&N);
    int arr1[N];
    for(int i=0;i<=N-1;i++){
        arr1[i]=rand()%101;
    }
    printf("随机生成的数: ");
    printArray(arr1,N);
    invertArray(arr1,N);
    printf("\n反转后的数是: ");
    printArray(arr1,N);

    return 0;
}