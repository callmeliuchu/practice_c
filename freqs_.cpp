//
// Created by 刘楚 on 2020/11/21.
//


#include <cstdio>

int freqs(char *source, char *dest){
    int count = 0;
    while(*dest){
        char *j = source;
        char *i = dest;
        while(*i && *j && *i == *j){
            i++;
            j++;
        }
        if(!*j){
            count++;
        }
        dest++;
    }
    return count;
}

int main(int argc,char *args[]){
    char source[] = "aa";
    char dest[] = "aaaa";
    printf("%d\n",freqs(source,dest));
}