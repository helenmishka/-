#ifndef MEMORY_H
#define A_H

int allocate_char_array(char **a, int n);
int resize_char(char **a, int len);
int resize_float(float **a, int n);
int resize_struct(experiments_t exp_ch, experiments_t exp);
void free_struct(experiments_t *exp, int size);
int allocate_float_array(float **a, int n);
int allocate_struct(experiments_t **exp);
int resize_exp(experiments_t **exp, int size);
void free_struct_field(experiments_t *exp, int size);

#endif