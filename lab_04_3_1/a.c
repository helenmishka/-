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
        for (i = 0; i < n; i++)
        {
            rc = scanf("%d", &x[i]);
            if (rc != 1)
                return -1;
        }
        return n;
    }
}
float geometric_mean(int x[], int n)
{
    double sr = 1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            sr *= x[i];
            count += 1;
        }
    }
    if (count != 0)
    {
        sr = pow(sr, (1. / count));
        return sr;
    }
    else
        return -1;
}

void print(double sr)
{
	printf("%lf", sr);
}

int main()
{
    int len;
    int x[N];
    float sr;

    len = read_arr(x, N);

    if (len == -1)
    {
        return -1;
    }
    else
    {
        sr = geometric_mean(x, len);
        if (sr == -1)
            return -1;
        else
		{
			print(sr);
            return 0;
		}
    }
}
