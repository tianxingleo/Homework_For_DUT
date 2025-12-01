#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <iomanip> // 用于 std::put_time
#include <chrono>
#include <iostream>

int main()
{
    initgraph(640, 480);
    setbkcolor(WHITE);  // 1. 只是设置了“要把背景刷成什么色”
    cleardevice();     // 2. 真正动手把屏幕“刷”一遍
    BeginBatchDraw();


    while (1) {
        cleardevice();


        // 1. 设置边框颜色 (圆周的颜色)
        setlinecolor(LIGHTGRAY);

        // 2. 设置填充颜色 (圆内部的颜色)
        setfillcolor(WHITE);

        // 3. 画圆 (圆心x: 200, 圆心y: 240, 半径: 100)
        fillcircle(300, 240, 200);
        setfillcolor(LIGHTGRAY);
        fillcircle(300, 240, 190);
        

        int width = 300;
        int height = 240;

        // 1. 获取当前系统时间点
        auto now = std::chrono::system_clock::now();

        // 2. 转换为 std::time_t 以便格式化
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm parts;
        localtime_s(&parts, &now_c);

        // 4. 直接访问结构体成员获取时、分、秒
        int hour = parts.tm_hour;
        int min = parts.tm_min;
        int sec = parts.tm_sec;
        std::cout << hour << std::endl << min << std::endl << sec;


        // 1. 定义中心点和最大半径
        int centerX = width;
        int centerY = height;
        // 计算中心到角落的距离作为最大半径 (勾股定理)
        // sqrt(320*320 + 240*240) = 400
        double maxRadius = 190;

        // 2. 定义颜色范围
        // 中心是白色 (255)，边缘是灰色 (比如 80，越小越黑)
        int centerColorVal = 255;
        int edgeColorVal = 200;
        int colorDiff = centerColorVal - edgeColorVal; // 颜色差值 (175)

        // 3. 开始循环画同心圆
        // 【关键】从最大半径开始往里画，步长为 1 或 2 都可以，越小越细腻
        for (int r = (int)maxRadius; r > 0; r -= 1)
        {
            // --- 计算当前半径对应的颜色 ---

            // 计算当前半径占最大半径的比例 (0.0 到 1.0 之间)
            // 靠近中心时接近 0，靠近边缘时接近 1
            double ratio = (double)r / maxRadius;

            // 线性插值计算当前灰度值
            // 核心思想：基础白色 - (要变黑的总量 * 当前进度比例)
            int currentColorVal = centerColorVal - (int)(colorDiff * ratio);

            // 合成 RGB 颜色 (因为是灰度渐变，RGB三个值相等)
            COLORREF color = RGB(currentColorVal, currentColorVal, currentColorVal);

            // --- 绘图 ---
            // 设置描边和填充都为这个颜色，然后画实心圆
            setlinecolor(color);
            setfillcolor(color);
            fillcircle(centerX, centerY, r);
        }

        //画刻度
        setlinecolor(BLACK);
        settextstyle(20, 0, _T("黑体"));
        setbkmode(TRANSPARENT);
        settextcolor(BLACK);
        setlinestyle(PS_SOLID, 1.5);
        for (int temp_min = 1; temp_min <= 60; temp_min++) {
            if (temp_min % 5 == 0) {
                setlinestyle(PS_SOLID, 3);
            }
            int kedu_x1 = 300 + 185 * cos(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            int kedu_y1 = 240 - 185 * sin(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            int kedu_x2 = 300 + 175 * cos(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            int kedu_y2 = 240 - 175 * sin(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            int kedu_x3 = 300 + 160 * cos(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            int kedu_y3 = 240 - 160 * sin(-double(temp_min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
            line(kedu_x1, kedu_y1, kedu_x2, kedu_y2);
            if (temp_min % 5 == 0) {
                wchar_t s1[20]; // 定义一个能装下20个字的数组
                swprintf_s(s1, L"%d", temp_min/5); // 注意前面的 L
                outtextxy(kedu_x3-5, kedu_y3-10, s1);
            }
            setlinestyle(PS_SOLID, 1.5);
        }
        
        //line(kedu_x1, kedu_y1, kedu_x2, kedu_y2);

        //画指针
        setlinecolor(BLACK);
        setlinestyle(PS_SOLID, 10);
        int hour_x = 300 + 120 * cos(-double(hour % 12) / 12 * 2 * 3.1415926 + 3.1415926 / 2);
        int hour_y = 240 - 120 * sin(-double(hour % 12) / 12 * 2 * 3.1415926 + 3.1415926 / 2);
        line(300, 240, hour_x, hour_y);

        setlinestyle(PS_SOLID, 7.5);
        int min_x = 300 + 160 * cos(-double(min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
        int min_y = 240 - 160 * sin(-double(min) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
        line(300, 240, min_x, min_y);


        setlinestyle(PS_SOLID, 5);
        setlinecolor(RED);
        int sec_x = 300 + 160 * cos(-double(sec) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
        int sec_y = 240 - 160 * sin(-double(sec) / 60 * 2 * 3.1415926 + 3.1415926 / 2);
        line(300, 240, sec_x, sec_y);

        setfillcolor(RED);
        fillcircle(300, 240, 2.5);


        FlushBatchDraw();
        Sleep(100);
    }
    

    _getch();
    closegraph();
    return 0;
}