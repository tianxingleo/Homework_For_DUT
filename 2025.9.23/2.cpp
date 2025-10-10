#include <stdio.h>
#include <stdbool.h>

int main() {

    char a = 'A';
    short b = 10;
    int c = 20;
    long d = 1234567890L;
    long long e = 1234567890LL;
    float f = 3.14159f;
    double g = 3.1415926536;
    long double h = 0.0000000000L;
    bool i = true;
    bool j = false;

    printf("变量a的值是：%c\n", a);
    printf("变量b的值是：%hd\n", b);
    printf("变量c的值是：%d\n", c);
    printf("变量d的值是：%ld\n", d);
    printf("变量e的值是：%lld\n", e);
    printf("变量f的值是：%f\n", f);
    printf("变量g的值是：%.10f\n", g); 
    printf("变量h的值是：%.10Lf\n", h);
    printf("变量i的值是：%d\n", i);
    printf("变量j的值是：%d\n", j);

    printf("\n变量a的内存地址是：%p\n", (void *)&a);
    printf("变量b的内存地址是：%p\n", (void *)&b);
    printf("变量c的内存地址是：%p\n", (void *)&c);
    printf("变量d的内存地址是：%p\n", (void *)&d);
    printf("变量e的内存地址是：%p\n", (void *)&e);
    printf("变量f的内存地址是：%p\n", (void *)&f);
    printf("变量g的内存地址是：%p\n", (void *)&g);
    printf("变量h的内存地址是：%p\n", (void *)&h);
    printf("变量i的内存地址是：%p\n", (void *)&i);
    printf("变量j的内存地址是：%p\n", (void *)&j);

    printf("\nchar类型使用%zu个字节的内存\n", sizeof(char));
    printf("short类型使用%zu个字节的内存\n", sizeof(short));
    printf("int类型使用%zu个字节的内存\n", sizeof(int));
    printf("long类型使用%zu个字节的内存\n", sizeof(long));
    printf("long long类型使用%zu个字节的内存\n", sizeof(long long));
    printf("float类型使用%zu个字节的内存\n", sizeof(float));
    printf("double类型使用%zu个字节的内存\n", sizeof(double));
    printf("long double类型使用%zu个字节的内存\n", sizeof(long double));
    printf("bool类型使用%zu个字节的内存\n", sizeof(bool));

    return 0;
}
