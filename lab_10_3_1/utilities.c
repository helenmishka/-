#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "codes_errors.h"
#include "codes_errors.h"
#include "struct.h"
#include "memory.h"

int tools_date(char date[N], int *day, int *month, int *year) 
{
    if (sscanf(date, "%d.%d.%d", day, month, year) != 3)
        return ERR;
    
    return OK;
}

void createstruct(experiments_t *exp, int *size, int ind, char date[N], char surname[N], int quantity, ...)
{ 
	
    allocate_char_array(&exp[ind].date, strlen(date) + 1);
    
    strcpy(exp[ind].date, date);
    
    allocate_char_array(&exp[ind].surname, strlen(surname) + 1);
    
    strcpy(exp[ind].surname, surname);
    
    exp[ind].quantity = quantity;
    
    allocate_float_array(&exp[ind].test, quantity);
    int i = 0;
    va_list arg;
    va_start(arg, quantity);
    while (i != quantity)
    {	
        exp[ind].test[i] = va_arg(arg, double);
        i++;
    }
    
    va_end(arg);
    
    *size += 1;
}