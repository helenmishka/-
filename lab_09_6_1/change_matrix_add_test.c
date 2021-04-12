#include <stdio.h>
#include <stdlib.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"

int matrix_a_larger_matrix_b()
{
	int **a;
	int check = 0;
	allocate_matrix(&a, 3, 3);
	
	int n = 3;
	int m = 3;
	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	a[2][0] = 7;
	a[2][1] = 8;
	a[2][2] = 9;
	
	int **b;
	allocate_matrix(&b, 2, 2);
	
	int p = 2;
	int q = 2;
	b[0][0] = 1;
	b[0][1] = 1;
	b[1][0] = 1;
	b[1][1] = 1;
	
	int **b_expected;
	allocate_matrix(&b_expected, 3, 3);
	
	b_expected[0][0] = 1;
	b_expected[0][1] = 1;
	b_expected[0][2] = 1;
	
	b_expected[1][0] = 1;
	b_expected[1][1] = 1;
	b_expected[1][2] = 1;
	
	b_expected[2][0] = 1;
	b_expected[2][1] = 1;
	b_expected[2][2] = 1;
	
	change_matrix_add(&a, &b, &m, &n, &q, &p);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] != b_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(b_expected, 3);
	free_matrix(b, p);
	
	if (check != 0)
		return FAIL;
	return OK;
}

int matrix_b_larger_matrix_a()
{
	int **b;
	int check = 0;
	allocate_matrix(&b, 3, 3);
	
	int p = 3;
	int q = 3;
	b[0][0] = 1;
	b[0][1] = 2;
	b[0][2] = 3;
	b[1][0] = 4;
	b[1][1] = 5;
	b[1][2] = 6;
	b[2][0] = 7;
	b[2][1] = 8;
	b[2][2] = 9;
	
	int **a;
	allocate_matrix(&a, 2, 2);
	
	int m = 2;
	int n = 2;
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	
	int **a_expected;
	allocate_matrix(&a_expected, 3, 3);
	
	a_expected[0][0] = 1;
	a_expected[0][1] = 1;
	a_expected[0][2] = 1;
	
	a_expected[1][0] = 1;
	a_expected[1][1] = 1;
	a_expected[1][2] = 1;
	
	a_expected[2][0] = 1;
	a_expected[2][1] = 1;
	a_expected[2][2] = 1;
	
	change_matrix_add(&a, &b, &m, &n, &q, &p);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != a_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 3);
	free_matrix(b, p);
	
	if (check != 0)
		return FAIL;
	return OK;
}

int matrix_sizes_are_equal()
{
	int **b;
	int check = 0;
	allocate_matrix(&b, 2, 2);
	
	int p = 2;
	int q = 2;
	
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][0] = 4;
	b[1][1] = 5;
	
	int **a;
	allocate_matrix(&a, 2, 2);
	
	int m = 2;
	int n = 2;
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	
	int **a_expected;
	allocate_matrix(&a_expected, 2, 2);
	
	a_expected[0][0] = 1;
	a_expected[0][1] = 1;
	a_expected[1][0] = 1;
	a_expected[1][1] = 1;
	
	int **b_expected;
	allocate_matrix(&b_expected, 2, 2);
	
	b_expected[0][0] = 1;
	b_expected[0][1] = 2;
	b_expected[1][0] = 4;
	b_expected[1][1] = 5;

	change_matrix_add(&a, &b, &m, &n, &q, &p);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] != a_expected[i][j] || b[i][j] != b_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 2);
	free_matrix(b_expected, 2);
	free_matrix(b, p);
	
	if (check != 0)
		return FAIL;
	return OK;
}

int test_min_element_in_row()
{
	int **b;
	int check = 0;
	allocate_matrix(&b, 2, 2);
	
	int p = 2;
	int q = 2;
	
	b[0][0] = 5;
	b[0][1] = 2;
	b[1][0] = 5;
	b[1][1] = 3;
	
	int **a;
	allocate_matrix(&a, 2, 2);
	
	int m = 2;
	int n = 2;
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	
	int **a_expected;
	allocate_matrix(&a_expected, 3, 3);
	
	a_expected[0][0] = 1;
	a_expected[0][1] = 1;
	a_expected[0][2] = 1;
	
	a_expected[1][0] = 1;
	a_expected[1][1] = 1;
	a_expected[1][2] = 1;
	
	a_expected[2][0] = 1;
	a_expected[2][1] = 1;
	a_expected[2][2] = 1;
	
	int **b_expected;
	allocate_matrix(&b_expected, 3, 3);
	
	b_expected[0][0] = 5;
	b_expected[0][1] = 2;
	b_expected[0][2] = 2;
	
	b_expected[1][0] = 5;
	b_expected[1][1] = 3;
	b_expected[1][2] = 3;
	
	b_expected[2][0] = 5;
	b_expected[2][1] = 2;
	b_expected[2][2] = 2;

	change_matrix_add(&a, &b, &m, &n, &q, &p);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] != a_expected[i][j] || b[i][j] != b_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 3);
	free_matrix(b_expected, 3);
	free_matrix(b, p);
	
	if (check != 0)
		return FAIL;
	return OK;
}