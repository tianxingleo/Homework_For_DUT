#include <stdio.h>  

int main() {
    int year;

    // TODO
    printf("请输入年份：");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0)||year%400==0)
    {
        printf("%d 是闰年",year);
    }
    else
    {
        printf("%d 不是闰年", year);
    }

    return 0;
}