// 编写 C 程序，用下面两种方式将姓名按长度进行冒泡排序并打印。
// 冒泡排序的本质是 “相邻元素比较交换”，每轮将未排序部分的最大值（此处为 “最长字符串”）移动到末尾。
// （1）用二维数组存储姓名
// char name[5][10] = {"zhangsan", "sam", "sally", "meimei", "jack"};

// 函数声明：
// ​    void sortByLength ( char (*p)[10],  int n )
// ​    p是数组指针，n是字符串的个数
// 要求：在函数内部使用排序算法交换字符串的值

// （2）用指针数组存储姓名
// char* name2[5] = {"zhangsan", "sam", "sally", "meimei", "jack"};

// 函数声明：
// ​    void sortByLength2 ( char* p[],  int n )
// ​    p是指针数组，n是字符串的个数
// 要求：在函数内部使用排序算法交换字符串的地址

// 范例：
// 方法1 排序前：zhangsan sam sally meimei jack
// 方法1 排序后：sam jack sally meimei zhangsan
// 方法2 排序前：zhangsan sam sally meimei jack
// 方法2 排序后：sam jack sally meimei zhangsan


#include <stdio.h>
#include <string.h>
#define STR_NUM 5				// 字符串的个数
#define MAX_LEN 10				// 字符串的最大长度 

// 遍历数组（以数组指针做参数，n是字符串的个数）
void printArray(char (*p)[MAX_LEN], int n)
{
	// TODO
    
    for(int i=0;i<n;i++){
        printf("%s ",p[i]);
    }
}

// 使用冒泡排序算法，交换两个字符串的值（参数同上）
void sortByLength(char (*p)[MAX_LEN], int n) 
{
    char temp[MAX_LEN]; 		// 临时字符数组，用于交换
    // TODO
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strlen(p[j])>strlen(p[j+1])){
                strcpy(temp,p[j]);
                strcpy(p[j],p[j+1]);
                strcpy(p[j+1],temp);
            }
        }
    }
	
}

// 遍历数组（以指针数组做参数，n是字符串的个数）
void printArray2(char* p[], int n)
{
    // TODO
    for(int i=0;i<n;i++){
        printf("%s ",p[i]);
    }

}

// 使用冒泡排序算法，交换两个字符串的地址（参数同上）
void sortByLength2(char* p[], int n)
{
    char *temp = NULL;  		// 临时字符指针，用于交换
    // TODO
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strlen(p[j])>strlen(p[j+1])){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

int main()
{	
	char name[STR_NUM][MAX_LEN] = {"zhangsan", "sam", "sally", "meimei", "jack"};   // 用二维字符数组存储多个字符串
    // TODO：用方法1输出排序前后的值
    printf("法1 排序前：");
    printArray(name,STR_NUM);
    sortByLength(name,STR_NUM);
    printf("\n法1 排序后：");
    printArray(name,STR_NUM);
    
	
	
	char* name2[STR_NUM] = {"zhangsan", "sam", "sally", "meimei", "jack"};	        // 用指针数组存储多个字符串
    // TODO：用方法2输出排序前后的值
    printf("\n法2 排序前：");
    printArray2(name2,STR_NUM);
    sortByLength2(name2,STR_NUM);
    printf("\n法2 排序后：");
    printArray2(name2,STR_NUM);


    return 0;
}