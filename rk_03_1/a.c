#include <stdio.h>
#include <stdlib.h>

#define ERR 1
#define OK 0

void free_matrix(int ***a, int n)
{
	for (int i = 0; i < n; i++)
	{
		free((*a)[i]);
	}
	free(*a);
}
int read_size(int *n, int *m)
{
	if (scanf("%d", n) != 1)
		return ERR;
	if (scanf("%d", m) != 1)
		return ERR;
	return OK;
}

int allocate_matrix(int ***a, int n, int m)
{
	*a = malloc(n * sizeof(int*));
	if (!(*a))
		return ERR;
	for (int i = 0; i < n; i++)
	{
		(*a)[i] = malloc(m * sizeof(int));
		if (!(*a)[i])
		{
			free_matrix(a, n);
			return ERR;
		}
	}
	return OK;
}

int allocate_new_matrix(int ***a, int n, int m, int *size)
{

	if (n > m)
		*size = n + 1;
	else
		*size = m + 1;
	*a = malloc(*size * sizeof(int*));
	if (!(*a))
		return ERR;
	
	
	int k = 0;
	
	while (k != *size + 1)
	{
		int r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{		
				if (i + j == k)
					r++;
			}
			(*a)[k] = malloc(r * sizeof(int));
		}
		k++;
	}
	
	return OK;
}

int read_matrix(int ***a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (scanf("%d", &(*a)[i][j]) != 1)
			{
				free_matrix(a, n);
				return ERR;
			}
		}
	}
	return OK;
}
void print_matrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void print_new_matrix(int **a, int n, int m, int size)
{
	int k = 0;
	while (k != size + 1)
	{
		int r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{		
				if (i + j == k)
				{
					printf("%d ", a[k][r]);
					r++;
				}
			}
		}
		printf("\n");
		k++;
	}
}

int max_len(int **b, int n, int m, int size, int *max_k)
{
	int k = 0;
	
	int max_len = 0;
	while (k != size + 1)
	{
		int r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{		
				if (i + j == k)
				{
					r++;
				}
			}
		}
		if (max_len < r)
		{
			max_len = r;
			*max_k = k;
		}
		k++;
	}
	return OK;
}

int min_len(int **b, int n, int m, int size, int *min_k)
{
	int k = 0;
	
	int min_len = m + 5;
	
	while (k != size + 1)
	{
		int r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{		
				if (i + j == k)
				{
					r++;
				}
			}
		}
		if (min_len > r)
		{
			min_len = r;
			*min_k = k;
		}
		k++;
	}
	return OK;
}

int diag(int **a, int **b, int n, int m)
{
	
	int k = 0;
	
	while (k != n + 2)
	{
		int r = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{		
				if (i + j == k)
				{
					b[k][r] = a[i][j];
					r++;
				}
			}
		}
		k++;
	}
	return OK;
}

int del(int ***a, int n, int m, int *size, int ind)
{
	free(*a[ind]);
	for (int j = ind; j < *size - 1; j++)
	{
		*a[j] = *a[j+1];
	}
	*size = *size - 1;
	*a = realloc(*a, (*size) * sizeof(int*));
	if (!*a)
		return ERR;
	return OK;
}

int main()
{
	int n, m;
	int **a;
	int **b;
	int size;
	int min_k, max_k;
	
	read_size(&n, &m);
	allocate_matrix(&a, n, m);
	read_matrix(&a, n, m);
	allocate_new_matrix(&b, n, m, &size);
	diag(a, b, n, m);
	print_new_matrix(b, n, m, size);
	max_len(b, n, m, size, &max_k);
	min_len(b, n, m, size, &min_k);
	if (min_k == max_k)
		del (&b,n,m,&size, min_k);
	print_new_matrix(b, n, m, size);
	free_matrix(&a, n);
	return OK;
	
}