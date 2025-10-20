/*

编写 C 程序，将给定的一维数组中的元素前后翻转，打印翻转前后数组元素的值。

例如：
翻转前的数组: 1 2 3 4 5 6 7 8 9 10
翻转后的数组: 10 9 8 7 6 5 4 3 2 1

*/

#include <stdio.h>  
  
int main() {  
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
    int size = sizeof(arr) / sizeof(arr[0]);  		// 计算数组大小 
  
    //TODO
    printf("翻转前的数组: ");
    for(int i=0;i<=size-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n翻转后的数组: ");
    for(int i=size-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
  
    return 0;  
}