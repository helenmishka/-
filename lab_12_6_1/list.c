#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void append_node(node **head, matrix new) 
{
    node *current = *head;
    node *new_node;
   
    new_node = malloc(sizeof(node));
    new_node->data = new;
    new_node->next = NULL;

    if (current == NULL) 
    {
        *head = new_node;
    }
    else 
    {
        while (current->next != NULL) 
            current = current->next;
        current->next = new_node;
    }
}

void delete_element(node **head, int ind)
{
    node *current, *previous;
    
    current = *head;
    previous = *head;
    while (current != NULL) 
    {
        if (current->data.row == ind) 
        {
            if (current == *head) 
            {
                current = current->next;
                free(*head);
                *head = current;
                previous = *head;
            }
            else 
            {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

void print_elem(matrix element)
{
    printf("%d %d %d ", element.row, element.column, element.item);
}

void list_print(node *head)
{
    node *p;
    p = head;
    do 
    {
        print_elem(p->data);
        p = p->next;
    }
    while (p != NULL);
}

void free_all(node *head)
{
    node *p;
    for (; head; head = p)
    {
        p = head->next;
        free(head);
    }
}