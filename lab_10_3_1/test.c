#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codes_errors.h"
#include "test_sort.h"
#include "test_main_funcs.h"
#include "test_check.h"

int main()
{
    int check = test_key_date() + test_key_techinician() + test_key_data() +
        test_del_exp() + test_change_arr_struct() + test_io_check_big_month() +
        test_io_check_neg_year() + test_io_check_31_day() +
        test_io_check_big_day() + test_io_check_29feb_day() +
        test_io_check_30feb_day() + test_tools_date_ok() + test_tools_date_err() + 
        test_wrong_key();
          
    printf("%d FAILED", check);
    
    if (check != OK)
        return FAILED;
    
    return OK;
}