#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab11.h"


int test_mysnprintf_s()
{
    char actuall[200];
    char expected[200];
    my_snprintf(actuall, 5, "%s", "lena");
    snprintf(expected, 5, "%s", "lena");
    if (strcmp(actuall, expected) != 0)
        return FAILED;
    return 0;
}

int test_mysnprintf_s_text()
{
    char actuall[200];
    char expected[200];
    my_snprintf(actuall, 10, "Lena %s", "lena");
    snprintf(expected, 10, "Lena %s", "lena");
    if (strcmp(actuall, expected) != 0)
        return FAILED;
    return 0;
}

int test_mysnprintf_x()
{
    char actuall[200];
    char expected[200];
    my_snprintf(actuall, 5, "%X", 1245);
    snprintf(expected, 5, "%X", 1245);
    if (strcmp(actuall, expected) != 0)
        return FAILED;
    return 0;
}

int test_mysnprintf_lo()
{
    char actuall[200];
    char expected[200];
    my_snprintf(actuall, 5, "%lo", 10);
    snprintf(expected, 5, "%o", 10);
    if (strcmp(actuall, expected) != 0)
        return FAILED;
    return 0;
}

int main()
{
    int check = test_mysnprintf_s() + test_mysnprintf_lo() + test_mysnprintf_lo() + 
        test_mysnprintf_s_text() + test_mysnprintf_x();
    printf("FAILED %d", check);
    if (check != 0)
        return FAILED;
    return 0;
}