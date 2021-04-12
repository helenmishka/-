#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "codes_errors.h"

void free_matrix(int **a, int n)
{
	for (int k = 0; k < n; k++) 
	{
		free(a[k]);
	}
	free(a);
}

int allocate_matrix(int ***a, int m, int n)
{
	*a = (int**)malloc(n * sizeof(int*));

	if (!(*a))
	{
		free(*a);
		return MEMORY_ERROR;
	}
	
	for (int i = 0; i < n; i++)
	{
		(*a)[i] = (int*)malloc(m * sizeof(int));
		if (!((*a)[i]))
		{
			free_matrix(*a, n);
			return MEMORY_ERROR;
		}
	}
	
	return OK;
}

int resize_del_row(int ***a, int n)
{
	int **new_a;
	new_a = realloc(*a, n * sizeof(int*));
	
	if (new_a)
	{
		*a = new_a;
		new_a = NULL;
	}
	else
		return MEMORY_ERROR;

	return OK;
}

int resize_add_row(int ***a, int n, int m)
{
	int **new_a;
	new_a = realloc(*a, (n + 1) * sizeof(int*));
	
	if (new_a)
	{
		*a = new_a;
		(*a)[n] = malloc(m * sizeof(int));
		new_a = NULL;
	}
	else
		return MEMORY_ERROR;

	return OK;
}

int resize_del_column(int ***a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int *new_a;
		
		new_a = realloc((*a)[i], m * sizeof(int));
		if (new_a)
		{
			(*a)[i] = new_a;
			new_a = NULL;
		}
		else
			return MEMORY_ERROR;
	}

	return OK;
}

int resize_add_column(int ***a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int *new_a;
		
		new_a = realloc((*a)[i], (m + 1) * sizeof(int));
		if (new_a)
		{
			(*a)[i] = new_a;
			new_a = NULL;
		}
		else
			return MEMORY_ERROR;
	}
	return OK;
}
