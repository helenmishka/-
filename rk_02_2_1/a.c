#include <stdio.h>
#define N 100
#define INPUT_ERROR -1
#define OK 0
int read_mas(int a[N][N], int *n, int *m)
{
	int rc;
	if (rc = scanf("%d", n) !=1)
		return INPUT_ERROR;
	if (rc = scanf("%d", m) !=1)
		return INPUT_ERROR;
	for (int i = 0; i < *n; i++)
	{
		for( int j = 0; j < *m; j++)
		{
			if (rc = scanf("%d", &a[i][j]) !=1)
				return INPUT_ERROR;
		}
	}
	return OK;
}
void print_mas(int a[N][N], int n, int m)
{
	printf("%d ", n);
	printf("%d ", m);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for( int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);	
		}
		printf("\n");
	}
}


int max(int a[N][N], int n, int m, int *ind_i,int *ind_j)
{
	int max = a[0][0];
	*ind_i = 0;
	*ind_j = 0;
	for (int i = 0; i < n; i++)
	{
		for( int j = 0; j < m; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				*ind_i = i;
				*ind_j = j;
			}				
		}
	}
	return OK;
}
int min(int a[N][N], int n, int m, int *ind_i,int *ind_j)
{
	int min = a[0][0];
	*ind_i = 0;
	*ind_j = 0;
	for (int i = 0; i < n; i++)
	{
		for( int j = 0; j < m; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				*ind_i = i;
				*ind_j = j;
			}				
		}
	}
	return OK;
}
void replace(int a[N][N],int n, int max_i, int max_j, int min_i, int min_j)
{
	
	int temp;
	for(int i = 0;i<n;i++)
	{
		temp = a[i][min_j];
		a[i][min_j] = a[i][max_j];
		a[i][max_j] = temp;
	}
}

int main()
{
	int a[N][N];
	int n;
	int m;
	int max_i, max_j;
	int min_i,min_j;
	if(read_mas(a, &n, &m) != OK)
		return INPUT_ERROR;
	min(a,n,m,&min_i,&min_j);
	max(a,n,m,&max_i,&max_j);
	replace(a,n,max_i,max_j,min_i,min_j);
	print_mas(a, n, m);
	return OK;
}

	