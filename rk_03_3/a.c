#include <stdio.h>
#include <stdlib.h>
#include "rk.h"

void free_matrix(int ***a, int n)
{
	for (int i = 0; i < n; i++)
	{
		free((*a)[i]);
	}
	free(*a);
}

int read_size(int *n)
{
	if (scanf("%d", n) != 1)
		return INPUT_ERROR;
	if (*n < 1)
		return INPUT_ERROR;
	return OK;
}

int allocate_matrix(int ***a, int n)
{
	*a = malloc(n * sizeof(int*));
	if (!(*a))
		return MEMORY_ERROR;
	for (int i = 0; i < n; i++)
	{
		(*a)[i] = malloc(n * sizeof(int));
		if (!(*a)[i])
		{
			free_matrix(a, n);
			return MEMORY_ERROR;
		}
	}
	return OK;
}

int read_matrix(int ***a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (scanf("%d", &(*a)[i][j]) != 1)
			{
				free_matrix(a, n);
				return INPUT_ERROR;
			}
		}
	}
	return OK;
}


int allocate_new_matrix(int ***a, int n)
{
	int count_row = n + n - 1;
	*a = malloc(count_row * sizeof(int*));
	if (!(*a))
		return MEMORY_ERROR;
	for (int i = 0; i < count_row; i++)
	{
		(*a)[i] = malloc(n * sizeof(int));
		if (!(*a)[i])
		{
			free_matrix(a, n);
			return MEMORY_ERROR;
		}
	}
	return OK;
}

void reverse(int **a, int **b, int n)
{
	int row = 0;
	
	while (row != n + n - 1)
	{
		int column = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{		
				if (i + j == row)
				{
					b[row][column] = a[i][j];
					column++;
				}
			}
		}
		row++;
	}
}

void new_matrix(int **a, int **b, int n)
{
	for (int i = 0; i < n + n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = 0;
		}
	}
	reverse(a, b, n);
}

void print_new_matrix(int **a, int n)
{
	printf("\n");
	int k = n + n - 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void print_matrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
