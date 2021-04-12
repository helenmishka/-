#include <stdio.h>
#include <string.h>
#define N 100
#define INPUT_ERROR -1
#define ERROR -2

typedef struct
{
	char name[N];
	int year;
	int people;
}town;

int read(FILE *f,town a[N], int *count)
{
    *count = 0;
	while (!feof(f))
	{
		char s[N];
		fgets(a[*count].name , N, f);
		fgets(s, N, f);
		sscanf(s,"%d", &a[*count].year);
		fgets(s, N, f);
		sscanf(s,"%d", &a[*count].people);
		*count += 1;
	}
	return 0;
}
int min_year(town a[N], int count)
{
	char s[N];
	int min;
	int len_str;
	int c = 0;
	for (int i = 0; i < count; i++)
	{
		strcpy(s,a[i].name);
		len_str = strlen(s);
		for(int j = 0; j < len_str; j++)
		{
			if(s[j] == ' ')
			{
				min = a[i].year;
				c += 1;
			}
		}
	}
	if ( c == 0)
		return ERROR;
	
	for (int i = 0; i < count; i++)
	{
		strcpy(s,a[i].name);
		len_str = strlen(s);
		for(int j = 0; j < len_str; j++)
		{
			if(s[j] == ' ')
			{
				if (min > a[i].year)
					min = a[i].year;
			}
		}
	}
	return min;
}

int main()
{
	town a[N];
	int min;
	int count;
	char s[N];
	FILE *f = fopen("in.txt", "r");
	read(f,a,&count);
	fclose(f);
	FILE *t = fopen("out.txt", "w");
	min = min_year(a,count);
	if (min == ERROR)
		return ERROR;
	fprintf(t,"%d", min);
	fclose(t);
	return 0;
	
}