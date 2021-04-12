#include <stdio.h>
#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2
#define NOT_SYMMETRICAL -3

int read_matrix(int x[N][N], int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2)
        return ERR_INPUT;
    if (*n <= 0 || *n > N || *m <= 0 || *m > N)
        return ERR_RANGE;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            if (scanf("%d", &x[i][j]) != 1)
                return ERR_INPUT;
        }
    return OK;
}

int symmetry(int x[N][N], int n, int m, int k)
{
    int j;

    j = m - 1;

    for (int i = 0; i < m / 2; i++)
    {
        if (x[k][i] == x[k][j])
            j -= 1;
        else
            return NOT_SYMMETRICAL;
    }
    return OK;
}

void arr_1(int a[], int k)
{
    a[k] = 1;
}

void arr_0(int a[], int k)
{
    a[k] = 0;
}

void arr(int a[], int x[N][N], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (symmetry(x, n, m, i) == OK)
			arr_1(a, i);
		else
			arr_0(a, i);
	}
}	

void print_arr(int a[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int x[N][N], a[N];

    int n, m;

    int status;

    status = read_matrix(x, &n, &m);
    if (status == OK)
    {
        arr(a, x, n, m);
		print_arr(a, n);
	}
	return status;
}
