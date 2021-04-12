#include <stdio.h>

#define OK 0
#define WRONG_ARG -1
#define EMPTY_FILE -2
#define FILE_ERROR -3
#define ERROR -4
#define CANT_FIND_LOCAL_MAX_ERROR -5

#include <stdio.h>

int ind_min_max(FILE *f, int *min_i, int *max_i)
{
	float tek;
	int flag = 0;
	int i = 0;
	float min_num;
	float max_num;
	
	if (fscanf(f, "%f", &min_num) == 1)
	{
		max_num = min_num;
		*min_i = 0;
		*max_i = 0;
		i += 1;
		
		while (fscanf(f, "%f", &tek) == 1)
		{
			flag = 1;
			if (tek > max_num)
			{
				max_num = tek;
				*max_i = i;
			}
				
			if (tek < min_num)
			{
				min_num = tek;
				*min_i = i;
			}
			i += 1;
		}
		if (flag == 0)
			return FILE_ERROR;
	}
	else
		return FILE_ERROR;
	return OK;
}

int ind(int *min_i, int *max_i)
{
	int temp;
	if (*min_i > *max_i)
	{
		temp = *max_i;
		*min_i = *max_i;
		*max_i = temp;
	}
	return OK;
}

int average(FILE *f, int min_i, int max_i, float *sred)
{
	int i = 0;
	float num;
	int count = 0;
	float summa = 0;

	
	rewind(f);
	ind(&min_i, &max_i);
	while (!feof(f))
	{
		if (fscanf(f, "%f", &num) == 1)
		{
			if (i > min_i && i < max_i)
			{
				summa += num;
				count += 1;
			}
			i += 1;
		}
		else
			return FILE_ERROR;
	}
	
	*sred = summa / count;
	return OK;
}
	


int main(int argc, char *argv[])
{
    int min_i;
	int max_i;
	float sred;


	FILE *f;
	if (argc != 2)
		return ERROR;
	f = fopen(argv[1], "r");
	if (f == NULL)
		return EMPTY_FILE;
	else
	{
	
		if (ind_min_max(f, &min_i, &max_i) == OK)
		{
			average(f, min_i, max_i, &sred);
			printf("%.5f", sred);
			fclose(f);
			return OK;
		}
		else
			return ERROR;
	}
}