#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#include "codes_errors.h"
#include "utilities.h"

int compare_surname(const void *item1, const void *item2)
{
    experiments_t *struct_1 = (experiments_t *)item1;
    experiments_t *struct_2 = (experiments_t *)item2;
    
    return strcmp(struct_1->surname, struct_2->surname);
}

int compare_date(const void *item1, const void *item2)
{
    experiments_t *struct_1 = (experiments_t *)item1;
    experiments_t *struct_2 = (experiments_t *)item2;
    
    char date_1[N];
    char date_2[N];
    
    strcpy(date_1, struct_1->date);
    strcpy(date_2, struct_2->date);
    
    int day_1, month_1, year_1;
    int day_2, month_2, year_2;
    
    tools_date(date_1, &day_1, &month_1, &year_1);
    tools_date(date_2, &day_2, &month_2, &year_2);
    
    if ((year_1 == year_2) && (month_1 == month_2))
        return (day_1 - day_2);
    if (year_1 == year_2)
        return (month_1 - month_2);
    
    return year_1 - year_2; 
}

int compare_test(const void *item1, const void *item2)
{
    experiments_t *struct_1 = (experiments_t *)item1;
    experiments_t *struct_2 = (experiments_t *)item2;
    
    float average_1 = struct_1->test[0];
    float average_2 = struct_2->test[0];
    
    return (average_1 - average_2);
}

int sort_by_key(experiments_t *exp, int size, char key[N])
{
    if (strcmp(key, "DATE") == 0)
        qsort(exp, (size_t)size, sizeof(experiments_t), compare_date);
    else if (strcmp(key, "TECHNICIAN") == 0)
        qsort(exp, (size_t)size, sizeof(experiments_t), compare_surname);
    else if (strcmp(key, "DATA") == 0)
        qsort(exp, (size_t)size, sizeof(experiments_t), compare_test);
    else
        return ERR;
    return OK;
}