#include <stdio.h>

// 定义学生结构体
typedef struct {
    char id[20];     // 学号（字符串）
    char name[20];   // 姓名（字符串）
    int scores[3];   // 3门课程成绩
    float avg;       // 平均成绩，保留小数点后两位
} Student;

// 显示菜单
void showMenu() {
    printf("====================学生信息管理系统=====================\n");
    printf("1. 录入学生信息\n");
    printf("2. 按平均成绩降序排序\n");
    printf("3. 输出所有学生信息\n");
    printf("4. 退出系统\n");
    printf("=========================================================\n");
}

// 功能1：录入学生信息（计算平均成绩）
void addStudent(Student *students, int *count) {
    Student *newStu;        // 指向待添加的学生结构体（需通过参数计算）

    // TODO
    if(*count>=10){
        printf("学生数量已达上限\n");
        return;
    }
    printf("请输入学号：");
    scanf("%s",&(students[*count].id));
    printf("请输入姓名：");
    scanf("%s",&(students[*count].name));
    printf("请输入3门课程成绩（空格分隔）：");
    scanf("%d %d %d",&(students[*count].scores[0]),&(students[*count].scores[1]),&(students[*count].scores[2]));
    students[*count].avg=(students[*count].scores[0]+students[*count].scores[1]+students[*count].scores[2])/3.0;
    printf("录入成功\n");
    (*count)++;
}

// 2：按平均成绩降序排序（冒泡排序）
void sortStudents(Student *students, int count) {
    Student temp;           // 临时变量，用于交换两个结构体    

    // TODO
    if(count<=1){
        printf("无需排序！\n");
        return ;
    }
    double temp_arr[10];
    int temp_int=0;
    for(int i=0;i<count;i++){
        for (int j=i;j<count;j++){
            if(temp_int<students[j].avg){
                temp_int=j;
            }
        }
        temp=students[i];
        students[i]=students[temp_int];
        students[temp_int]=temp;

    }
    printf("排序完成\n");

}

// 3：输出所有学生信息
void printAll(Student *students, int count) {

    if(count<=0){
        printf("暂无学生信息\n");
        return;
    }

    printf("====================所有学生信息=========================\n");
    printf("%-10s %-10s %-8s %-8s %-8s %-8s\n", 
           "学号", "姓名", "课程1", "课程2", "课程3", "平均成绩");
    printf("---------------------------------------------------------\n");

    // TODO: 输出所有学生信息，内容和标题左侧对齐
        for(int i=0;i<count;i++){
            printf("%-10s %-10s %-8d %-8d %-8d %-8.2f\n",
                   students[i].id, students[i].name,
                   students[i].scores[0], students[i].scores[1], students[i].scores[2],
                   students[i].avg);
        }

    printf("=========================================================\n");
}
 
int main() {
    Student students[10];  // 最多存储10名学生
    int count = 0;         // 当前已存储的学生数量
    int choice;			   // 用户的选项 

    // TODO: 显示菜单，提示用户选择功能，调用对应函数完成功能并提示操作结果
    while(1){
        
        showMenu();
        printf("请输入选择（1-4）：");
        scanf("%d",&choice);
        if(choice==1){
            addStudent(students,&count);
        }else if(choice ==2){
            sortStudents(students,count);
        }else if(choice ==3){
            printAll(students,count);
        }else if(choice==4){
            break;
        }else{
            printf("输入错误，请重新选择");
        }
    }
    printf("退出系统，感谢使用");

    return 0;
}