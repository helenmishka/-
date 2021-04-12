#ifndef UTILITIES_H
#define A_H

#include "codes_errors.h"
int tools_date(char *date, int *day, int *month, int *year);
void createstruct(experiments_t *exp, int *size, int ind, char date[256], char surname[256], int quantity, ...);
#endif