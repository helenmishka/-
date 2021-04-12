#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "list.h"

void change_ind(node **head, int ind)
{
    node *p;
    p = *head;
    do 
    {
        if (p->data.row > ind)
        {
            p->data.row = p->data.row - 1;
        }
        p = p->next;
    } 
    while (p != NULL);
}

void delete_str(node **head)
{
    node *p;
    p = *head;
    int max = p->data.item;
    int ind_max = p->data.row;
    do 
    {
        if (p->data.item > max)
        {
            max = p->data.item;
            ind_max = p->data.row;
        }
        p = p->next;
    } 
    while (p != NULL);
    delete_element(head, ind_max);
    change_ind(head, ind_max);
}

int search_elem(node *head, int i, int j)
{
    node *p = head;
    do 
    {
        if (p->data.row == i && p->data.column == j)
            return p->data.item;
        p = p->next;
    } 
    while (p != NULL);
    return 0;
}

void max_size(int *n, int *m, int k, int l)
{
    if (*n < k)
        *n = k;
    if (*m < l)
        *m = l;
}

void add_matrix(node *head_1, node *head_2, node **head_3, int n, int m, int k, int l)
{
    matrix a;
    
    int temp_1;
    int temp_2;
    int res;
    
    *head_3 = NULL;
    
    max_size(&n, &m, k, l);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp_1 = search_elem(head_1, i, j);
            temp_2 = search_elem(head_2, i, j);
            
            res = temp_1 + temp_2;
            if (res != 0)
            {
                a.row = i;
                a.column = j;
                a.item = res;
                append_node(head_3, a);
            }
        }
    }
}    
void mult_matrix(node *head_1, node *head_2, node **head_3, int n, int m, int k, int l)
{
    matrix a;
    
    int temp_1;
    int temp_2;
    int res;
    
    *head_3 = NULL;
    
    max_size(&n, &m, k, l);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = 0;
            for (int k = 0; k < n; k++)
            {
                temp_1 = search_elem(head_1, i, k);
                temp_2 = search_elem(head_2, k, j);
                res += temp_1 * temp_2;
            }
            if (res != 0)
            {
                a.row = i;
                a.column = j;
                a.item = res;
                append_node(head_3, a);
            }
        }
    } 
}