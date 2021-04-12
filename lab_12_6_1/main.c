#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "key_funcs.h"
#include "codes_err.h"

int main()
{
    char key[100]; 
    scanf("%s", key);
    if (strcmp(key, "out") == 0)
    {
        if (out() != OK)
            return ERR;
        return OK;
    }
    if (strcmp(key, "mul") == 0)
    {
        if (mul() != OK)
            return ERR;
        return OK;
    }
    if (strcmp(key, "add") == 0)
    {
        if (add() != OK)
            return ERR;
        return OK;
    }
    if (strcmp(key, "lin") == 0)
    {
        if (lin() != OK)
            return ERR;
        return OK;
    }
    else
        return ERR;
    return OK;
}