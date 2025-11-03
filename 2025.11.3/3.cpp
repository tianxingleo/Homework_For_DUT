// 编写 C 程序，求一维数组中最大元素，在主函数中输出一维数组的值、所有最大元素的下标以及最大元素的个数。

// 函数声明：int maxArr ( int arr[], int n, int indexes[] )
// 参数： arr 是待统计的数组；n 是数组元素的个数；indexes  存储所有最大值的下标
// 返回值：最大元素的个数

// 范例：
// 所有的数组元素：5 3 5 9 3 6 9
// 最大元素的个数：2
// 最大元素的下标：3 6

#include <stdio.h>  
  
int max;						        // 最大的元素值

// 统计一维数组中最大元素的个数及其所在位置的下标
int maxArr(int arr[], int n, int *indexes) {  
    
    int count=0;							    // 最大的元素的个数  
    max=arr[0];
    // TODO 
    for(int i=0;i<=n-1;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=0;i<=n-1;i++){
        if(arr[i]==max){
            count++;
            indexes[i]=1;
        }
    }
  
    return count;
}

int main() {
    int arr[] = {5, 3, 5, 9, 3, 6, 9};
    int n=sizeof(arr)/sizeof(arr[0]);                                	// 计算数组长度
    int maxCount; 							// 数组中最大值的个数
    int indexes[n]; 						// 所有最大值的下标（极端情况下，所有值都相同） 
    for(int i=0;i<=n-1;i++){
        indexes[i]=0;
    }
    maxCount=maxArr(arr,n,indexes);
    printf("所有的数组元素：");
    for(int i=0;i<=n-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n最大元素的个数：%d\n最大元素的下标：",maxCount);
    for(int i=0;i<=n-1;i++){
        if(indexes[i]){
            printf("%d ",i);
        }
    }
    
    // TODO


    
    return 0;
}