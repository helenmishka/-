#include <stdio.h>
#include <stdlib.h>
#include "darray.h"

#define OK 0
#define FAIL 1
#define ERROR -2

int find_m1_should_return_m1()
{
	double *start = malloc(3 * sizeof(*start));
	double *end = start + 3;
	int check = 0;
	
	*start = 1;
	*(start + 1) = 0;
	*(start + 2) = 3;
	
	double expected = 2.000000;
	double actuall;
	
	actuall = find_m1(start, end);
	
	if (expected != actuall)
		check = 1;

	free(start);
	
	if (check == 1)
		return FAIL;
	
	return OK;
}

int del_should_return_new_massive()
{
	double *start = malloc(5 * sizeof(*start));
	double *end = start + 5;
	int check = 0;
	
	*start = 1;
	*(start + 1) = 0;
	*(start + 2) = 3;
	*(start + 3) = 5;
	*(start + 4) = 4;
	
	double *start_expected = malloc(3 * sizeof(*start_expected));
	
	*start_expected = 1;
	*(start_expected + 1) = 0;
	*(start_expected + 2) = 3;
	
	double m_1 = 1;
	
	del(&start, &end, m_1);
	
	int len = end - start;
	if (len == 3)
	{
		int n = 0;
		for (double *p = start; p < end; p++)
		{
			if (*p != *(start_expected + n))
			{
				check = 1;
				break;
			}
			n++;
		}
	}
	else
		check = 1;

	free(start);
	free(start_expected);
	
	if (check == 1)
		return FAIL;
		
	return OK;
}


int find_m2_should_return_m2()
{
	double *start = malloc(3 * sizeof(*start));
	double *end = start + 3;
	int check = 0;
	
	*start = 1;
	*(start + 1) = 2;
	*(start + 2) = 3;
	
	double expected = 2.000000;
	double actuall;
	
	actuall = find_m2(start, end);

	if (expected != actuall)
		check = 1;
	free(start);
	if (check == 1)
		return FAIL;
	return OK;
}

int add_element_should_return_mas()
{
	double *start = malloc(2 * sizeof(*start));
	double *end = start + 2;
	int check = 0;
	
	*start = 1;
	*(start + 1) = 0;
	
	double *start_expected = malloc(5 * sizeof(*start_expected));
	
	*start_expected = 2;
	*(start_expected + 1) = 1;
	*(start_expected + 2) = 2;
	*(start_expected + 3) = 0;
	*(start_expected + 4) = 2;
	
	double pos = 1;
	double m_2 = 2;
	
	add_m2(&start, &end, m_2, pos);
	
	int len = end - start;
	if (len == 5)
	{
		int n = 0;
		for (double *p = start; p < end; p++)
		{
			if (*p != *(start_expected + n))
			{
				check = 1;
				break;
			}
			n++;
		}
	}
	else
		check = 1;
	
	free(start);
	free(start_expected);
	
	if (check == 1)
		return FAIL;

	return OK;
}

int main()
{
	int r = find_m1_should_return_m1() \
		+ del_should_return_new_massive() \
		+ find_m2_should_return_m2() \
		+ add_element_should_return_mas();
		
	if (r != OK)
	{
		printf("FAILED %d", r);
		return ERROR;
	}
	
	printf("OK");
	return OK;
}