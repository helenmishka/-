#include <stdio.h>
#define N 10
#define OK 0
#define ERR_INPUT -1
#define ERR_RANGE -2


int read_matrix(int x[N][N], int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2)
        return ERR_INPUT;
    if (*n < 2 || *n > N || *m < 2 || *m > N)
        return ERR_RANGE;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            if (scanf("%d", &x[i][j]) != 1)
                return ERR_INPUT;
        }
    return OK;
}

int summ_numbers(int num)
{
	if (num < 0)
		num *= -1;
	
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void min_sum_numb(int x[N][N], int n, int m, int *i_min, int *j_min)
{
    int min_sum = summ_numbers(x[0][0]);
    int sum;

    *i_min = 0;
    *j_min = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            sum = summ_numbers(x[i][j]);
            if (sum < min_sum)
            {
                min_sum = sum;
                *i_min = i;
                *j_min = j;
            }
        }
}

void del_line(int x[N][N], int *n, int m, int i_min)
{
    for (int i = i_min + 1; i < *n; i++)
        for (int j = 0; j < m; j++)
            x[i - 1][j] = x[i][j];
    *n -= 1;
}

void del_column(int x[N][N], int n, int *m, int j_min)
{
    for (int i = 0; i < n; i++)
        for (int j = j_min + 1; j < *m; j++)
            x[i][j - 1] = x[i][j];
    *m -= 1;
}

void print_matrix(int x[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d ", x[i][j]);
}
int main()
{
    int x[N][N];

    int n, m;

    int i_min, j_min;

    int status;

    status = read_matrix(x, &n, &m);
    if (status == OK)
    {
        min_sum_numb(x, n, m, &i_min, &j_min);
        del_line(x, &n, m, i_min);
        del_column(x, n, &m, j_min);
        print_matrix(x, n, m);
    }
    return status;
}
