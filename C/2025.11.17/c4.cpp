#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)

bool isValidTime(Time *t) {
    if (t->year < 0 || t->month < 1 || t->month > 12 ||
        t->day < 1 || t->hour < 0 || t->hour > 23 ||
        t->minute < 0 || t->minute > 59 || t->second < 0 || t->second > 59) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(t->year)) {
        daysInMonth[2] = 29;
    }

    if (t->day > daysInMonth[t->month]) {
        return false;
    }

    return true;
}

int main() {
    Time t;

    printf("请输入时间（年 月 日 时 分 秒）：");
    if (scanf("%d %d %d %d %d %d", &t.year, &t.month, &t.day, &t.hour, &t.minute, &t.second) != 6) {
        printf("输入格式错误！\n");
        return 1;
    }

    if (isValidTime(&t)) {
        printf("输入的时间是：%04d/%02d/%02d %02d:%02d:%02d\n", 
               t.year, t.month, t.day, t.hour, t.minute, t.second);
    } else {
        printf("输入的时间无效！\n");
    }

    return 0;
}