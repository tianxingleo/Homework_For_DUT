#include <stdio.h>
#include <string.h>
#include <stdbool.h> // 引入 bool 类型

// 函数声明
int countSubstring(const char string[], const char substr[]);

/**
 * @brief 计算子串在主串中出现的次数（非重叠计数）
 * @param string 主字符串
 * @param substr 待查找的子字符串
 * @return int 子串出现的次数
 */
int countSubstring(const char string[], const char substr[]) {
    int count = 0;
    int i, j;
    int subLength = strlen(substr); // 子串长度
    int strLength = strlen(string); // 主串长度
    
    // 边界条件判断：如果子串为空或比主串长，则出现次数为 0
    if (subLength == 0 || subLength > strLength) {
        return 0;
    }
    
    // 朴素匹配算法：i 是主串中待匹配的起始位置
    // 循环条件 i <= strLength - subLength 确保主串剩余长度足够匹配子串
    for (i = 0; i <= strLength - subLength; i++) {
        bool match = true;
        
        // 比较子串的每个字符
        for (j = 0; j < subLength; j++) {
            if (string[i + j] != substr[j]) {
                match = false;
                break; // 只要有一个字符不匹配，立即跳出内层循环
            }
        }
        
        // 如果内层循环完成且 match 仍为 true，说明找到一次匹配
        if (match) {
            count++;
            // 注意：此实现计算的是非重叠匹配。若要计算重叠匹配，只需移除此注释即可。
        }
    }
    
    return count;
}

int main() {
    // 考虑到输入长度不超过100，数组大小设为101以容纳空字符 '\0'
    char string[101] = {0}; 
    char substr[101] = {0}; 
    int count;

    // 1. 读取主串
    printf("请输入长度不超过100的字符串：");
    // 使用 %100s 限制读取长度，防止缓冲区溢出
    if (scanf("%100s", string) != 1) {
        printf("读取主串失败。\n");
        return 1; 
    }
    
    // 2. 读取子串
    printf("请输入要查找的子串：");
    if (scanf("%100s", substr) != 1) {
        printf("读取子串失败。\n");
        return 1; 
    }

    // 3. 调用函数并获取结果
    count = countSubstring(string, substr);

    // 4. 输出结果
    // 匹配范例输出格式
    printf("\"%s\" 在 \"%s\" 中出现了%d次。\n", substr, string, count);
    
    return 0;
}