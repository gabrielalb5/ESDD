#include "t_date.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct date{
    int day, month, year;
};

int days_in_month(int month, int year);
bool is_leap_year(int year);
char* month_in_full(int month);

T_Date create_date(int day, int month, int year){
    T_Date ptr = NULL;

    if(year>=1000 && year<=3000){
        if(month>0 && month<=12){
            if(day>0 && day<= days_in_month(month,year)){
                ptr = malloc(sizeof(struct date));
                if(ptr!=NULL){
                    ptr->day = day;
                    ptr->month = month;
                    ptr->year = year;
                }
            }
        }
    }

    return ptr;
}

char* ptbr_date(T_Date date){
    char* str = malloc(sizeof(char)*12);
    if(str==NULL){
        return NULL;
    }

    sprintf(str,"%02d/%02d/%04d\n",date->day,date->month,date->year);
    return str;
}   

char* usa_date(T_Date date){
    char* str = malloc(sizeof(char)*12);
    if(str==NULL){
        return NULL;
    }

    sprintf(str,"%02d-%02d-%02d\n",date->year,date->month,date->day);
    return str;
}

char* complete_date(T_Date date, char* location) {
    char* string = malloc(sizeof(char) * 64);
    if (string != NULL) {
        sprintf(string, "%s, %02d de %s de %04d.", location, date->day, month_in_full(date->month), date->year);
    }

    return string;
}

void destroy_date(T_Date* date){
    free(*date);
    *date = NULL;
}

int days_in_month(int month, int year){
    int days = 0;
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9: 
        case 11:
            days = 30;
            break;
        case 2:
            days = is_leap_year(year)?29:28;
            break;
    }
    return days;
}

bool is_leap_year(int year){
    return (year%4==0 && year%100!=0) || year%400 == 0;
}

char* month_in_full(int month){
    char* str = malloc(sizeof(char)*16);
    if(str==NULL){
        return NULL;
    }
    switch(month){
        case 1: strcpy(str,"Janeiro");
                break;
        case 2: strcpy(str,"Fevereiro");
                break;
        case 3: strcpy(str,"Março");
                break;
        case 4: strcpy(str,"Abril");
                break;
        case 5: strcpy(str,"Maio");
                break;
        case 6: strcpy(str,"Junho");
                break;
        case 7: strcpy(str,"Julho");
                break;
        case 8: strcpy(str,"Agosto");
                break;
        case 9: strcpy(str,"Setembro");
                break;
        case 10: strcpy(str,"Outubro");
                break;
        case 11: strcpy(str,"Novembro");
                break;
        case 12: strcpy(str,"Dezembro");
                break;
    }
    return str;
}