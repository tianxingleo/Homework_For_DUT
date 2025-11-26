#include <stdio.h> 

// 函数声明：计算正整数 n 的阶乘
// 注意：使用 unsigned long long 是为了防止阶乘值溢出，因为 13! 就会超过 int 范围，21! 就会超过 unsigned long long 范围。
unsigned long long factorial(int n); 

/**
 * @brief 计算正整数 n 的阶乘 (n!)
 * * @param n 正整数
 * @return unsigned long long n 的阶乘值
 */
unsigned long long factorial(int n) { 
    // 阶乘增长极快，13! 就会溢出 32 位 int，21! 就会溢出 64 位 unsigned long long
    if (n < 0) {
        return 0; // 处理负数输入，虽然题目要求正整数
    }
    
    unsigned long long result = 1; 

    // 循环计算 n 的阶乘：result = 1 * 2 * ... * n
    for (int i = 1; i <= n; i++) {
        result *= i;
        // 实际应用中需要检查溢出，但在此题中暂时省略
    }

    return result; 
}

int main() { 
    int n;
    unsigned long long sum = 0; // 存储阶乘和

    // 1. 提示用户输入并读取 n
    printf("请输入一个正整数: ");
    
    // 增加输入校验
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        // 由于 21! 就会溢出 unsigned long long，我们将 n 限制在 20 以内。
        printf("输入错误，请输入一个介于 1 到 20 之间的正整数。\n");
        return 1; 
    }

    // 2. 循环计算 1! 到 n! 的和
    // 优化：为了提高效率，避免重复计算阶乘，可以使用递推方式。
    // 但是，为了严格符合题目要求“输出1～n 的阶乘和”以及函数的定义，
    // 我们将继续使用调用函数的方式，以保持程序的模块化和可读性。
    for (int i = 1; i <= n; i++) {
        unsigned long long fact_i = factorial(i); // 计算 i 的阶乘
        sum += fact_i; // 累加到总和
    }

    // 3. 格式化输出结果
    // 输出格式: 1! + 2! + ... + n! = sum
    for (int i = 1; i <= n; i++) {
        printf("%d!", i);
        if (i < n) {
            printf(" + "); // 非最后一项，打印加号
        }
    }
    // 使用 %llu 格式符输出 unsigned long long 类型
    printf(" = %llu\n", sum);

    return 0; 
}