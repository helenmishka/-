#include <stdio.h>
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

void print_arr(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

int primes(int number)
{
    if (number < 2)
        return -1;
    else
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
                return -1;
        }
    return 0;
}

void number_primes(int x[], int n, int new_arr[], int *prime_count)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (!(primes(x[i]))) 
        {
            new_arr[j] = x[i]; 
            j++;
        }
    }
    *prime_count = j; 
}
int main()
{
    int x[N], new_arr[N];
    int len, prime_count;

    len = read_arr(x, N);

    if (len == -1)
    {
        return -1;
    }
    else
    {
		number_primes(x, len, new_arr, &prime_count);
		
        if (!prime_count)
			return -1;
        else
		{
			print_arr(new_arr, prime_count);
            return 0;
		}
    }
}
