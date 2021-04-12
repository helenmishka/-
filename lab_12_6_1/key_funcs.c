#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "input_output.h"
#include "main_funcs.h"
#include "list.h"
#include "codes_err.h"

int add()
{
    node *head_1 = NULL;
    node *head_2 = NULL;
    node *head_3 = NULL;
    
    int n, m;
    int k, l;
    
    if (read_matrix(&n, &m, &head_1) != OK)
    {
        free_all(head_1);
        return ERR;
    }
    if (read_matrix(&k, &l, &head_2) != OK)
    {
        free_all(head_1);
        free_all(head_2);
        return ERR;
    }
    
    if (head_1 == NULL && head_2 == NULL)
        return OK;
    else if (head_1 == NULL)
        list_print(head_2);
    else if (head_2 == NULL)
        list_print(head_1);
    else
    {
        add_matrix(head_1, head_2, &head_3, n, m, k, l);
        list_print(head_3);
    }
    free_all(head_1);
    free_all(head_2);
    free_all(head_3);
    return OK;
}

int mul()
{
    node *head_1 = NULL;
    node *head_2 = NULL;
    node *head_3 = NULL;
    
    int n, m;
    int k, l;
    
    if (read_matrix(&n, &m, &head_1) != OK)
    {
        free_all(head_1);
        return ERR;
    }
    if (read_matrix(&k, &l, &head_2) != OK)
    {
        free_all(head_1);
        free_all(head_2);
        return ERR;
    }
    
    if (head_1 == NULL || head_2 == NULL)
        return OK;   
    mult_matrix(head_1, head_2, &head_3, n, m, k, l);
    
    list_print(head_3); 
    
    free_all(head_1);
    free_all(head_2);
    free_all(head_3);
    return OK;
}

int lin()
{
    node *head = NULL;
    
    int n, m;
    
    if (read_matrix(&n, &m, &head) != OK)
    {
        free_all(head);
        return ERR;
    }
    
    if (head == NULL)
        return OK;
    delete_str(&head);
    
    list_print(head);
    
    free_all(head);
    return OK;
}

int out()
{
    node *head = NULL;
    
    int n, m;
    
    if (read_matrix(&n, &m, &head) != OK)
    {
        free_all(head);
        return ERR;
    }
    
    if (head == NULL)
        return OK;
    
    list_print(head);
    
    free_all(head);
    
    return OK;
}