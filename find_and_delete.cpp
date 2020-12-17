//
// Created by 刘楚 on 2020/11/22.
//
#include <cstring>
#include "stdio.h"
#include "stdlib.h"


int find_delete(char *s,char c){
    for(int i=0;s[i];i++){
        if(s[i] == c){
            strcpy(s+i,s+i+1);
            return i;
        }
    }
    return -1;
}

int main(int argc,char *args[]){
    if(argc < 3){
        printf("not enough values");
        exit(EXIT_FAILURE);
    }
    char *s = args[1];
    char c = args[2][0];
    int loc = find_delete(s,c);
    if(loc == -1){
        printf("cannt find");
        exit(EXIT_FAILURE);
    }
    printf("%s\n",s);
}