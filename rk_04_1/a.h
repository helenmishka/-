#ifndef A_H
#define A_H

#define N 255

int input_name(town new[N], int *size);
void print(town a);
void sort(town a[N], int size);
void input_list(node **head, town data);
void input(town data[N], int size, node **head);
void print_list(node *head);
void free_list(node *head);
#endif