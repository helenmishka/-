#include <stdio.h>
#include "darray.h"
#include <stdlib.h>

int main()
{
	setbuf(stdout, NULL);
	double *end;
	
	double *start;
	
	
	if (read_array(&end, &start) != OK)
	{
		return INPUT_ERROR;
	}
	
	double m_1 = find_m1(start, end);
	
	if (del(&start, &end, m_1) != OK)
	{
		free(start);
		return ERROR;
	}
	
	double m_2 = find_m2(start, end);
	
	int pos;
	
	if (scanf_pos(&pos) != OK)
	{
		free(start);
		return INPUT_ERROR;
	}
	
	if (add_m2(&start, &end, m_2, pos) != OK)
	{
		free(start);
		return ERROR;
	}
	print_array(start, end);
	free(start);
	return OK;
}