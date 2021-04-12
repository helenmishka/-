#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include "memory.h"
#include "codes_errors.h"

int scanf_size_matrix(int *n, int *m)
{
	if (scanf("%d", n) != 1)
		return INPUT_ERROR;
	
	if (*n <= 0)
		return INPUT_ERROR;
	
	if (scanf("%d", m) != 1)
		return INPUT_ERROR;
	
	if (*m <= 0)
		return INPUT_ERROR;
	
	return OK;
}

int read_matrix(int ***a, int m, int n)
{
	if (allocate_matrix(a, m, n) != OK)
		return MEMORY_ERROR;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (scanf("%d", &(*a)[i][j]) != 1)
			{
				free_matrix(*a, n);
				return INPUT_ERROR;
			}
		}
	}
	return OK;
}

int scanf_pow(int *r, int *y)
{
	if (scanf("%d", r) != 1)
		return INPUT_ERROR;
	
	if (*r < 0)
		return INPUT_ERROR;
	
	if (scanf("%d", y) != 1)
		return INPUT_ERROR;
	
	if (*y < 0)
		return INPUT_ERROR;
	
	return OK;
}

void print_matrix(int **a, int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}