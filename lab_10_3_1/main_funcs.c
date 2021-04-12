#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#include "codes_errors.h"
#include "utilities.h"
#include "memory.h"

#include "main_funcs.h"

int check_date(experiments_t exp)
{
    int day, month, year;
    tools_date(exp.date, &day, &month, &year);
    if (year < CHECK_YEAR || (year == CHECK_YEAR && month < CHECK_MONTH) || (year == CHECK_YEAR && month == CHECK_MONTH && day == CHECK_DAY))
        return IS_DATE;
    return NOT_DATE;
}

int del_exp(experiments_t **exp, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        if (check_date((*exp)[i]) == IS_DATE)
        {
            free((*exp)[i].date);
            free((*exp)[i].surname);
            free((*exp)[i].test);
            for (int j = i; j < *size - 1; j++)
            {
                (*exp)[j] = (*exp)[j + 1];
            }
            *size = *size - 1;
            i--;
        }
    }
    if (*size == 0)
        return ERR;
    if (resize_exp(exp, *size) != OK)
        return MEMORY_ERROR;
    return OK;
}

float calc_average(float *arr, int size)
{
    float res;
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    res = sum / size;
    return res;
}

int change_test(float **test, int size)
{
    (*test)[0] = calc_average(*test, size);
    if (resize_float(test, 1) != OK)
        return ERR;
    return OK;
}
int change_arr_struct(experiments_t **exp, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (change_test(&(*exp)[i].test, (*exp)[i].quantity) != OK)
            return ERR;
        (*exp)[i].quantity = 1;
    }
    return OK;
}