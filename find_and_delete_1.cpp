//
// Created by liuchu on 2020/12/16.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int delete_s(char *s,char c){
    for(int i=0;*s;s++,i++){
        if(*s == c){
            strcpy(s,s+1);
            return i;
        }
    }
    return -1;
}


int main(int argc,char *args[]){
    if(argc < 3){
        puts("not enough values");
        exit(EXIT_FAILURE);
    }
    char *s = args[1];
    char c = args[2][0];
    int loc = delete_s(s,c);
    if(loc == -1){
        puts("cannot find the char");
        exit(EXIT_FAILURE);
    }
    puts(s);
}
