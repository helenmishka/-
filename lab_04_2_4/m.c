#include <stdio.h>
#include <math.h>
#define N 10

int read_arr(int x[], int t)
{
    int i, n;
    int rc;

    rc = scanf("%d", &n);
    if (n > t || n == 0 || rc != 1)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < n ; i++)
        {
            rc = scanf("%d", &x[i]);
            if (rc != 1)
				return -1;
        }
        return n;
    }
}
void selection_sort(int x[], int n)
{
    int min_pos, tmp;

    for (int i = 0; i < n; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
            if (x[min_pos] > x[j])
                min_pos = j;
        tmp = x[min_pos];
        x[min_pos] = x[i];
        x[i] = tmp;
    }
}
void print_arr(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

int main()
{
    int x[N];
    int len;

    len = read_arr(x, N);

    if (len == -1)
    {
        return 1;
    }
    else
    {
		selection_sort(x, len);
		print_arr(x, len);
    }
}
