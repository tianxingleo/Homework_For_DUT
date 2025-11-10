// 编写 C 程序，从键盘获得五门课程的成绩，通过 compute 函数计算最高分、最低分、平均分。
// 要求：在函数中利用指针返回多个数值，保留小数点后两位

// 函数声明：
// ​    float compute(float *arr, int n, float *pMax, float *pMin)； 

// 参数说明：
// ​    arr ：指向数组的指针
// ​    n ：数组的长度
// ​    pMax ：指向存储最大值的变量的指针
// ​    pMin ：指向存储最小值的变量的指针
// ​    返回值：数组元素的平均值

// 范例：
// 第1门课程的分数：50
// 第2门课程的分数：60
// 第3门课程的分数：70
// 第4门课程的分数：80
// 第5门课程的分数：90

// 最高分: 90
// 最低分: 50
// 平均分: 70.00

#include <stdio.h>  
#define N 5

// 计算最高分、最低分、平均分
float compute(int *arr, int n, int *pMax, int *pMin) {  
    float avgScore;  

    // TODO
    float sum=0;
    *pMax=*pMin=arr[0];
    for(int i=0;i<=N-1;i++){
        sum+=arr[i];
        if(arr[i]>*pMax){
            *pMax=arr[i];
        }
        if(arr[i]<*pMin){
            *pMin=arr[i];
        }
    }
    avgScore=sum/N;

    return avgScore;
}

int main() {     
    int score[N];  						// 记录五门课程的分数 
    int maxScore, minScore;				// 最高分、最低分
    float avgScore;						// 平均分 
    
    // TODO
    for(int i=0;i<=N-1;i++){
        printf("第%d门课程的分数：",i+1);
        scanf("%d",&score[i]);
    }

    avgScore=compute(score,N,&maxScore,&minScore);
    printf("最高分: %d\n",maxScore);
    printf("最低分: %d\n",minScore);
    printf("平均分: %.2f\n",avgScore);
    return 0;
}