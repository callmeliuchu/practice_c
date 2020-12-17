//
// Created by liuchu on 2020/12/16.
//
#include <stdio.h>
#define MAX 100

int main(){
    char s[MAX];
    char *p = s;
    while(scanf("%c",p++)!=EOF);
    puts(s);
    *p='\0';
    puts(s);
    p = s;
    char max = *p;
    while(*p){
        if(max < *p){
            max = *p;
        }
        p++;
    }
    printf("max char: %c\n",max);
    return 0;
}