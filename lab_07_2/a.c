#include <stdio.h>
#include <string.h>
#define OK 0
#define ERROR -1
#define FILE_ERROR -2
#define INPUT_ERROR -3
#define CMD_ERROR 53
#define N 31
#define C 16
#define M 100

typedef struct
{
	char name[N];
	char creator[C];
	unsigned int price;
	unsigned int quantity;
}product_t;

int read_file(FILE *f, product_t a[M], int *size)
{
	*size = 0;
	int flag = 0;

	if (!f)
		return FILE_ERROR;
	while (fgets(a[*size].name, N, f))
	{
		char s[N];
		flag++;
		
		if (!fgets(a[*size].creator, C, f))
		{
			return INPUT_ERROR;
		}
		flag++;
		if (!fgets(s, M, f))
		{
			return INPUT_ERROR;
		}
		if (sscanf(s, "%u", &a[*size].price) != 1)
		{
			return INPUT_ERROR;
		}
		flag++;
		if (!fgets(s, M, f))
		{
			return INPUT_ERROR;
		}
		if (sscanf(s, "%u", &a[*size].quantity) != 1)
		{
			return INPUT_ERROR;
		}
		flag++;
		*size += 1;
	}
	if (flag < 4 || flag % 4 != 0)
	    return INPUT_ERROR;
	return OK;
}

void sort(product_t a[M], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j - 1].price < a[j].price)
			{
				product_t temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			if (a[j - 1].price == a[j].price && a[j - 1].quantity < a[j].quantity)
			{
				product_t temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

void write_file(FILE *f, product_t a[M], int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(f, "%s", a[i].name);
		fprintf(f, "%s", a[i].creator);
		fprintf(f, "%u\n", a[i].price);
		fprintf(f, "%u\n", a[i].quantity);
	}
}

void print_info_product(product_t a)
{
	printf("%s", a.name);
	printf("%s", a.creator);
	printf("%u\n", a.price);
	printf("%u\n", a.quantity);
}

int is_end_substr(char str[N], char substr[N])
{
	char s[N] = { 0 };
	int i = 0;
	int len_substr = strlen(substr);
	int len_str = strlen(str);
	int flag = 0;
	while (i < len_str && flag == 0)
	{
		if (len_str - i == len_substr)
		{
			strcpy(s, &str[i]);
			flag = 1;
		}
		i++;
	}
	return strcmp(s, substr);
}

int search_product(product_t a[M], int size, char substr[N])
{
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (is_end_substr(a[i].name, substr) == 0)
		{
			print_info_product(a[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		return ERROR;
	return OK;
}


void insert_product(product_t a[M], int *size, product_t new)
{
	int i = 0;
	int flag = 0;
	while (flag == 0 && i < *size)
	{
		if (a[i].price < new.price)
		{
			for (int j = *size; j >= i ; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = new;
			flag = 1;
			*size += 1; 
		}
		if (a[i].price == new.price)
		{
			if (a[i].quantity < new.quantity)
			{
				for (int j = *size; j >= i ; j--)
				{
					a[j] = a[j - 1];
				}
				a[i] = new;
				flag = 1;
				*size += 1;
			}
		}
		i++;
	}
	if (flag == 0)
	{
		a[*size] = new;
		*size += 1;
	}
}

product_t input_product()
{
	product_t new;
	
	FILE *f = stdin;
	
	char s[N];
	fgets(new.name, N, f);
	fgets(new.creator, C, f);
	fgets(s, M, f);
	sscanf(s, "%u", &new.price);
	fgets(s, M, f);
	sscanf(s, "%u", &new.quantity);
	
	return new;
}

int main(int argc, char *argv[])
{
	product_t goods[M];
	int size;
	
	if (argc != 4 && argc != 3)
		return CMD_ERROR;
	
	if (argc == 4)
	{
		char *key = argv[1];
		char *file_in = argv[2];
		char *file_out = argv[3];
		char *substr = argv[3];
		if (strcmp(key, "st") == 0)
		{
			FILE *f = fopen(file_in, "r");
			if (read_file(f, goods, &size) != OK)
				return ERROR;
			fclose(f);
			sort(goods, size);
			FILE *t = fopen(file_out, "w");
			write_file(t, goods, size);
			fclose(t);
		}
		else if (strcmp(key, "ft") == 0)
		{
			strcat(substr, "\n");
			FILE *f = fopen(file_in, "r");
			if (read_file(f, goods, &size) != OK)
				return ERROR;
			fclose(f);
			if (search_product(goods, size, substr) != OK)
				return ERROR;
		}
		else
			return CMD_ERROR;
	}
	if (argc == 3)
	{
		char *key = argv[1];
		char *file_in_out = argv[2];
		product_t new_product;
		
		if (strcmp(key, "at") == 0)
		{
			FILE *f = fopen(file_in_out, "r");
			if (read_file(f, goods, &size) != OK)
				return ERROR;
			fclose(f);
			new_product = input_product();
			insert_product(goods, &size, new_product);
			f = fopen(file_in_out, "w");
			write_file(f, goods, size);
			fclose(f);
		}
		else
			return CMD_ERROR;
	}
	return OK;
}