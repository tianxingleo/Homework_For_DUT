#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
 
#define COUNT_TOTAL 20 // 产生的随机数总数
#define RANGE_MAX 10   // 随机数范围 (0到9)

int main() { 	
    // 随机生成的20个数字，用于存储和首次输出
    int numbers[COUNT_TOTAL]; 
    // 每个数字被生成的次数，索引0-9对应数字0-9
    int count[RANGE_MAX] = {0}; 
    
    // 初始化随机数种子，必须在rand()之前执行
    srand(time(0)); 
    
    // --- 1. 生成随机数并计数 ---
    for(int i = 0; i < COUNT_TOTAL; i++) {
        // 生成 0 到 9 之间的随机数
        int rand_num = rand() % RANGE_MAX; 
        
        numbers[i] = rand_num;
        // 使用随机数作为 count 数组的索引进行计数
        count[rand_num] += 1;
    }

    // --- 2. 输出所有生成的随机数 ---
    printf("随机生成的%d个0~%d的数：\n", COUNT_TOTAL, RANGE_MAX - 1);
    for(int i = 0; i < COUNT_TOTAL; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // --- 3. 输出每个数生成的次数 ---
    printf("\n每个数生成的次数：\n");
    for(int i = 0; i < RANGE_MAX; i++) {
        // *** 修正点 1：输出 count[i] 而不是 numbers[i] ***
        printf("数字%d --- %d次\n", i, count[i]);
    }
    
    // --- 4. 输出不重复的数 (只生成一次的数) ---
    printf("\n不重复的数是：");
    int first_unique = 1; // 辅助变量，用于控制第一个数字前的空格

    for(int i = 0; i < RANGE_MAX; i++) {
        // *** 修正点 2：判断 count[i] 是否等于 1 ***
        if (count[i] == 1) {
            if (!first_unique) {
                printf(" ");
            }
            printf("%d", i);
            first_unique = 0;
        }
    }
    printf("\n");
 
    return 0; 
}