#include <stdio.h> 
#define PI 3.14159 

int main() {
    double diameter;        // 底面直径 
    double height;          // 高 
    double radius, circumference, surfaceArea, volume;   // 半径、周长、表面积、体积 
    double baseArea;      // 底面积 (辅助变量)

    printf("请输入圆柱的底面直径（单位：厘米）: ");
    scanf("%lf", &diameter);
    printf("请输入圆柱的高（单位：厘米）: ");
    scanf("%lf", &height);
    
    // 1. 计算半径 (r = d / 2)
    radius = diameter / 2.0; 
    
    // 2. 计算底面周长 (C = π * d)
    circumference = PI * diameter;
    
    // 3. 计算底面积 (A_base = π * r^2)
    baseArea = PI * radius * radius;
    
    // 4. 计算表面积 (S = 2 * A_base + 侧面积 = 2 * A_base + C * h)
    surfaceArea = 2 * baseArea + circumference * height;
    
    // 5. 计算体积 (V = A_base * h)
    volume = baseArea * height;
    
    // 6. 输出结果
    printf("圆柱体底面周长为：%.2f厘米\n", circumference);
    printf("圆柱体表面积为：%.2f平方厘米\n", surfaceArea);
    printf("圆柱体体积为：%.2f立方厘米\n", volume);

    return 0;
}