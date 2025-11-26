#include <stdio.h>

#define MAX_N 30 // 定义最大行数，防止数组溢出

int main() {
    int n;
    
    // TODO：提示输入杨辉三角形的行数n
    printf("请输入杨辉三角形的行数n: ");
    
    // 检查输入是否成功且在合理范围内
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_N) {
        printf("输入无效。请输入一个介于 1 到 %d 之间的正整数。\n", MAX_N);
        return 1;
    }
    
    // 使用 VLA (C99特性) 或固定大小数组。
    // 这里采用 VLA: int yanghui[n+1][n+1]
    // 考虑到许多编译器支持 C99 VLA，且其使用更灵活。
    // 数组索引从 1 开始对应行数和列数，因此大小为 n+1。
    int yanghui[n + 1][n + 1];

    // --- 1. 计算杨辉三角形的值 ---
    for (int i = 1; i <= n; i++) { // i 为行数 (1 到 n)
        for (int j = 1; j <= i; j++) { // j 为列数 (1 到 i)
            // 规则：每一行的第一个 (j==1) 和最后一个 (j==i) 数字都是 1
            if (j == 1 || j == i) {
                yanghui[i][j] = 1;
            } else {
                // 规则：其余每个数字是上一行相邻两数之和
                yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
            }
        }
    }

    // --- 2. 格式化输出 ---
    printf("\n");
    for (int i = 1; i <= n; i++) { // i 为当前行数
        
        // 打印行前的空格以实现居中对齐
        // 居中逻辑：总宽度 - 当前行数字占位
        // 假设每个数字占 4 个字符宽度，总宽度基于最宽的行 (第 n 行)
        int total_width = n * 4; 
        int current_width = i * 4;
        
        // 打印空格，使数字居中
        for (int k = 0; k < (total_width - current_width) / 2; k++) {
            printf(" ");
        }

        // 打印本行的数字
        for (int j = 1; j <= i; j++) {
            // 使用 %4d 确保每个数字都占据 4 个字符宽度，便于对齐
            printf("%4d", yanghui[i][j]); 
        }
        
        printf("\n"); // 换行
    }

    return 0;
}