#include <stdio.h>

int gcd(int a, int b)
{
    int max = 0;

    int i;

    if (a > b)
    {
        for (i = 1; i <= b; i++)
        {
            if ((a % i == 0) && (b % i == 0))
            {
                if (i > max)
                    max = i;
            }
        }
    }
    else
    {
        for (i = 1; i <= a; i++)
        {
            if ((a % i == 0) && (b % i == 0))
            {
                if (i > max)
                    max = i;
            }
        }
    }
    return max;
}

int main()
{
	int a, b;

	int rc;

	int m;

	rc = scanf("%d %d", &a, &b);

	if (rc == 2 && a > 0 && b > 0)
	{
		m = gcd(a, b);
		printf("%d", m);
		return 0;
	}
	else
	{
		printf("Input error");
		return 1;
	}
}