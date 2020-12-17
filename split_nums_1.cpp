//
// Created by liuchu on 2020/12/17.
//
#include <stdio.h>

int is_num(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}


int main(){
    char s[]= "82174jhsadjksbjk7173kand8213nwd823jcjs824j4838n12";
    char *p = s;
    while(*p){
        while(*p && !is_num(*p)){
            p++;
        }
        int num = 0;
        while(*p && is_num(*p)){
            num = num*10 + (*p - '0');
            p++;
        }
        printf("%d\n",num);
    }
}