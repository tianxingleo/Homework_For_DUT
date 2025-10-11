
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
