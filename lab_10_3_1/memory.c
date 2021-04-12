#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#include "codes_errors.h"


int allocate_char_array(char **a, int n)
{
    *a = calloc(n, sizeof(char));

    if (!(*a))
    {
        free(*a);
        return MEMORY_ERROR;
    }
    
    return OK;
}

int resize_char(char **a, int len)
{
    char *new_a;
    new_a = realloc(*a, len * sizeof(char));
    
    if (new_a)
    {
        *a = new_a;
        new_a = NULL;
    }
    else
        return MEMORY_ERROR;

    return OK;
}

int resize_float(float **a, int n)
{
    float *new_a;
    new_a = realloc(*a, n * sizeof(float));
    
    if (new_a)
    {
        *a = new_a;
        new_a = NULL;
    }
    else
        return MEMORY_ERROR;

    return OK;
}

int resize_struct(experiments_t exp_ch, experiments_t exp)
{
    if (resize_char(&exp_ch.date, strlen(exp.date)) != OK)
        return MEMORY_ERROR;

    if (resize_char(&exp_ch.surname, strlen(exp.surname)) != OK)
        return MEMORY_ERROR; 

    if (resize_float(&exp_ch.test, exp.quantity) != OK)
        return MEMORY_ERROR;

    return OK;
}

void free_struct_field(experiments_t *exp, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(exp[i].date);
        free(exp[i].surname);
        free(exp[i].test);
    }
}

void free_struct(experiments_t *exp, int size)
{
    free_struct_field(exp, size);
    free(exp);
}

int allocate_float_array(float **a, int n)
{
    *a = calloc(n, sizeof(float));

    if (!(*a))
    {
        free(*a);
        return MEMORY_ERROR;
    }
    
    return OK;
}

int allocate_struct(experiments_t **exp)
{
    *exp = calloc(1, sizeof(experiments_t));

    if (!(*exp))
    {
        free(*exp);
        return MEMORY_ERROR;
    }
    
    return OK;
}

int resize_exp(experiments_t **exp, int size)
{
    experiments_t *new_exp;
    new_exp = realloc(*exp, size * sizeof(experiments_t));
    
    if (new_exp)
    {
        *exp = new_exp;
        new_exp = NULL;
    }
    else
        return MEMORY_ERROR;

    return OK;
}