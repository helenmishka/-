#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#include "codes_errors.h"
#include "input_output.h"
#include "memory.h"
#include "main_funcs.h"
#include "sort.h"

int main()
{
    setbuf(stdout, NULL);

    experiments_t *exp;
    
    int size = 0;
    int rc;
    rc = read_array_exp(&exp, &size);
    if (rc == ERR)
    {
        free_struct(exp, size);
        return ERR;
    }
    if (size == 0)
        return ERR;
    if (del_exp(&exp, &size) != OK)
    {
        free_struct(exp, size);
        return ERR;
    }
    if (size == 0)
        return ERR;
    if (change_arr_struct(&exp, size) != OK)
    {
        free_struct(exp, size);
        return ERR;
    }
    
    char key[N];
    if (read_key(key) != OK)
        return ERR;
    
    if (sort_by_key(exp, size, key) != OK)
    {
        free_struct(exp, size);
        return ERR;
    }
    
    FILE *f = fopen("results.txt", "w");
    print_array_exp(exp, f, size);
    fclose(f);
    
    free_struct(exp, size);
    
    return OK;
}
