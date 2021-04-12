#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "memory.h"

#include "codes_errors.h"
#include "utilities.h"
#include "sort.h"

int test_key_date()
{
    int size = 0;
    experiments_t exp[N];
    
    char date_1[N] = "21.01.2001";
    char surname_1[N] = "Katya";
    int quantity_1 = 1;
    
    char date_2[N] = "21.01.1997";
    char surname_2[N] = "Arina";
    int quantity_2 = 1;
    
    createstruct(exp, &size, 0, date_1, surname_1, quantity_1, 25.0);
    createstruct(exp, &size, 1, date_2, surname_2, quantity_2, 12.0);
   
    sort_by_key(exp, size, "DATE");
    
    char date_expected_1[N] = "21.01.1997";
    char date_expected_2[N] = "21.01.2001";
    
    int check = OK;
    if (strcmp(date_expected_1, exp[0].date) != 0 || strcmp(date_expected_2, exp[1].date) != 0)
    {
        printf("test_key_date FAILED");
        check = FAILED;
    }

    for (int i = 0; i < size; i++)
    {
        free(exp[i].date);
        free(exp[i].surname);
        free(exp[i].test);
    }
    
    return check;
}

int test_key_techinician()
{
    int size = 0;
    experiments_t exp[N];
    
    char date_1[N] = "21.01.2001";
    char surname_1[N] = "Katya";
    int quantity_1 = 1;
    
    char date_2[N] = "21.01.1997";
    char surname_2[N] = "Arina";
    int quantity_2 = 1;
    
    createstruct(exp, &size, 0, date_1, surname_1, quantity_1, 25.0);
    createstruct(exp, &size, 1, date_2, surname_2, quantity_2, 12.0);
    
    sort_by_key(exp, size, "TECHNICIAN");
    
    char surname_expected_1[N] = "Arina";
    char surname_expected_2[N] = "Katya";
    
    int check = OK;
    if (strcmp(surname_expected_1, exp[0].surname) != 0 || strcmp(surname_expected_2, exp[1].surname) != 0)
    {
        printf("test_key_techinician FAILED");
        check = FAILED;
    }

    for (int i = 0; i < size; i++)
    {
        free(exp[i].date);
        free(exp[i].surname);
        free(exp[i].test);
    }
    
    return check;
}

int test_key_data()
{
    int size = 0;
    experiments_t exp[N];
    
    char date_1[N] = "21.01.2001";
    char surname_1[N] = "Katya";
    int quantity_1 = 1;
    
    char date_2[N] = "21.01.1997";
    char surname_2[N] = "Arina";
    int quantity_2 = 1;
    
    createstruct(exp, &size, 0, date_1, surname_1, quantity_1, 25.0);
    createstruct(exp, &size, 1, date_2, surname_2, quantity_2, 12.0);
    
    sort_by_key(exp, size, "DATA");
    
    float expected_data_1 = 12;
    float expected_data_2 = 25;
    
    int check = OK;
    if (exp[0].test[0] != expected_data_1 || exp[1].test[0] != expected_data_2)
    {
        printf("test_key_data FAILED");
        check = FAILED;
    }

    for (int i = 0; i < size; i++)
    {
        free(exp[i].date);
        free(exp[i].surname);
        free(exp[i].test);
    }
    
    return check;
}

int test_wrong_key()
{
    int size = 0;
    experiments_t exp[N];
    
    char date_1[N] = "21.01.2001";
    char surname_1[N] = "Katya";
    int quantity_1 = 1;
    
    char date_2[N] = "21.01.1997";
    char surname_2[N] = "Arina";
    int quantity_2 = 1;
    
    createstruct(exp, &size, 0, date_1, surname_1, quantity_1, 25.0);
    createstruct(exp, &size, 1, date_2, surname_2, quantity_2, 12.0);
    
    int actuall_err = sort_by_key(exp, size, "DAT");
    int expected_err = ERR;
    
    int check = OK;
    
    if (actuall_err != expected_err)
        check = FAILED;

    for (int i = 0; i < size; i++)
    {
        free(exp[i].date);
        free(exp[i].surname);
        free(exp[i].test);
    }
    
    return check;
}