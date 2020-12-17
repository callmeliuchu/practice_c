//
// Created by liuchu on 2020/12/17.
//

#include <stdlib.h>
#include <stdio.h>

int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int is_special_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }
    return 0;
}


int get_month_day(int year,int month){
    if(month == 2){
        if(is_special_year(year)){
            return 29;
        }
        return 28;
    }
    return month_days[month-1];
}

int get_year_days(int year){
    if(is_special_year(year)){
        return 366;
    }
    return 365;
}


int main(int argc,char *args[]){
    int year = atoi(args[1]);
    int month = atoi(args[2]);
    int day = atoi(args[3]);
    int total = 0;
    for(int i=1;i<year;i++){
        total += get_year_days(i);
    }
    for(int i=1;i<month;i++){
        total += get_month_day(year,i);
    }
    total += day;
    printf("%d\n",total%7);
}