#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dmatrix.h"
#include "memory.h"
#include "codes_errors.h"

int del_row(int ***a, int *n, int i_str)
{
	free((*a)[i_str]);
	for (int i = i_str; i < *n - 1; i++)
	{
		(*a)[i] = (*a)[i + 1];
	}
	*n = *n - 1;
	if (resize_del_row(a, *n) != OK)
		return MEMORY_ERROR;
	
	return OK;
}

int del_column(int ***a, int n, int *m, int j_col)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = j_col; j < *m - 1; j++)
			(*a)[i][j] = (*a)[i][j + 1];
	}
	*m = *m - 1;
	if (resize_del_column(a, n, *m) != OK)
		return MEMORY_ERROR;
	
	return OK;
}

void min_element(int **a, int m, int n, int *i_min, int *j_min)
{
	int min = a[0][0];
	*i_min = 0;
	*j_min = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] <= min)
			{
				*i_min = i;
				*j_min = j;
				min = a[i][j];
			}
		}
	}	
}

int change_matrix_del(int ***a, int *m, int *n)
{
	int i_min = 0, j_min = 0;
	
	if (*n == *m)
		return OK;
	if (*n > *m)
	{
		while (*n != *m)
		{
			min_element(*a, *m, *n, &i_min, &j_min);
			if (del_row(a, n, i_min) != OK)
				return MEMORY_ERROR;
		}
	}
	else
	{
		while (*n != *m)
		{
			min_element(*a, *m, *n, &i_min, &j_min);
			if (del_column(a, *n, m, j_min) != OK)
				return MEMORY_ERROR;
		}
	}
	return OK;
}

int geometric_mean(int **a, int n, int ind)
{
	int sr;
	double geom_sr;
	int mult = 1;
	for (int i = 0; i < n; i++)
		mult *= fabs(a[i][ind]);
	geom_sr = pow(mult, 1.0 / n);
	sr = floor(geom_sr);
	return sr;
}

int min_element_in_row(int **a, int m, int ind)
{
	int min = a[ind][0];
	for (int j = 0; j < m; j++)
	{
		if (min > a[ind][j])
			min = a[ind][j];
	}
	return min;
}

int add_row(int ***a, int *n, int m)
{
	if (resize_add_row(a, *n, m) != OK)
		return MEMORY_ERROR;
	for (int j = 0; j < m; j++)
		(*a)[*n][j] = geometric_mean(*a, *n, j);
	*n = *n + 1;
	
	return OK;
}

int add_column(int ***a, int n, int *m)
{
	if (resize_add_column(a, n, *m) != OK)
		return MEMORY_ERROR;
	for (int i = 0; i < n; i++)
		(*a)[i][*m] = min_element_in_row(*a, *m, i);
	*m = *m + 1;
	
	return OK;
}

int change_matrix_add(int ***a, int ***b, int *m, int *n, int *q, int *p)
{
	if (*m == *q)
		return OK;
	
	if (*m > *q)
	{
		while (*n != *p)
		{
			if (add_row(b, p, *q) != OK)
				return MEMORY_ERROR;
		}
		while (*m != *q)
		{
			if (add_column(b, *p, q) != OK)
				return MEMORY_ERROR;
		}
	}
	else
	{
		while (*n != *p)
		{
			if (add_row(a, n, *m) != OK)
				return MEMORY_ERROR;
		}
		while (*m != *q)
		{
			if (add_column(a, *n, m) != OK)
				return MEMORY_ERROR;
		}
	}
	return OK;
}

void transpose_matrix(int **a, int ***a_t, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(*a_t)[i][j] = a[j][i];
		}
	}
}

void copy_matrix(int **a, int ***a_copy, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(*a_copy)[i][j] = a[i][j];
		}
	}
}
void identity_matrix(int ***identity, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				(*identity)[i][j] = 1;
			else
				(*identity)[i][j] = 0;
		}
	}
}

void mult_operation(int ***a, int **a_t, int **a_copy, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int result = 0;
			for (int p = 0; p < n; p++)
			{
				result += ((*a)[i][p] * a_t[j][p]);
			}
			a_copy[i][j] = result;	
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(*a)[i][j] = a_copy[i][j];
		}
	}
}

int pow_matrix(int ***a, int n, int m, int pow)
{
	int **a_t;
	int **a_copy;
	
	int check = 0;
	
	if (pow == 0)
	{
		identity_matrix(a, n);
		return OK;
	}
	
	if (allocate_matrix(&a_t, m, n) != OK)
		check = 1;
	
	if (check != 1)
	{
		transpose_matrix(*a, &a_t, n, m);
		
		if (allocate_matrix(&a_copy, m, n) != OK)
			check = 1;
		
		if (check != 1)
		{
			copy_matrix(*a, &a_copy, n, m);
			
			int count = 1;
			
			while (count != pow)
			{
				mult_operation(a, a_t, a_copy, n, m);
				count++;
			}
		}
	}
	
	free_matrix(a_copy, n);
	free_matrix(a_t, n);
	
	if (check == 1)
		return MEMORY_ERROR;
	return OK;
}

int multiplication_matrix(int ***a, int **b, int n, int m)
{
	int **b_t;
	int **a_c;
	
	int check = 0;
	if (allocate_matrix(&b_t, m, n) != OK)
		check = 1;
	if (check != 1)
	{
		transpose_matrix(b, &b_t, n, m);
		
		if (allocate_matrix(&a_c, m, n) != OK)
			check = 1;
		
		if (check != 1)
		{
			copy_matrix(*a, &a_c, n, m);
			mult_operation(a, b_t, a_c, n, m);
		}
	}

	free_matrix(a_c, n);
	free_matrix(b_t, n);
	
	if (check == 1)
		return MEMORY_ERROR;
	return OK;
}