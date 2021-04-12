#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "memory.h"
#include "utilities.h"

#include "codes_errors.h"
#include "input_output.h"

int test_io_check_big_month()
{
    int check_actuall = input_date_check(1, 13, 2001);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}

int test_tools_date_ok()
{
    char date[30] = "21.01.2001";
    
    int day_actuall;
    int month_actuall;
    int year_actuall;
    
    int check_expected = OK;
    
    int day_expected = 21;
    int month_expected = 1;
    int year_expected = 2001;
    
    int check_actuall = tools_date(date, &day_actuall, &month_actuall, &year_actuall);
    
    if (check_actuall != check_expected || day_actuall != day_expected || 
        month_actuall != month_expected || year_expected != year_actuall)
        return FAILED;
    return OK;
}

int test_tools_date_err()
{
    char date[30] = "21.01.";
    
    int day_actuall;
    int month_actuall;
    int year_actuall;
    
    int check_expected = ERR;
    
    int check_actuall = tools_date(date, &day_actuall, &month_actuall, &year_actuall);
    
    if (check_actuall != check_expected)
        return FAILED;
    return OK;
}

int test_io_check_neg_year()
{
    int check_actuall = input_date_check(1, 3, -5);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}

int test_io_check_31_day()
{   
    int check_actuall = input_date_check(31, 4, 2001);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}

int test_io_check_big_day()
{
    int check_actuall = input_date_check(32, 5, 2001);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}

int test_io_check_29feb_day()
{
    int check_actuall = input_date_check(29, 2, 2018);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}

int test_io_check_30feb_day()
{
    int check_actuall = input_date_check(30, 2, 2018);
    
    if (check_actuall != INPUT_ERROR)
        return FAILED;
    return OK;
}