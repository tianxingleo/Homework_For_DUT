#include <stdio.h>  

int main() {
    int a, b, c;    // 三角形的三条边长

    // TODO
    printf("请输入三个整数（三角形的三边长）：");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c>b && b + c > a) {
        if (a == b && b == c && a == c) {
            printf("这是一个等边三角形");
        }
        else if (a == b || a == c || c == b) {
            printf("这是一个等腰三角形");
        }
        else {
            printf("这是一个不等边三角形");
        }

    }
    else {
        printf("这不能构成一个三角形");
    }

    return 0;
}