#ifndef DARRAY_H
#define A_H
#define OK 0
#define INPUT_ERROR -1
#define ERROR -2
int read_array(double **end, double **start);
void print_array(double *start, double *end);
double find_m1(double *start, double *end);
double find_m2(double *start, double *end);
void del_element(double **start, double **end, double number);
void clear(double **start, int n);
int del(double **start, double **end, double m_1);
int scanf_pos(int *pos);
void add(double **start, int len, int n);
int add_m2(double **start, double **end, double m_2, int pos);
#endif