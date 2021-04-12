#include <stdio.h>
#define N 100
#define ERR_RANGE -1
#define ERR_INPUT -2
#define OK 0

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
int input(int a[], int *n)
{
	int rc;
	if ((rc = scanf("%d", n))!=1)
		return ERR_INPUT;
	if (*n > N || *n<1)
		return ERR_RANGE;
	for (int i = 0; i < *n; i++)
		if ((rc = scanf("%d", &a[i])) != 1)
			return ERR_INPUT;
	return OK;
}
int fact(int a)
{
	int fact = 1;
	for (int i = 2; i <=a; i++)
		fact *= i;
	return fact;
}
int insert(int a[], int n)
{
	int fac;
	for (int i = 0; i < n; i += 2)
	{
		fac = fact(a[i]);
		for (int j = n-1; j > i; j--)
		{
			a[j+1] = a[j];
		}
		a[i+1] = fac;
		n++;
	}
	return n;
}

int main()
{
	int n, new_n;
	int a[N];
	
	input(a, &n);
	new_n = insert(a, n);
	print(a, new_n);
}
