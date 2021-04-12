#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str)
{
    int len = 0;
    while (*str++)
    {
        len++;
    }

    return len;
}

void write_buf(char **buf, size_t buf_size, char *str, int *length)
{
    if (*buf && buf_size)
    {   
        while ((*length < buf_size - 1) && *str)
        {
            **buf = *str;
            *buf += 1;
            *length += 1;
            str++;
        }
    }
    *length += my_strlen(str);
}

void calc(char **buf, size_t buf_size, unsigned long int num, int base, int *length)
{   
    unsigned long int copy_num = num;
    int len_num = 0;

    do 
    {
        len_num++;
        copy_num /= base;
    } while (copy_num);
    
    char char_num[len_num + 1];

    char_num[len_num--] = 0;
    do
    {
        char_num[len_num] = num % base + '0';
        
        if (char_num[len_num] > '9')
            char_num[len_num] += 39;

        if (base == 16 && char_num[len_num] >= 'a' && char_num[len_num] <= 'z')
            char_num[len_num] -= 32;

        num /= base;
        len_num--;
    } while (num);

    write_buf(buf, buf_size, char_num, length);
}

int my_snprintf(char *buf, size_t buf_size, char const *fmt, ...) 
{
    va_list arg;
    va_start(arg, fmt);
    
    int length = 0;

    while (*fmt) 
    {
        if (*fmt == '%') 
        {
            fmt++;
            switch (*fmt) 
            {
                case 's':
                    write_buf(&buf, buf_size, va_arg(arg, char *), &length);
                    break;
                case 'X':
                    calc(&buf, buf_size, (unsigned long int) va_arg(arg, unsigned int), 16, &length);
                    break;
                default:
                    {
                        fmt++;
                        calc(&buf, buf_size, va_arg(arg, unsigned long int), 8, &length);
                    }
                    break;
            }
        }
        else
        {
            if (buf)
                if (length < (buf_size - 1) && buf_size)
                    *buf++ = *fmt;
            length++;
        }
        fmt++;
    }

    if (buf)
        *buf = 0;

    va_end(arg);
    return length;
}