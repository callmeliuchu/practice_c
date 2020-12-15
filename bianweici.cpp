#include <cstring>
#include "stdio.h"
#include "stdlib.h"


void get_count(char *s1,int *arr){
    for(;*s1;s1++){
        arr[*s1-'a'] += 1;
    }
}

void lower(char *s){
    while(*s){
        if(*s >= 'A' && *s <= 'Z'){
            *s = 'a' + (*s-'A');
        }
        s++;
    }
}


int is_similar(char *s1,char *s2){
    if(strcmp(s1,s2)==0){
        return 0;
    }
    int arr1[26] = {0};
    int arr2[26] = {0};
    get_count(s1,arr1);
    get_count(s2,arr2);
    for(int i=0;i<26;i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

void sort(char s[][20],int n){
    for(int i=0;i<n;i++){
        char tmp[20];
        strcpy(tmp,s[i]);
        int loc = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(tmp,s[j])>0){
                strcpy(tmp,s[j]);
                loc = j;
            }
        }
        strcpy(tmp,s[i]);
        strcpy(s[i],s[loc]);
        strcpy(s[loc],tmp);
    }
}



int main(int argc,char *args[]){
    if(argc < 3){
        printf("not enough values");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if((fp=fopen(args[2],"r")) == NULL){
        printf("cannt open file");
        exit(1);
    }
    char tmp[20];
    char source[20];
    strcpy(source,args[1]);
    lower(source);
    char str_arr[100][20];
    int count = 0;
    while(fscanf(fp,"%s",tmp)!=EOF){
        lower(tmp);
        if(is_similar(tmp,source)){
//            printf("%s\n",tmp);
            strcpy(str_arr[count++],tmp);
        }
    }
    if(count <= 0){
        printf("NONE");
        return 0;
    }
    sort(str_arr,count);
    for(int i=0;i<count;i++){
        printf("%s\n",str_arr[i]);
    }
}