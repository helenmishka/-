#ifndef LAB11_H
#define A_H

#define FAILED 1

int my_strlen(char *str);
void write_buf(char **buf, size_t buf_size, char *str, int *length);
void calc(char **buf, size_t buf_size, unsigned long int num, int base, int *length);
int my_snprintf(char *buf, size_t buf_size, char const *fmt, ...);

#endif