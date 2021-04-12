#include <stdio.h>

#define OK 0
#define WRONG_ARG -1
#define EMPTY_FILE -2
#define FILE_ERROR -3
#define ERROR -4
#define CANT_FIND_LOCAL_MAX_ERROR -5

int find_local_max_count(FILE *f, int *local_max_count)
{
    int current = 0;
	int previous = 0;
	int next = 0;
	int local_max_count_file = 0;

    if (!f)
        return FILE_ERROR;

    if (feof(f))
        return EMPTY_FILE;

    if (fscanf(f, "%d%d", &previous, &current) == 2)
    {
        if (feof(f))
            return CANT_FIND_LOCAL_MAX_ERROR;

        while (!feof(f))
        {
            if (fscanf(f, "%d", &next) == 1)
            {
                if (current > previous && current > next)
                    local_max_count_file++;
                previous = current;
                current = next;
            }
            else
                return WRONG_ARG;
        }

		*local_max_count = local_max_count_file;
		
        return OK;
    }

    return WRONG_ARG;
}

int main()
{
    int max_count = 0;

    if (find_local_max_count(stdin, &max_count) == OK)
    {
        printf("%d", max_count);

        return OK;
    }

    return ERROR;
}