
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