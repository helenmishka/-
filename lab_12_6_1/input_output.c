#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "list.h"
#include "codes_err.h"

int read_matrix(int *n, int *m, node **head)
{
    int element;
    matrix a;
    char sym;
    
    if (scanf("%d %d", n, m) != 2)
        return ERR;
    if (*n < 1 || *m < 1)
        return ERR;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            if (scanf("%d%c", &element, &sym) != 2)
                return ERR;
            if (sym != '\n' && sym != ' ')
                return ERR;
            if (element != 0)
            {
                a.row = i;
                a.column = j;
                a.item = element;
                append_node(head, a);
            }
        }
    }
    return OK;
}