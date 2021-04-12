#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "main_funcs.h"
#include "codes_errors.h"
#include "utilities.h"
#include "memory.h"

int check_date(experiments_t exp)
{
    int day, month, year;
    tools_date(exp.date, &day, &month, &year);
    if (year < CHECK_YEAR || (year == CHECK_YEAR && month < CHECK_MONTH) || (year == CHECK_YEAR && month == CHECK_MONTH && day == CHECK_DAY))
        return IS_DATE;
    return NOT_DATE;
}

int del_exp(experiments_t **exp, int *size, int *ind)
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
			*ind--;
        }
    }
    if (*size == 0)
        return ERR;
    if (resize_exp(exp, *size) != OK)
        return MEMORY_ERROR;
    return OK;
}