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

    printf("����a��ֵ�ǣ�%c\n", a);
    printf("����b��ֵ�ǣ�%hd\n", b);
    printf("����c��ֵ�ǣ�%d\n", c);
    printf("����d��ֵ�ǣ�%ld\n", d);
    printf("����e��ֵ�ǣ�%lld\n", e);
    printf("����f��ֵ�ǣ�%f\n", f);
    printf("����g��ֵ�ǣ�%.10f\n", g); 
    printf("����h��ֵ�ǣ�%.10Lf\n", h);
    printf("����i��ֵ�ǣ�%d\n", i);
    printf("����j��ֵ�ǣ�%d\n", j);

    printf("\n����a���ڴ��ַ�ǣ�%p\n", (void *)&a);
    printf("����b���ڴ��ַ�ǣ�%p\n", (void *)&b);
    printf("����c���ڴ��ַ�ǣ�%p\n", (void *)&c);
    printf("����d���ڴ��ַ�ǣ�%p\n", (void *)&d);
    printf("����e���ڴ��ַ�ǣ�%p\n", (void *)&e);
    printf("����f���ڴ��ַ�ǣ�%p\n", (void *)&f);
    printf("����g���ڴ��ַ�ǣ�%p\n", (void *)&g);
    printf("����h���ڴ��ַ�ǣ�%p\n", (void *)&h);
    printf("����i���ڴ��ַ�ǣ�%p\n", (void *)&i);
    printf("����j���ڴ��ַ�ǣ�%p\n", (void *)&j);

    printf("\nchar����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(char));
    printf("short����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(short));
    printf("int����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(int));
    printf("long����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(long));
    printf("long long����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(long long));
    printf("float����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(float));
    printf("double����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(double));
    printf("long double����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(long double));
    printf("bool����ʹ��%zu���ֽڵ��ڴ�\n", sizeof(bool));

    return 0;
}
