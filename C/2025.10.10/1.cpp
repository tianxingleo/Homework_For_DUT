#include <stdio.h>  

int main() {
    float fahrenheit;   // 华氏温度
    float celsius;      // 摄氏温度

    // TODO
    printf("请输入华氏温度: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("对应的摄氏温度为: %.2f", celsius);

    return 0;
}
