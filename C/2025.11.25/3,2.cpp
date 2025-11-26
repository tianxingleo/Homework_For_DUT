#include <stdio.h>

// 穷举法计算最大公约数 (GCD)
int gcd_bruteforce(int a, int b) {
    int min, gcd = 1;
    
    // 确保 a 和 b 都是正整数
    if (a <= 0 || b <= 0) return -1; 
    
    // 找出较小的数，作为循环的上限
    min = (a < b) ? a : b;
    
    // 从 1 遍历到较小的数
    for (int d = 1; d <= min; d++) {
        // 如果 d 能同时整除 a 和 b，则 d 是当前找到的最大公约数
        if (a % d == 0 && b % d == 0) {
            gcd = d;
        }
    }
    return gcd;
}

// 迭代法（辗转相除法/欧几里得算法）计算最大公约数 (GCD)
int gcd_euclidean(int a, int b) {
    int temp;

    // 欧几里得算法要求输入正整数
    if (a <= 0 || b <= 0) return -1; 
    
    // 使用 while 循环实现迭代
    while (b != 0) {
        temp = a % b; // 计算余数 r = a % b
        a = b;        // 更新 a = b
        b = temp;     // 更新 b = r
    }
    
    return a; // 当 b 为 0 时，a 即为最大公约数
}


int main() {
    int num1, num2;
    int gcd_e, gcd_b; // 存储两种方法的结果
    
    // 1. 获取用户输入
    printf("请输入两个正整数：");
    // 使用 %d 读取 int 类型数据
    if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) {
        printf("输入错误，请确保输入两个正整数。\n");
        return 1; // 返回错误代码
    }
    
    // 2. 使用穷举法计算
    gcd_b = gcd_bruteforce(num1, num2);
    
    // 3. 使用迭代法（辗转相除法）计算
    // 辗转相除法不要求 a > b，但为了保持函数独立性，我们在 main 中直接调用。
    gcd_e = gcd_euclidean(num1, num2);
    
    // 4. 输出结果
    printf("%d和%d的最大公约数是（穷举法）：%d\n", num1, num2, gcd_b);
    printf("%d和%d的最大公约数是（迭代法）：%d\n", num1, num2, gcd_e);
    
    return 0;
}