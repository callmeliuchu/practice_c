//
// Created by liuchu on 2020/12/16.
//
#include <stdio.h>

int freqs(char *source,char *target){
    int count = 0;
    while(*source){
        char *s1 = source;
        char *s2 = target;
        while(*s1 && *s2 && *s1 == *s2){
            s1++;
            s2++;
        };
        if(!*s2){
            puts(source);
            puts(s1);
            puts(s2);
            puts("----");
            count++;
        }
        source++;
    }
    return count;
}



int main(int argc,char *args[]){
    char source[] = "jdksjdkjkjdjjjd";
    char target[] = "jd";
    printf("freqs --> %d",freqs(source,target));
}