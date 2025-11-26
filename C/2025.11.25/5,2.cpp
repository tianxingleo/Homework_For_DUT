#include <stdio.h>
#include <stdbool.h>
#include <math.h> // 引入 math.h 以使用 sqrt 函数

// 函数声明
bool isPrime(int num);

/**
 * @brief 判断一个整数是否为素数
 * * @param num 待检查的整数
 * @return true/false
 */
bool isPrime(int num) {
    // 1. 特殊情况处理
    if (num < 2) {
        return false; 
    }
    if (num == 2) { // 2是唯一的偶素数
        return true; 
    }
    if (num % 2 == 0) {
        return false; // 大于2的偶数不是素数
    }

    // 2. 循环检查因子
    // 只检查到 sqrt(num)，从 3 开始，每次递增 2 (只检查奇数)
    int limit = (int)sqrt((double)num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) {
            return false; // 找到因子，不是素数
        }
    }

    return true; // 是素数
}

int main() {
    int num;

    // 1. 循环读取输入并进行有效性检查
    while (1) {
        printf("请输入一个不小于6的偶数: ");
        // 尝试读取输入
        if (scanf("%d", &num) != 1) {
            printf("输入错误，请输入一个整数。\n");
            // 清除输入缓冲区，防止无限循环
            while (getchar() != '\n'); 
            continue;
        }

        // 检查是否满足条件：不小于 6 的偶数
        if (num >= 6 && num % 2 == 0) {
            break; // 输入有效，跳出循环
        } else {
            // 注意：这里匹配范例中的输出格式
            printf("输入错误，请输入一个不小于6的偶数\n");
        }
    }

    // 2. 验证哥德巴赫猜想
    printf("%d =", num);
    bool first_pair = true; // 用于控制输出格式

    // 从 3 开始检查 p1
    // p1 循环到 num/2 即可 (例如 66 只需要检查到 33)
    for (int p1 = 3; p1 <= num / 2; p1 += 2) {
        
        if (isPrime(p1)) {
            int p2 = num - p1;
            
            // 只需要检查 p2 是否为素数
            if (isPrime(p2)) {
                // 控制输出格式：第一个分解直接输出，后面的用 " =" 分隔
                if (first_pair) {
                    printf(" %d + %d", p1, p2);
                    first_pair = false;
                } else {
                    printf(" = %d + %d", p1, p2); 
                }
            }
        }
    }
    printf("\n");

    return 0;
}