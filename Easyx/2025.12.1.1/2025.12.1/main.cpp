#include <graphics.h> // 引入 EasyX 头文件
#include <conio.h>

int main()
{
    // 初始化绘图窗口，宽640，高480
    initgraph(640, 480);

    // 设置背景颜色为白色
    setbkcolor(YELLOW);
    cleardevice();

    // 设置画笔颜色为黑色
    setlinecolor(BLACK);
    // 画一个圆，圆心(320, 240)，半径100
    //circle(320, 240, 100);

    //// 设置文字颜色和样式
    settextcolor(BLUE);
    //settextstyle(30, 0, _T("宋体"));
    //outtextxy(220, 220, _T("EasyX @ VS2026"));

    int line_x = 70, line_y = 50;

    for (int i = 1; i <= 15; i++) {
        line(line_x, line_y, line_x + 14*25, line_y);
        if ((16-i == 4 || 16-i == 12)) {
            fillcircle(line_x+ 25*3, line_y, 10);
            fillcircle(line_x + 25 * 11, line_y, 10);

        }
        if ((16 - i == 8)) {
            fillcircle(line_x + 25 * 7, line_y, 10);

        }
		line_y += 25;
        TCHAR s[50]; // 定义一个字符串缓冲区
        _stprintf_s(s, _T("%d"), 16-i);
        outtextxy(line_x-40, line_y-30,s);
        
    }

    line_x = 70;
    line_y = 50;
    
    for (int i = 1; i <= 15; i++) {
        line(line_x, line_y, line_x, line_y + 25 * 14);
        line_x += 25;
        TCHAR s[50]; // 定义一个字符串缓冲区
        _stprintf_s(s, _T("%c"), char(i-1+'A'));
        outtextxy(line_x - 30, line_y + 25 * 14+10, s);
    }
    




    // 按任意键退出
    _getch();
    closegraph();
    return 0;
}