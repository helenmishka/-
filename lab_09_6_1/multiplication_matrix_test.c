#include <stdio.h>
#include <stdlib.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"

int return_new_mult_matrix()
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
	allocate_matrix(&b, 3, 3);
	
	int p = 3;
	b[0][0] = 1;
	b[0][1] = 1;
	b[0][2] = 1;
	b[1][0] = 1;
	b[1][1] = 1;
	b[1][2] = 1;
	b[2][0] = 1;
	b[2][1] = 1;
	b[2][2] = 1;
	
	int **a_expected;
	allocate_matrix(&a_expected, 3, 3);
	
	a_expected[0][0] = 6;
	a_expected[0][1] = 6;
	a_expected[0][2] = 6;
	
	a_expected[1][0] = 15;
	a_expected[1][1] = 15;
	a_expected[1][2] = 15;
	
	a_expected[2][0] = 24;
	a_expected[2][1] = 24;
	a_expected[2][2] = 24;
	
	multiplication_matrix(&a, b, n, m);
	
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
