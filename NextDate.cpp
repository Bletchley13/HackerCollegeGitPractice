#include <stdlib.h>
#include "NextDate.h"

int getYearType(Date *a)
{
    printf("Hi, I don't know how to implement\n");
}


int getMonthType(Date *a)
{
	int month = a->month;
	if(month < 1 || month > 12) return INVALID;
	if(month < 8 && month  == 2) return FEBUARY;
	if( (month < 8 && month % 2 == 0) || (month >= 8 && month % 2 == 1) ) 
		return SMALLMONTH;
	else return BIGMONTH; 
}

Date *NextDate(Date *argv)
{
	Date *ret = (Date *)malloc(sizeof(Date));
	int yearType = getYearType(argv);
	int monthType = getMonthType(argv);
	int maxDay;
	int maxMonth = 12;

	if(monthType == BIGMONTH) maxDay = BIGMONTHMAX;
	else if(monthType == SMALLMONTH) maxDay = SMALLMONTHMAX;
	else if(yearType==LEAPYEAR) maxDay = LEAPFEBUARYMAX;
	else maxDay = NORMALFEBUARYMAX;

	ret->year = argv->year;
	ret->month = argv->month;
	ret->day = argv->day;


	if(ret->day > maxDay || ret->day < 1|| yearType==INVALID || monthType == INVALID)
        {
                free(ret);
                return NULL;
        }


	ret->day += 1;
	int carry = 0;
	if(ret->day > maxDay ) 
	{
		ret->day = 1;
		carry = 1;
	} 
	
	ret->month += carry;
	if(ret->month > maxMonth)
	{
		ret->month = 1;
		ret->year += 1;
	}

	return ret;
}  

Date *NewDateInstance(int year, int month, int day)
{
	Date *ret = (Date *)malloc(sizeof(Date));
	ret->year = year;
        ret->month = month;
        ret->day = day;
	return ret;
}

void ShowDate(Date* date)
{
	printf("%d-%d-%d\n", date->year, date->month, date->day);
}

bool checkDate(Date* a, int true_year, int true_mouth, int true_day)
{
        if(a->year == true_year && a->month == true_mouth && a->day == true_day){
                return true;
        }
        return false;
}

