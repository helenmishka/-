#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "input_output.h"
#include "main_funcs.h"
#include "list.h"
#include "codes_err.h"

void create_list(node **head_1, node **head_2, int *n, int *m, int *k, int *l)
{
    matrix a;
    a.row = 0;
    a.column = 0;
    a.item = 1;
    append_node(head_1, a);
    a.row = 1;
    a.column = 1;
    a.item = 3;
    append_node(head_1, a);
    *n = 2;
    *m = 2;
    
    a.row = 0;
    a.column = 0;
    a.item = 1;
    append_node(head_2, a);
    a.row = 1;
    a.column = 1;
    a.item = 2;
    append_node(head_2, a);
    a.row = 2;
    a.column = 2;
    a.item = 1;
    append_node(head_2, a);
    *k = 3;
    *l = 3;
}

void create_list_del(node **head)
{
    matrix a;

    a.row = 0;
    a.column = 0;
    a.item = 7;
    append_node(head, a);
    a.row = 0;
    a.column = 1;
    a.item = 8;
    append_node(head, a);
    a.row = 0;
    a.column = 2;
    a.item = 9;
    append_node(head, a);
    a.row = 1;
    a.column = 0;
    a.item = 4;
    append_node(head, a);
    a.row = 1;
    a.column = 1;
    a.item = 5;
    append_node(head, a);
    a.row = 1;
    a.column = 2;
    a.item = 6;
    append_node(head, a);
    a.row = 2;
    a.column = 0;
    a.item = 1;
    append_node(head, a);
    a.row = 2;
    a.column = 1;
    a.item = 2;
    append_node(head, a);
    a.row = 2;
    a.column = 2;
    a.item = 3;
    append_node(head, a);
}

int test_max_size()
{
    int n = 5;
    int m = 6;
    int k = 7;
    int l = 8;
    
    int n_expected = 7;
    int m_expected = 8;
    
    max_size(&n, &m, k, l);
    if (n != n_expected || m != m_expected)
    {
        printf("test_max_size FAILED");
        return FAILED;
    }
    return OK;
}

int test_add_matrix()
{
    node *head_1 = NULL;
    node *head_2 = NULL;
    node *head_3 = NULL;
    
    int n, m, k, l;
    
    int expected[100] = { 0, 0, 2, 1, 1, 5, 2, 2, 1 };
    create_list(&head_1, &head_2, &n, &m, &k, &l);
    add_matrix(head_1, head_2, &head_3, n, m, k, l);
    
    node *p;
    p = head_3;
    int i = 0;
    do 
    {
        if (expected[i] != p->data.row || expected[i + 1] != p->data.column || expected[i + 2] != p->data.item)
        {
            printf("test_add_matrix FAILED");
            return FAILED;
        }
        p = p->next;
        i += 3;
    }
    while (p != NULL);
    free_all(head_1);
    free_all(head_2);
    free_all(head_3);
    return OK;
}

int test_mult_matrix()
{
    node *head_1 = NULL;
    node *head_2 = NULL;
    node *head_3 = NULL;
    
    int n, m, k, l;
    
    int expected[100] = { 0, 0, 1, 1, 1, 6 };
    create_list(&head_1, &head_2, &n, &m, &k, &l);
    mult_matrix(head_1, head_2, &head_3, n, m, k, l);
    
    node *p;
    p = head_3;
    int i = 0;
    do 
    {
        if (expected[i] != p->data.row || expected[i + 1] != p->data.column || expected[i + 2] != p->data.item)
        {
            printf("test_mult_matrix FAILED");
            return FAILED;
        }
        p = p->next;
        i += 3;
    }
    while (p != NULL);
    free_all(head_1);
    free_all(head_2);
    free_all(head_3);
    return OK;
}

int test_delete_str()
{
    node *head = NULL;
    
    int expected[100] = { 0, 0, 4, 0, 1, 5, 0, 2, 6, 1, 0, 1, 1, 1, 2, 1, 2, 3 };

    create_list_del(&head);
    delete_str(&head);
    
    node *p;
    p = head;
    int i = 0;
    do 
    {
        if (expected[i] != p->data.row || expected[i + 1] != p->data.column || expected[i + 2] != p->data.item)
        {
            printf("test_delete_str FAILED");
            return FAILED;
        }
        p = p->next;
        i += 3;
    }
    while (p != NULL);
    free_all(head);
    return OK;
}

int main()
{
    int count = test_add_matrix() + test_max_size() + test_mult_matrix() + 
        test_delete_str();
    if (count != 0)
    {
        printf("%d FAILED", count);
        return FAILED;
    }
    printf("%d FAILED", count);
    return OK;
}