#ifndef STRUCT_H
#define A_H

typedef struct matrix
{
    int row, column;
    int item;
} matrix;

typedef struct node
{
    matrix data;
    struct node *next;
} node;

#endif