#include <stdio.h>

int main()
{
    char ch;        // 输入的字符

    // TODO
    printf("请输入一个字符: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        printf("输入的是大写字母: %c\n", ch);
    }
    else if (ch >= 'a' && ch <= 'z') {
        int a = ch - 32;
        printf("对应的大写字母是: %c\n", a);
    }
    else {
        printf("输入错误，请输入英文字母");
    }


    return 0;
}