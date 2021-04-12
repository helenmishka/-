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
        for (i = 0; i < n ;i++)
        {
            rc = scanf("%d", &x[i]);
            if (rc != 1)
                return -1;
        }
        return n;
    }
}
int number_palind(int d)
{
    int old_d = d;
    int new_d = 0;
	int tmp;

    while (d > 0)
    {
        tmp = d % 10;
        new_d = new_d * 10 + tmp;
        d = d / 10;
    }

    if (old_d == new_d)
	{
        return 0;
	}
    else
	{
        return -1;
	}
}

int del_palind(int x[], int n)
{
    int count = 0;
	
    for (int i = 0; i < n; i++)
    {
        if (number_palind(x[i]) == 0)
            count += 1;
    }
	if (count == n)
		return -1;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (number_palind(x[i]) == 0)
			{
				for (int j = i + 1; j < n; j++)
				{
					x[j - 1] = x[j];
				}
				n--;
				i--;
			}
		}
		return n;
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
    int len, n;

    len = read_arr(x, N);

    if (len == -1)
    {
        return 1;
    }
    else
    {
		n = del_palind(x, len);
		if (n == -1)
			return -1;
		else
		{
			print_arr(x, n);
			return 0;
		}
    }
}
