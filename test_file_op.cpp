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

struct student{
    int num;
    int score;
    char name[20];
};

void create(){
    FILE *fp;
    if((fp=fopen("data.db","wb"))==NULL){
        printf("can not open the file\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<10;i++){
        student stu = {10,100,"lihua"};
        fwrite(&stu,sizeof(student),1,fp);
    }
    fclose(fp);
}


void test_read(){
    FILE *fp;
    if((fp=fopen("data.db","rb"))==NULL){
        printf("can not open the file\n");
        exit(EXIT_FAILURE);
    }
    struct student stus[10];
    for(int i=0;i<10;i++){
        fseek(fp,i*sizeof(struct student),0);
        fread(&stus[i],sizeof(struct student),1,fp);
        printf("%d,%d,%s\n",stus[i].num,stus[i].score,stus[i].name);
    }
    fclose(fp);
}

int main(){
    test_read();
}