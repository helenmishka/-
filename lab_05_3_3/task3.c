#include <stdio.h>
#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2


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

int min_element(int x[N][N], int k, int m)
{
    int min = x[k][0];
    for (int j = 0; j < m; j++)
    {
        if (x[k][j] < min)
            min = x[k][j];
    }
    return min;
}

void change_lines(int x[N][N], int m, int i, int k)
{
    int temp;
    for (int j = 0; j < m; j++)
    {
        temp = x[i][j];
        x[i][j] = x[k][j];
        x[k][j] = temp;
    }
}

void sort_matrix(int x[N][N], int n, int m)
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (min_element(x, j, m) > min_element(x, j - 1, m))
                change_lines(x, m, j, j - 1);
        }
}

void print_matrix(int x[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", x[i][j]);
    }
}

int main()
{
    int x[N][N];

    int n, m;

    int status;

    status = read_matrix(x, &n, &m);
    if (status == OK)
    {
        sort_matrix(x, n, m);
        print_matrix(x, n, m);
    }
    else
        return status;
    return OK;
}
