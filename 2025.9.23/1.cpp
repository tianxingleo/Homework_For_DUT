#include <stdio.h>
#include <windows.h>

int main()
{
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    // 打印李白的诗《静夜思》
    printf("   月   夜        思\n");
    printf("    [唐] 李白\n");
    printf("\n");
    printf("床  前  明  月  光，\n");
    printf("疑  是  地  上  霜。\n");
    printf("举  头  望  明  月，\n");
    printf("低  头  思  故  乡。\n");

    return 0;
}