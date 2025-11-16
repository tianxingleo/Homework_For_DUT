#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int target_num;							// 随机生成的数
	int guess_num;							// 玩家猜测的数
	int guess_count;						// 猜测的次数
    srand(time(NULL)); 						// 初始化随机数种子

    //TODO
    char a;
    while(1){
        target_num=rand()%100+1;
        //printf("%d\n",target_num);
        for(guess_count=1;guess_count<=6;guess_count++){
            printf("输入猜测的数字");
            scanf("%d",&guess_num);
            if(guess_num==target_num){
                printf("你赢了，一共猜了%d次\n",guess_count);
                break;
            }else if(guess_num<target_num){
                printf("你猜小了\n");
            }else{
                printf("你猜大了\n");
            }
        }
        if(guess_count==7){
            printf("你输了，正确的数是%d\n",target_num);
        }
        printf("是否进入下一轮答题(y/n)");
        scanf("%c",&a);//用于不读到\n
        scanf("%c",&a);
        if(a=='n'){
            break;
        }
    }
    return 0;  
}