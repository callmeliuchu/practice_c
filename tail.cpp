//
// Created by liuchu on 2020/12/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80

typedef struct node{
    char data[80];
    node *next;
}node;


int  main(int argc,char *args[]){
    FILE *fp;
    if(argc < 3){
        printf("not enough values\n");
        exit(EXIT_FAILURE);
    }
    char *filename = args[2];
    if((fp=fopen(filename,"r"))==NULL){
        printf("cannot open file");
        exit(EXIT_FAILURE);
    }
    char *sn = args[1];
    if(sn[0] != '-'){
        printf("not right format");
        exit(EXIT_FAILURE);
    }
    sn++;
    int n = atoi(sn);
    char temp[MAX];
    node *head=NULL;
    node *p = NULL;
    node *q = NULL;
    for(int i=0;i<n;i++){
        p = (node *)malloc(sizeof(node));
        if(q != NULL){
            q->next = p;
            q = p;
        }else{
            q = p;
            head = p;
        }
    }
    q->next = head;
    p = head;
    int count = 0;
    while(fgets(temp,MAX,fp)){
        strcpy(p->data,temp);
        p = p->next;
        count++;
    }
    if(count < n){
        p = head;
    }else{
        count = n;
    }
    for(int i=0;i<count;i++){
        printf("%s",p->data);
        p=p->next;
    }
}