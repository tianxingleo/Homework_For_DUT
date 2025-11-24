#include <stdio.h>
#include <string.h>

// 反转字符串，所有程序内容都现在这个函数里面
void reverseString(char *str, int start, int end,char *reversed)
{
    char temp;			    // 临时变量，用于交换两个字符 

	// TODO: 将字符串str从start到end之间的部分进行反转
    //char reversed[100];		
    int j=0;
    int len=strlen(str),temp1=len-1,temp2=len-1;
    for(int i=len-1;i>=0;i--){
        if(str[i]==' '){
            temp1=i;
            for(int k=temp1+1;k<=temp2;k++){
                reversed[j]=str[k];
                j++;
            }
            reversed[j]=' ';
            j++;
            temp2=temp1-1;
        }
        
    }
    reversed[j]=' ';
    j++;
    for(int k=0;k<=temp1;k++){
        reversed[j-1]=str[k];
        j++;
    }
}

// 反转整个单词列表src，结果保存到dest
// void reverseWords(char *dest, char *src)
// {
//     int len;                // 单词列表的总长度
//     int start;              // 每个单词起始位置
//     int end;                // 每个单词结束位置
	
// 	// TODO 1:复制单词列表src到desc 
//     strcpy(dest,src);

    
// 	// TODO 2:使用reverseString函数反转desc中每个单词（用空格或'\0'分割单词） 
// 	// 例如：将 "I love c language" 变为 "I evol c egaugnal" 
    

    
//     // TODO 3:使用reverseString函数反转整个单词列表 
//     // 例如：将 "I evol c egaugnal" 变为 "language c love I" 
    


// }

int main()
{   printf("请输入多个单词：");
    char words[100];  								// 存储输入的单词列表 
    char reversed[100];								// 存储反转后的单词列表 

    // TODO: 接收用户输入的单词列表，按要求反转并输出
    if (fgets(words, sizeof(words), stdin) != NULL) {
        size_t ln = strlen(words);
        if (ln > 0 && words[ln - 1] == '\n') {
            words[ln - 1] = '\0';
        }
    } else {
        words[0] = '\0';
    }

    reverseString(words,0,strlen(words),reversed);
    printf("反转后的字符串：");
    printf("%s",reversed);
    
    return 0;
}