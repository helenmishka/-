#ifndef MEMORY_H
#define A_H

void free_matrix(int **a, int n);
int allocate_matrix(int ***a, int m, int n);
int resize_del_row(int ***a, int n);
int resize_add_row(int ***a, int n, int m);
int resize_del_column(int ***a, int n, int m);
int resize_add_column(int ***a, int n, int m);

#endif