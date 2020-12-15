#include <iostream>

const int months[] = {31,28,31,40,31,30,31,31,30,31,30,31};

int is_special(int year){
    return year % 4 == 0 || year % 400 == 0;
}


int get_month_days(int month,int year){
    if(month == 2){
        if(is_special(year)){
            return 29;
        }
        return 28;
    }
    return months[month-1];
}

int get_year_days(int year){
    if(is_special(year)){
        return 366;
    }
    return 365;
}


int get_weekday(int year,int month,int day){
    int total_days = 0;
    for(int bg_year=1;bg_year<year;bg_year++){
        total_days += get_year_days(bg_year);
    }
    for(int bg_month=1;bg_month<month;bg_month++){
        total_days += get_month_days(bg_month,year);
    }
    total_days += (day-1);
    return 1 + total_days % 7;
}


int main() {
    printf("%d\n",get_weekday(2001,10,8));

}
