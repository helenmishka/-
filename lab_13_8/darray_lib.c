#include <stdio.h>
#include <stdlib.h>
#include "darray_lib.h"


int read_array(double **end, double **start)
{
	int n;
	
	if (scanf("%d", &n) != 1)
		return INPUT_ERROR;
	
	if (n <= 0)
		return INPUT_ERROR;
	
	*start = malloc(n * sizeof(*start));
	
	if (!(*start))
		return ERR;
	
	*end = *start + n;
	
	for (double *p = *start; p < *end; p++)
	{
		if (scanf("%lf", p) != 1)
		{
			free(*start);
			return INPUT_ERROR;
		}
	}
	return OK;
}

void print_array(double *start, double *end)
{
	for (double *p = start; p < end; p++)
	{
		printf("%8.6lf ", *p);
	}
}

double find_m1(double *start, double *end)
{
	int i = 0;
	double numerator = 0;
	double denominator = 0;
	double m_1;
	
	for (double *p = start; p < end; p++)
	{
		denominator += (i + 1) * (i + 1);
		numerator += (i + 1) * (i + 1) * (*p);
		i++;
	}
	
	m_1 = numerator / denominator;
	
	return m_1;
}

double max_diff(double *start, double *end, double m_1)
{
	double max = 0;
	double diff;
	double number;
	
	for (double *p = start; p < end; p++)
	{
		if (*p < 0)
			diff = (*p * (-1)) - m_1;
		else
			diff = *p - m_1;
		
		if (diff < 0)
			diff *= (-1);
		if (diff > max)
		{
			max = diff;
			number = *p;
		}
	}
	return number;
}

int resize_d(double **start, int len)
{
	double *new_start;
	new_start = realloc(*start, len * sizeof(*new_start));
	
	if (new_start)
	{
		*start = new_start;
		new_start = NULL;
	}
	else
		return ERR;

	return OK;
}

int resize_a(double **start, double **end, int n)
{
	int len = *end - *start;
	
	double *new_start;
	new_start = realloc(*start, (len + n) * sizeof(*new_start));
	
	if (new_start)
	{
		*start = new_start;
		*end = *start + len + n;
		new_start = NULL;
	}
	else
		return ERR;

	return OK;
}

void del_element(double **start, double **end, double number)
{
	for (double *p = *start; p < *end; p++)
	{
		if (*p == number)
		{
			for (double *p_1 = p + 1; p_1 < *end; p_1++)
				*(p_1 - 1) = *p_1;
			break;
		}
	}
}

int del(double **start, double **end, double m_1)
{
	int len = *end - *start;
	double number;
	
	if (len < 3)
		return ERR;

	
	number = max_diff(*start, *end, m_1);
	
	del_element(start, end, number);
	
	len -= 1;
	
	if (resize_d(start, len) != OK)
		return ERR;
	
	*end = *start + len;
	
	number = max_diff(*start, *end, m_1);
	
	del_element(start, end, number);
	
	len -= 1;
	
	if (resize_d(start, len) != OK)
		return ERR;
	
	*end = *start + len;
	
	return OK;
}

double find_m2(double *start, double *end)
{
	int len = end - start;
	
	double m_2 = 0;
	
	for (double *p = start; p < end; p++)
	{
		m_2 += (*p / len);
	}
	
	return m_2;
}

void add_element(double **start, double **end, double m_2, int pos)
{
	int count = 0;
	
	for (double *p = *start; p < *end; p++)
	{
		if (count == pos)
		{
			for (double *p_1 = *end - 1 ; p_1 > p; p_1--)
			{
				*(p_1) = *(p_1 - 1);
			}
			*p = m_2;
			break;
		}
		count++;
	}
}

int scanf_pos(int *pos)
{
	if (scanf("%d", pos) != 1)
		return INPUT_ERROR;
	
	return OK;
}

int add_m2(double **start, double **end, double m_2, int pos)
{
	int len = *end - *start;
	
	if (pos < 0)
		return ERR;
		
	if (pos >= len)
		return ERR;
	
	if (resize_a(start, end, 1) != OK)
		return ERR;
	
	add_element(start, end, m_2, pos);
	
	if (resize_a(start, end, 2) != OK)
		return ERR;
	
	for (double *p = *end - 2 ; p > *start; p--)
	{
		*(p) = *(p - 1);
	}
	
	*(*end - 1) = m_2;
	*(*start) = m_2;
	
	return OK;
}