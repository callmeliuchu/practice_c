//
// Created by 刘楚 on 2020/11/22.
//
#include <cstdio>
#define MAX 20

int is_num(char c){
    if(c >= '0' and c <= '9'){
        return 1;
    }
    return 0;
}




int main(){
    char s[] = "sjhgdhj123ajhds45jdh6?b789&234TGD89e";
    char *p=s;
    int arr[MAX];
    int n = 0;
    while(*p){
        while(*p && !is_num(*p))p++;
        int num=0;
        int flag = 0;
        while(*p && is_num(*p)){
            num = num*10 + (*p-'0');
            p++;
            flag = 1;
        }
        if(flag){
            arr[n++] = num;
            printf("%d\n",num);
        }
    }


}