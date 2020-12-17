//
// Created by liuchu on 2020/12/17.
//
#include <stdlib.h>
#include <stdio.h>

void test1(){
    FILE *fp;
    if((fp=fopen("test.txt","r")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    char ch;
    while((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
}


void test2(){
    FILE *fp;
    if((fp=fopen("test.txt","w")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    char ch;
    while(scanf("%c",&ch) != EOF){
        fputc(ch,fp);
    }
    fclose(fp);
}

void test3(){
    FILE *fp;
    if((fp=fopen("test.txt","r")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    char temp[80];
    while(fgets(temp,80,fp)){
        printf("%s",temp);
    }
}

void test4(){
    FILE *fp;
    if((fp=fopen("test1.txt","w")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    char temp[80];
    while(fgets(temp,80,stdin)){
        fputs(temp,fp);
    }
    fclose(fp);
}

void test5(){
    FILE *fp;
    if((fp=fopen("test.txt","r")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    int num;
    while(fscanf(fp,"%d",&num)!=EOF){
        printf("%d\n",num);
    }
}

void test6(){
    FILE *fp;
    if((fp=fopen("test.txt","w")) == NULL){
        printf("can open file\n");
        exit(EXIT_FAILURE);
    }
    char temp[80];
    while(fgets(temp,80,stdin)){
        fprintf(fp,"%s",temp);
    }
}




int main(){
    test6();
}