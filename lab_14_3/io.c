#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

#include "struct.h"
#include "codes_errors.h"
#include "memory.h"

int tools_date(char date[N], int *day, int *month, int *year) 
{
    if (sscanf(date, "%d.%d.%d", day, month, year) != 3)
        return ERR;
    
    return OK;
}

int check(char help[N])
{
    int len = strlen(help);
    if (len == 0)
        return INPUT_ERROR;
    int count_point = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (help[i] == '.')
            count_point++;
    }
    
    for (int i = 0; i < len; i++)
    {
        if ((help[i] < '0' || help[i] > '9') && help[i] != '.' && help[i] != '\n')
            return INPUT_ERROR;
    }
    
    if (count_point != 2)
        return INPUT_ERROR;
    
    int i = 0;
    int check = 1;
    while (i < len)
    {
        int count = 0;
        while (help[i] != '.' && i < len && help[i] != '\n')
        {
            count++;
            i++;
        }
        if (check == 1 && count != 2)
            return INPUT_ERROR;
        if (check == 2 && count != 2)
            return INPUT_ERROR;
        if (check == 3 && count != 4)
            return INPUT_ERROR;
        check++;
        i++;
    }
    return OK;
}

int input_date_check(int day, int month, int year)
{
    if (day < 1 || month < 1 || month > 12 || year < 1 || year > 9999)
        return INPUT_ERROR;
        
    if ((month == 9 || month == 4 || month == 6 || month == 11) && day > 30)
        return INPUT_ERROR;
    else if (day > 31)
        return INPUT_ERROR;
    
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
    {
        if (month == 2 && day > 28)
            return INPUT_ERROR;
    }
    else
    {
        if (month == 2 && day > 29)
            return INPUT_ERROR;
    }
    return OK;
}

int read_date(experiments_t *exp, int ind, uiEntry *date)
{
    char help[N];
	strcpy(help, uiEntryText(date));
    
    int len = strlen(help);
    
    if (check(help) != OK)
        return INPUT_ERROR;
    
    int day, month, year = 0;
    
    if (tools_date(help, &day, &month, &year) == ERR)
        return INPUT_ERROR;
    
    if (input_date_check(day, month, year) != OK)
        return INPUT_ERROR;
    
    allocate_char_array(&exp[ind].date, len + 1);
    
    strcpy(exp[ind].date, help);
    
    return OK;
}

int read_surname(experiments_t *exp, int ind, uiEntry *surname)
{
    char help[N];
    strcpy(help, uiEntryText(surname));
    
    int len = strlen(help);
    
    if (len == 0 || (len == 1 && help[len - 1] == '\n'))
        return INPUT_ERROR;
    
    for (int i = 0; i < len; i++)
    {
        if (((help[i] >= 'a') && (help[i] <= 'z')) || ((help[i] >= 'A') && (help[i] <= 'Z')) || help[i] == '\n')
            continue;
        else
            return INPUT_ERROR;
    }
    
    allocate_char_array(&exp[ind].surname, len + 1);
    
    strcpy(exp[ind].surname, help);
    
    return OK;
}

int read_test(experiments_t *exp, int ind, uiEntry *test)
{
    char help[N];
    strcpy(help, uiEntryText(test));
    
    int len = strlen(help);
    
    if (len == 0 || (len == 1 && help[len - 1] == '\n'))
        return INPUT_ERROR;
    
    for (int i = 0; i < len; i++)
    {
        if (((help[i] >= '0') && (help[i] <= '9')) || (help[i] == '.') || help[i] == '\n')
            continue;
        else
            return INPUT_ERROR;
    }
    
    allocate_char_array(&exp[ind].test, len + 1);
    
    strcpy(exp[ind].test, help);
    
    return OK;
}