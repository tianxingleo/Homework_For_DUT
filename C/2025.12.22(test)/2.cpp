#include <stdio.h>
#include<math.h>

int to_string(int* arr,int a){
    int length;
    for(int i=0;;i++){
        if(a/pow(10,i)<10){
            length=i;
            break;
        }
    }
    for(int i=length,temp=0;i>=0;i--){
        arr[length-i]=(int)((a-temp)/pow(10,i));
        temp+=arr[length-i]*pow(10,i);
    }
    return length;
}

int compare(int* arr1,int length1,int*arr2,int length2){
    for(int i=length1,j=length2;i>=0;){
        if(arr1[i]==arr2[j]){
            i--;j--;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    int temp_arr1[5],temp_arr2[5],length1,length2;
    // int list[100],number=0;
    for(int i=1,i_2;i<100;i++){
        length1=to_string(temp_arr1,i);
        length2=to_string(temp_arr2,pow(i,2));
        if(compare(temp_arr1,length1,temp_arr2,length2)==1){
            printf("%d\n",i);
        }
    }

    return 0;
}