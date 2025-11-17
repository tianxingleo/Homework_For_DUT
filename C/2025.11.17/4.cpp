// 编写 C 程序，提示用户输入时间（年、月、日、时、分、秒），保存到结构体类型 Time 中，并通过 isValidTime 函数判断输入的时间是否有效，如果有效则按格式 "年/月/日 时:分:秒" 打印，否则提示无效。

// 函数声明：
// ​    bool isValidTime ( Time *t )

// 范例：
// 请输入时间（年 月 日 时 分 秒）：2025 11 1 9 30 0
// 输入的时间是：2024/11/01 09:30:00

// 请输入时间（年 月 日 时 分 秒）：2025 13 1 9 30 0
// 输入的时间无效！

#include <stdio.h>    
#include <time.h>  
#include <stdbool.h>  
#include <stdlib.h>
  
// 定义时间结构体  
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
} Time;
  
// 判断是否为闰年  
bool isLeapYear(int year) { 
    bool isLeapYear; 
    // TODO
    if((year%4==0&&year%100!=0)||year%400==0){
        isLeapYear=1;
    }else{
        isLeapYear=0;
    }

    return isLeapYear;
}  
  
// 获取某年某月的天数  
int getDaysInMonth(int year, int month) {  
    int days;
    // TODO
    if(month=2){
        if(isLeapYear(year)==1){
            days=29;
        }else if(isLeapYear(year)==0){
            days=28;
        }
    }else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){//big
        days=31;
    }else{
        days=30;
    }

    return days;  
}  
  
// 判断时间的有效性  
bool isValidTime(Time *t) {  
    bool isValidTime;
    // TODO
    if(t->month>0&&t->month<13){
        if(t->day<=getDaysInMonth(t->year,t->month)&&t->day>0){
            if(t->hour>0&&t->hour<=24&&t->min>0&&t->min<60&&t->sec>0&&t->sec<60){
                isValidTime=0;
            }else{
                isValidTime=1;
            }
        }else{
            isValidTime=0;
        }
    }else{
        isValidTime=0;
    }

    return isValidTime;  
}  

int main() {  
    Time t;  					// 声明时间类型结构体变量     
    // TODO
    printf("请输入时间（年 月 日 时 分 秒）：");
    scanf("%d %d %d %d %d %d",&t.year,&t.month,&t.day,&t.hour,&t.min,&t.sec);
    if(isValidTime(&t)==0){
        printf("输入的时间无效！");
    }else if(isValidTime(&t)==1){
        printf("输入的时间是：%d/",t.year);
        if(t.month>=10){
            printf("%d/",t.month);
        }else{
            printf("0%d/",t.month);
        }
        if(t.month>=10){
            printf("%d/",t.month);
        }else{
            printf("0%d/",t.month);
        }
        if(t.day>=10){
            printf("%d ",t.day);
        }else{
            printf("0%d ",t.day);
        }
        if(t.hour>=10){
            printf("%d:",t.hour);
        }else{
            printf("0%d:",t.hour);
        }
        if(t.min>=10){
            printf("%d:",t.min);
        }else{
            printf("0%d:",t.min);
        }
        if(t.sec>=10){
            printf("%d",t.sec);
        }else{
            printf("0%d",t.sec);
        }
    }
    
    return 0;  
}