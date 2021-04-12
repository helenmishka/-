#include <stdio.h>
#include "dmatrix.h"
#include "memory.h"
#include "input_output.h"
#include <stdlib.h>
#include <math.h>
#include "codes_errors.h"

int main()
{
	setbuf(stdout, NULL);
	
	int m, n;
	int **a;
	
	int q, p;
	int **b;
	
	if (scanf_size_matrix(&n, &m) != OK)
		return INPUT_ERROR;

	if (read_matrix(&a, m, n) != OK)
		return INPUT_ERROR;
	
	if (scanf_size_matrix(&p, &q) != OK)
	{
		free_matrix(a, n);
		return INPUT_ERROR;
	}
	
	if (read_matrix(&b, q, p) != OK)
	{
		free_matrix(a, n);
		return INPUT_ERROR;
	}
	
	if (change_matrix_del(&a, &m, &n) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	if (change_matrix_del(&b, &q, &p) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	if (change_matrix_add(&a, &b, &m, &n, &q, &p) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	int r, y;
	
	if (scanf_pow(&r, &y) != OK)
	{
		free_matrix(a, n);
		free_matrix(b, p);
		return INPUT_ERROR;
	}
	
	if (pow_matrix(&a, n, m, r) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	if (pow_matrix(&b, n, m, y) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	if (multiplication_matrix(&a, b, n, m) != OK)
	{
		free_matrix(b, p);
		free_matrix(a, n);
		return ERROR;
	}
	
	print_matrix(a, m, n);
	
	free_matrix(b, p);

	free_matrix(a, n);
	
	return OK;
}
