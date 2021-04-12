#include <stdio.h>
#include <stdlib.h>
#include "rk.h"

int main()
{
	int n;
	int **a;
	int **b;
	
	if (read_size(&n) != OK)
		return INPUT_ERROR;
	
	if (allocate_matrix(&a, n) != OK)
		return MEMORY_ERROR;
	
	if (read_matrix(&a, n) != OK)
		return INPUT_ERROR;
	
	if (allocate_new_matrix(&b, n) != OK)
		return MEMORY_ERROR;
	
	new_matrix(a, b, n);
	
	print_new_matrix(b, n);
	
	int count_row = n + n - 1;
	
	free_matrix(&b, count_row);
	free_matrix(&a, n);
	return OK;
}