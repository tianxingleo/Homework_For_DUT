// 在字符串 string 中查找是否包含子串 substr，并在主函数中输出包含子串的个数。

// 函数声明：int countSubstring ( const char string[ ],  const char substr[ ])

// 范例：
// 请输入长度不超过100的字符串：aaabcabcabccabcaabcbca
// 请输入要查找的子串：abc
// "abc" 在 "aaabcabcabccabcaabcbca" 中出现了5次


#include <stdio.h>  
#include <string>
#include <stdbool.h> 
#include <iostream>

using namespace std;
// 计算子串在主串中出现的次数
int countSubstring(string string_1,string substr) {  
    int count=0;								    // 记录匹配的次数
	int i, j; 									// 主串和子串的下标
	bool match;									// 匹配标识 	
	int subLength = substr.size();				// 计算子串的长度 
    int string_length=string_1.size();
	for(int i=0;i<=string_length-1;i++){
        if(string_1.find(substr,i)!=string::npos){
            i=string_1.find(substr,i)+subLength-1;
            count++;
        }
    }
	// TODO

    
    return count;  
}  

int main() {  
    string string_1;			// 输入的字符串 
    string substr;				// 要查找的子串 
    int count;						    // 子串出现的次数
    printf("请输入长度不超过100的字符串：");
    cin>>string_1;
    printf("请输入要查找的子串：");
    cin>>substr;
    // TODO
    //printf("\"%s\" 在 \"%s\" 中出现了%d次",string_1,substr,countSubstring(string_1,substr));
	cout<<"\""<<string_1<<"\" 在 \""<<substr<<"\" 中出现了"<<countSubstring(string_1,substr)<<"次";
    return 0;  
}