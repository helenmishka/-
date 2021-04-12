#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#include "memory.h"
#include "codes_errors.h"
#include "utilities.h"

int read_str(char help[N])
{
    fgets(help, N, stdin);
    int len = strlen(help);
    if (len == 0)
        return INPUT_ERROR;
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

int read_date(experiments_t *exp, int ind)
{
    char help[N];
    read_str(help);
    
    int len = strlen(help);
    
    if (check(help) != OK)
        return INPUT_ERROR;
    
    int day, month, year = 0;
    
    if (tools_date(help, &day, &month, &year) == ERR)
        return INPUT_ERROR;
    
    if (day == 0 && month == 0 && year == 0)
        return END;
    
    if (input_date_check(day, month, year) != OK)
        return INPUT_ERROR;
    
    allocate_char_array(&exp[ind].date, len + 1);
    
    strcpy(exp[ind].date, help);
    
    return OK;
}

int read_surname(experiments_t *exp, int ind)
{
    char help[N];
    read_str(help);
    
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

int read_test(experiments_t *exp, int ind)
{
    if (fscanf(stdin, "%d", &exp[ind].quantity) != 1)
        return INPUT_ERROR;
    if (exp[ind].quantity < 1)
        return INPUT_ERROR;
    
    allocate_float_array(&exp[ind].test, exp[ind].quantity);
    
    for (int i = 0; i < exp[ind].quantity; i++)
    {
        if (fscanf(stdin, "%f", &exp[ind].test[i]) != 1)
        {
            free(exp[ind].test);
            return INPUT_ERROR;
        }
    }
    
    if (fgetc(stdin) != '\n')
    {
        free(exp[ind].test);
        return INPUT_ERROR;
    }
    return OK;
}

int read_array_exp(experiments_t **exp, int *size)
{
    int i = 0;
    int flag = 0;
    *size = i;
    allocate_struct(exp);
    while (flag == 0)
    {
        if (i > 0)
            resize_exp(exp, (*size + 1));
        int check;
        check = read_date(*exp, i);
        if (check == END)
        {
            resize_exp(exp, *size);
            flag = 1;
            return END;
        }
        if (check == INPUT_ERROR)
            return ERR;
        if (read_surname(*exp, i) != OK)
        {
            free((*exp)[i].date);
            return ERR;
        }
        if (read_test(*exp, i) != OK)
        {
            free((*exp)[i].date);
            free((*exp)[i].surname);
            return ERR;
        }
        i++;
        *size = i;
    }
    
    return OK;
}

int read_key(char key[N])
{
    int rc;
    
    rc = scanf("%s", key);
    if (rc != 1)
        return INPUT_ERROR;
    return OK;
}

void print_test(int quantity, float *test, FILE *f)
{
    for (int i = 0; i < quantity; i++)
        fprintf(f, "%8.6f ", test[i]);
}

void print_array_exp(experiments_t *exp, FILE *f, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%s", exp[i].date);
        fprintf(f, "%s", exp[i].surname);
        fprintf(f, "%d ", exp[i].quantity);
        print_test(exp[i].quantity, exp[i].test, f);
        fprintf(f, "\n");
    }
}