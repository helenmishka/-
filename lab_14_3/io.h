#ifndef IO_H
#define A_H

int tools_date(char date[N], int *day, int *month, int *year);

int check(char help[N]);

int input_date_check(int day, int month, int year);

int read_date(experiments_t *exp, int ind, uiEntry *date);

int read_surname(experiments_t *exp, int ind, uiEntry *surname);

int read_test(experiments_t *exp, int ind, uiEntry *test);
#endif
