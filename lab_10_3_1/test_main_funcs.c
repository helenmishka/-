#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "memory.h"
#include "utilities.h"
#include "codes_errors.h"
#include "main_funcs.h"

int test_del_exp()
{
    int size = 0;
    experiments_t *exp;
    
    allocate_struct(&exp);
    resize_exp(&exp, 2);
    
    char date_1[256] = "21.01.1991";
    char surname_1[256] = "Katya";
    
    char date_2[256] = "21.01.1990";
    char surname_2[256] = "Arina";
    
    createstruct(exp, &size, 0, date_1, surname_1, 3, 1.0, 3.0, 2.0);
    createstruct(exp, &size, 1, date_2, surname_2, 3, 1.0, 3.0, 2.0);
	
    del_exp(&exp, &size);
    
    if (size != 0)
    {
        free_struct(exp, size);
        printf("test_del_exp FAILED");
        return FAILED;
    }
    free_struct(exp, size);
    return OK;
}

int test_change_arr_struct()
{
    int size = 0;
    experiments_t *exp;
    
    allocate_struct(&exp);
    resize_exp(&exp, 2);
    
    char date_1[256] = "21.01.1991";
    char surname_1[256] = "Katya";
    
    char date_2[256] = "21.01.1990";
    char surname_2[256] = "Arina";
    
    createstruct(exp, &size, 0, date_1, surname_1, 3, 1.0, 3.0, 2.0);
    createstruct(exp, &size, 1, date_2, surname_2, 3, 1.0, 3.0, 2.0);
    
    change_arr_struct(&exp, size);
    
    if (exp[0].test[0] != 2 || exp[1].test[0] != 2)
    {
        free_struct(exp, size);
        printf("test_change_arr_struct FAILED");
        return FAILED;
    }
    free_struct(exp, size);
    return OK;
}