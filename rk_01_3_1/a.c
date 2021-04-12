#include <stdio.h>
#include <math.h>
#define ERR_INPUT -1
#define OK 0

void print(int a)
{
	printf("%d", a);
}

int max_n(int d)
{
	int tmp;
	int max;
	
	d = abs(d);
	max = d%10;
	while(d>0)
	{
		tmp = d%10;
		if (tmp > max)
			max = tmp;
		d = d / 10;
	}
	return max;
}	

int min_n(int d)
{
	int tmp;
	int min;
	
	d = abs(d);
	min = d%10;
	
	while(d>0)
	{
		tmp = d%10;
		if (tmp < min)
			min = tmp;
		d = d / 10;
	}
	return min;
}	
int summ(int min, int max)
{
	int summ;
	summ = min + max;
	return summ;
}
int main()
{
	int d;
	int rc;
	int min, max, sum;
	if((rc = scanf("%d", &d)) !=1)
		return ERR_INPUT;
	else
	{
		min = min_n(d);
		max = max_n(d);
		sum = summ(min, max);
		print(sum);
		return OK;
	}
}
	
	