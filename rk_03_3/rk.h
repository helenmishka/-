#ifndef RK_H
#define A_H

#define INPUT_ERROR 1
#define MEMORY_ERROR 2
#define OK 0

void free_matrix(int ***a, int n);
int read_size(int *n);

int allocate_matrix(int ***a, int n);
int read_matrix(int ***a, int n);
int allocate_new_matrix(int ***a, int n);
void new_matrix(int **a, int **b, int n);
void print_new_matrix(int **a, int n);

#endif