//
// Created by 刘楚 on 2020/11/21.
//
#include <cstring>
#include "stdlib.h"
#include "stdio.h"

int is_alph(char *s){
    while(*s){
        if(!(*s == 'A' || *s == 'T' || *s == 'G' || *s == 'G' || *s == 'a' || *s == 't' || *s == 'g' || *s == 'c') ){
            return 0;
        }
        s++;
    }
    return 1;
}

int is_legal(char *s){
    while(*s){
        if(!(*s >= 33 && *s <= 126)){
            return 0;
        }
        s++;
    }
    return 1;
}

int start_with(char *s,char c){
    if(*s == c){
        return 1;
    }
    return 0;
}

void edit(char *s){
    while(*s && *s != '\n'){
        s++;
    }
    *s = '\0';
}


int main(){
    FILE *fp ;
    if((fp=fopen("dna.txt","r"))==NULL){
        printf("cann open the file");
        exit(EXIT_FAILURE);
    }
    char temp[2000];
    int count = 1;
    int line2_len = 0;
    int line4_len = 0;
    while(fgets(temp,2000,fp)!=NULL){
        edit(temp);
        printf("%s\n",temp);
        if(count == 1){
            if(!start_with(temp,'@')){
                printf("line 1 wrong");
                exit(EXIT_FAILURE);
            }
        }
        if(count == 2){
            if(!is_alph(temp)){
                printf("line2 wrong");
                exit(EXIT_FAILURE);
            }
            line2_len = strlen(temp);
        }
        if(count == 3){
            if(!start_with(temp,'+')){
                printf("line3 wrong");
                exit(EXIT_FAILURE);
            }
        }
        if(count == 4){
            if(!is_legal(temp)){
                printf("line 4 wrong");
                exit(EXIT_FAILURE);
            }
            line4_len = strlen(temp);
        }
        count++;
    }
    if(count != 5){
        printf("line len wrong");
        exit(EXIT_FAILURE);
    }
    if(line2_len != line4_len){
        printf("line2 and line 4 not len equals");
        exit(EXIT_FAILURE);
    }
    printf("legal s");
    return 0;
}