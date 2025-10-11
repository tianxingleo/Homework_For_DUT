

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




#include <stdio.h>  
#define PI 3.14159  

int main() {
    double diameter;		// 底面直径 
    double height; 			// 高 
    double radius, circumference, surfaceArea, volume;  // 半径、周长、表面积、体积 

    // TODO
    printf("请输入圆柱的底面直径（单位：厘米）: ");
    scanf("%lf", &diameter);
    printf("请输入圆柱的高（单位：厘米）: ");
    scanf("%lf", &height);
    radius = PI * diameter;
    circumference = (diameter / 2) * (diameter / 2) * PI;
    volume = circumference * height;
    printf("圆柱体底面周长为：%.2f厘米\n圆柱体表面积为：%.2f平方厘米\n圆柱体体积为：%.2f立方厘米\n",radius,circumference,volume);

    return 0;
}



/*
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
*/

/*

#include <stdio.h>

int main() {
    int startHour, startMinute;		// 起飞时、分
    int endHour, endMinute;			// 降落时、分

    // TODO
    printf("起飞时间（小时:分钟）: ");
    scanf("%d:%d", &startHour, &startMinute);
    printf("降落时间（小时:分钟）: ");
    scanf("%d:%d", &endHour, &endMinute);
    int delta_Hour,delta_Minute;
    if (startHour <= endHour) {
        delta_Hour = endHour - startHour-1;
        delta_Minute = (60 - startMinute) + endMinute;
        if (delta_Minute >= 60) {
            delta_Hour += 1;
            delta_Minute -= 60;
        }
    }
    else {
        delta_Hour = 24 - startHour + endHour-1;
        delta_Minute = (60 - startMinute) + endMinute;
        if (delta_Minute >= 60) {
            delta_Hour += 1;
            delta_Minute -= 60;
        }
    }
    printf("飞行时间：%d小时%d分钟", delta_Hour, delta_Minute);
    return 0;
}
*/

/*
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
*/

/*
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
*/