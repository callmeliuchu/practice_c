//
// Created by 刘楚 on 2020/11/22.
//
#include "stdlib.h"
#include "stdio.h"
#define MAX 100

int main(){
    char s[MAX];
    char *p=s;
    while(scanf("%c",p++)!=EOF);
    p=s;
    char max = *s;
    while(*p){
        if(max < *p){
            max = *p;
        }
        p++;
    }
    printf("%c\n",max);
}