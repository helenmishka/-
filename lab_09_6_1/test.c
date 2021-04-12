#include <stdio.h>
#include <stdlib.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"
#include "change_matrix_add_test.h"
#include "change_matrix_del_test.h"
#include "multiplication_matrix_test.h"
#include "pow_matrix_test.h"

int main()
{
	int result = more_rows_than_columns() +
		more_columns_than_rows() +
		square_matrix() + 
		matrix_b_larger_matrix_a() + 
		matrix_a_larger_matrix_b() + 
		test_min_element_in_row() + 
		matrix_sizes_are_equal() + 
		return_square_of_matrix() + 
		return_matrix() + 
		return_new_matrix() + 
		return_identity_matrix() + 
		return_new_mult_matrix();
		
	if (result != OK)
	{
		printf("FAILED %d", result);
		return ERROR;
	}
	
	printf("OK");
	return OK;
}