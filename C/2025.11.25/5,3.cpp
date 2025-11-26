#include <stdio.h> 
#include <limits.h> // 用于 INT_MIN，确保能找到最小的负数

// 函数声明
int maxArr(int arr[], int n, int indexes[]);

/**
 * @brief 统计一维数组中最大元素的个数及其所有下标
 * @param arr 待统计的数组
 * @param n 数组元素的个数
 * @param indexes 存储所有最大值的下标（顺序存储下标值）
 * @return int 最大元素的个数
 */
int maxArr(int arr[], int n, int indexes[]) { 
    int max_val = INT_MIN; // 初始化最大值为最小可能的整数值
    int count = 0;         // 最大的元素的个数 

    // --- 第一轮遍历：找到最大元素的值 ---
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    
    // --- 第二轮遍历：找到所有最大元素的下标，并存储到 indexes 数组中 ---
    for (int i = 0; i < n; i++) {
        if (arr[i] == max_val) {
            // 将当前元素的下标 i 存入 indexes 数组的 count 位置
            indexes[count] = i; 
            count++; // 最大元素计数加一
        }
    }

    return count;
}

int main() {
    int arr[] = {5, 3, 5, 9, 3, 6, 9};
    // 计算数组长度
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    // 声明 indexes 数组，大小应为 n（最坏情况下所有元素都相同）
    int indexes[n]; 
    int maxCount; // 数组中最大值的个数
    
    // 调用函数
    maxCount = maxArr(arr, n, indexes);
    
    // --- 1. 输出所有的数组元素 ---
    printf("所有的数组元素：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // --- 2. 输出最大元素的个数 ---
    printf("最大元素的个数：%d\n", maxCount);
    
    // --- 3. 输出所有最大元素的下标 ---
    printf("最大元素的下标：");
    // 注意：这里只循环到 maxCount，因为 indexes 数组中只有前 maxCount 个位置存储了有效下标
    for (int i = 0; i < maxCount; i++) {
        printf("%d ", indexes[i]);
    }
    printf("\n");
    
    return 0;
}