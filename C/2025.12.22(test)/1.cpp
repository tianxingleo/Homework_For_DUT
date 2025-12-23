#include <stdio.h>
int strcompare(char* str1,char* str2){
    while(1){
        if(*str1==*str2&&(*str1!='\0'&&*str2!='\0')){
            str1++;str2++;
        }else if(*str1!=*str2){
            return *str1-*str2;
        }else if(*str1=='\0'&&*str2=='\0'){
            return 0;
        }
    }
}