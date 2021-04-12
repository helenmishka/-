/*
 * используемый тип - int
 * числа генерируются от 0 до 199
 * «направление» упорядочивания - по убыванию
 * алгоритм сортировки - пузырьком
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define N 30
#define READ_ERROR -1
#define POS_ERROR -2

int get_number_by_pos(FILE *f, int *n, long int t)
{
    fseek(f, t, SEEK_SET);
    if (fread(n, sizeof(int), 1, f) == 1)
        return OK;
    else
        return POS_ERROR;
}

int put_number_by_pos(FILE *f, int n, long int t)
{
    fseek(f, t, SEEK_SET);
    if (fwrite(&n, sizeof(int), 1, f) == 1)
        return OK;
    else
        return POS_ERROR;
}

int sort(FILE *f)
{
    int t1 = 0;
	int t = 0;
	
    fseek(f, 0, SEEK_END);
	
    long int max_len = ftell(f);
	
    for (int i = 0; i < max_len - 4; i += 4)
    {
        rewind(f);
        for (unsigned int j = 1; j < (max_len - i) / 4; j++)
        {
            if (get_number_by_pos(f, &t1, ftell(f)) == OK && get_number_by_pos(f, &t, ftell(f)) == OK)
            {
                if (t1 < t)
                {
                    if (put_number_by_pos(f, t1, j * sizeof(int)) != OK)
                        return POS_ERROR;
                    if (put_number_by_pos(f, t, (j - 1) * sizeof(int)) != OK)
                        return POS_ERROR;
                }
                else
                    fseek(f, j * sizeof(int), SEEK_SET);
            }
        }
    }
    return OK;
}

void full_file(FILE *f)
{
    int t;
    srand(time(NULL));
 
    for (int i = 0; i < N; i++)
    {
        t = rand() % 100;
        fwrite(&t, sizeof(int), 1, f);
    }
}

int print_file(FILE *f)
{
    int n;
    if (fread(&n, sizeof(int), 1, f) == 0)
        return READ_ERROR;
    rewind(f);
    while (fread(&n, sizeof(int), 1, f) == 1)
        printf("%d ", n);
    return OK;
}
int main(int argc, char *argv[])
{
    FILE *f;
	
    if (argc != 3)
        return READ_ERROR;
	
    if (strcmp(argv[1], "s") == 0)
    {
        f = fopen(argv[2], "r+b");
		
        if (f == NULL)
            return READ_ERROR;
		
        fseek(f, 0, SEEK_END);
        if (ftell(f) == 0)
            return READ_ERROR;
		
        sort(f);
        fclose(f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");
		
        if (f == NULL)
            return READ_ERROR;
		
        fseek(f, 0, SEEK_END);
		
        if (ftell(f) == 0)
            return READ_ERROR;
		
        rewind(f);
        if (print_file(f) == READ_ERROR)
            return READ_ERROR;
        fclose(f);
    }
    else if (strcmp(argv[1], "c") == 0)
    {
        f = fopen(argv[2], "wb");
		
        if (f == NULL)
            return READ_ERROR;
		
        full_file(f);
        fclose(f);
    }
    else
        return READ_ERROR;
    return OK;
}
