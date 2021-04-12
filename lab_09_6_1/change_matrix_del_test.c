#include <stdio.h>
#include <stdlib.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"

int more_rows_than_columns()
{
	int **a;
	int check = 0;
	allocate_matrix(&a, 2, 3);
	
	int n = 3;
	int m = 2;
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	a[2][0] = 5;
	a[2][1] = 6;
	
	int **a_expected;
	allocate_matrix(&a_expected, 2, 2);
	
	a_expected[0][0] = 3;
	a_expected[0][1] = 4;
	a_expected[1][0] = 5;
	a_expected[1][1] = 6;
	
	change_matrix_del(&a, &m, &n);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] != a_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 2);
	
	if (check != 0)
		return FAIL;
	return OK;
}

int more_columns_than_rows()
{
	int **a;
	int check = 0;
	allocate_matrix(&a, 3, 2);
	
	int n = 2;
	int m = 3;
	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	
	int **a_expected;
	allocate_matrix(&a_expected, 2, 2);
	
	a_expected[0][0] = 2;
	a_expected[0][1] = 3;
	a_expected[1][0] = 5;
	a_expected[1][1] = 6;
	
	change_matrix_del(&a, &m, &n);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] != a_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 2);
	
	if (check != 0)
		return FAIL;
	return OK;
}

int square_matrix()
{
	int **a;
	int check = 0;
	allocate_matrix(&a, 2, 2);
	
	int n = 2;
	int m = 2;
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;

	
	int **a_expected;
	allocate_matrix(&a_expected, 2, 2);
	
	a_expected[0][0] = 1;
	a_expected[0][1] = 2;
	a_expected[1][0] = 3;
	a_expected[1][1] = 4;
	
	change_matrix_del(&a, &m, &n);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] != a_expected[i][j])
			{
				check = 1;
				break;
			}
		}
	}
	
	free_matrix(a, n);
	free_matrix(a_expected, 2);
	
	if (check != 0)
		return FAIL;
	return OK;
}