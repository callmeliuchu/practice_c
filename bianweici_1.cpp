//
// Created by liuchu on 2020/12/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80


void lower(char *s){
    while(*s){
        if(*s >= 'A' && *s <= 'Z'){
            *s = 'a' + (*s - 'A');
        }
        s++;
    }
}
void convert(char *s,int *arr){
    while(*s){
        arr[*s-'a']++;
        s++;
    }
}

void sort(char s[][80],int n){
    for(int i=0;i<n;i++){
        char temp[80];
        strcpy(temp,s[i]);
        int loc = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(temp,s[j])>0){
                strcpy(temp,s[j]);
                loc = j;
            }
        }
        strcpy(s[loc],s[i]);
        strcpy(s[i],temp);
    }
}


int is_similar(char *s1,char *s2){
    int arr1[26] = {0};
    int arr2[26] = {0};
    convert(s1,arr1);
    convert(s2,arr2);
    for(int i=0;i<26;i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc,char *args[]){
    if(argc < 3){
        printf("not enough values\n");
        exit(EXIT_FAILURE);
    }
    char *filename = args[1];
    char *target = args[2];
    FILE *fp;
    if((fp=fopen(filename,"r")) == NULL){
        printf("cannt open the file\n");
        exit(EXIT_FAILURE);
    }
    char temp[MAX];
    char result[100][80];
    int count = 0;
    lower(target);
    while(fscanf(fp,"%s",temp) != EOF){
        lower(temp);
        if(is_similar(temp,target)){
            strcpy(result[count++],temp);
        }
    }
    for(int i=0;i<count;i++){
        printf("%s\n",result[i]);
    }
    printf("---------------------------");
    sort(result,count);
    for(int i=0;i<count;i++){
        printf("%s\n",result[i]);
    }
}