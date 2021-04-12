#ifndef INPUT_OUTPUT_H
#define A_H

int read_array_exp(experiments_t **exp, int *size);
int input_date_check(int day, int month, int year);
void print_test(int quantity, float *test, FILE *f);
void print_array_exp(experiments_t *exp, FILE *f, int size);
int read_key(char key[N]);

#endif
