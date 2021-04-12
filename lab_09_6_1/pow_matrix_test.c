#include <stdio.h>
#include <stdlib.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"

int return_square_of_matrix()
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
	
	a_expected[0][0] = 7;
	a_expected[0][1] = 10;
	a_expected[1][0] = 15;
	a_expected[1][1] = 22;
	
	pow_matrix(&a, n, m, 2);
	
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

int return_matrix()
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
	
	pow_matrix(&a, n, m, 1);
	
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

int return_new_matrix()
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
	
	a_expected[0][0] = 1069;
	a_expected[0][1] = 1558;
	a_expected[1][0] = 2337;
	a_expected[1][1] = 3406;
	
	pow_matrix(&a, n, m, 5);
	
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

int return_identity_matrix()
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
	a_expected[0][1] = 0;
	a_expected[1][0] = 0;
	a_expected[1][1] = 1;
	
	pow_matrix(&a, n, m, 0);
	
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