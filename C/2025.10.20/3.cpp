/*

编写 C 程序，将两个有序数组，合并成一个有序数组。

例如：
数组1：1 3 5 7 9
数组2：2 6
合并后的数组: 1 2 3 5 6 7 9

*/

#include <stdio.h>  
  
int main() {  
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);                         // 计算第1个数组的元素个数  
    int n2=sizeof(arr2)/sizeof(arr2[0]);                         // 计算第2个数组的元素个数
    int mergedArr[n1 + n2];  		// 合并后数组的大小是两个原数组大小之和      
	int i=0, j=0;  		            // 三个数组的下标 
    

    //TODO
int a=0;
    for(int k=0;k<=n1 + n2-1;k++){
        if(j<=1){
            if(arr1[i]<=arr2[j]){
                mergedArr[k]=arr1[i];
                i+=1;
            }else{
                mergedArr[k]=arr2[j];
                j+=1;
            }
        }else{
            mergedArr[k]=arr1[i];
            i+=1;
        }
        
    }

    printf("数组1：");
    for(int b=0;b<=n1-1;b++){
        printf("%d ",arr1[b]);
    }
    printf("\n数组2：");
    for(int b=0;b<=n2-1;b++){
        printf("%d ",arr2[b]);
    }
    printf("\n合并后的数组: ");
    for(int b=0;b<=n1+n2-1;b++){
        printf("%d ",mergedArr[b]);
    }

    return 0;  
}