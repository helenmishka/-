#include <stdio.h>
#include <string.h>
#define N 100
#define INPUT_ERROR -1
#define OK 0
#define IS_SEP 1
#define NOT_WORDS -2

void print_word(char word[N])
{
    int i = 0;
    while (word[i] != '\0' && word[i] != '\n')
    {
        printf("%c", word[i]);
        i++;
    }
    printf(" ");
}

int read_str(char str[N])
{
	FILE *f;
	
    f = stdin;
	
    if (!fgets(str, N, f))
    {
        return INPUT_ERROR;
    }
	
    if (str[strlen(str) - 1] != '\n')
    {
        return INPUT_ERROR;
    }
	return OK;
}
int is_sep(int s)
{
    if (s == ' ' || s == ',' || s == ';' || s == ':' || s == '-' || s == '.' || s == '!' || s == '?')
    {
        return IS_SEP;
    }
    return 0;
}

int my_split(char a[N], char words[N][N])
{
    int i = 0;
    int count_w = 0;
    while (a[i] != '\0')
    {
        while (a[i] != '\0' && is_sep(a[i]))
        {
            i++;
        }
        if (a[i] == '\n')
        {
            return count_w;
        }
        char word[N] = "";
        int len_w = 0;
        while (a[i] != '\0' && !is_sep(a[i]) && a[i] != '\n')
        {
            word[len_w] = a[i];
            i++;
            len_w++;
        }
        for (int j = 0; j < len_w; j++)
        {
            words[count_w][j] = word[j];
        }
        words[count_w][len_w] = '\0';
        count_w++;
    }
    return count_w;
}

int result(char words_a[N][N], char words_b[N][N], int len_a, int len_b, char words[N][N])
{
	int flag_1;
	int r = 0;
	
	for (int i = 0; i < len_a; i++)
	{
		flag_1 = 1;
		for (int j = 0; j < len_b; j++)
		{
			if (strcmp(words_a[i], words_b[j]) == 0)
			{
				flag_1 = 0;
			}
		}
		for (int k = 0; k < len_a; k++)
		{
			if (strcmp(words_a[i], words_a[k]) == 0 && k != i)
			{
				flag_1 = 0;
			}
		}
		if (flag_1 == 1)
		{
			strcpy(words[r], words_a[i]);
			r += 1;
		}
	}
	
	for (int i = 0; i < len_b; i++)
	{
		flag_1 = 1;
		for (int j = 0; j < len_a; j++)
		{
			if (strcmp(words_a[j], words_b[i]) == 0)
			{
				flag_1 = 0;
			}
		}
		for (int k = 0; k < len_b; k++)
		{
			if (strcmp(words_b[k], words_b[i]) == 0 && k != i)
			{
				flag_1 = 0;
			}
		}
		if (flag_1 == 1)
		{
			strcpy(words[r], words_b[i]);
			r += 1;
		}
	}
	if (r == 0)
		return NOT_WORDS;
	
	return r;
}

void print_words(char words_a[N][N], char words_b[N][N], int len_a, int len_b, char words[N][N])
{
	int count_words = result(words_a, words_b, len_a, len_b, words);
	
	if (count_words != NOT_WORDS)
	{
		printf("Result: ");
		
		for (int i = 0; i < count_words; i++)
			print_word(words[i]);
	}	
}

int main()
{
	char s_1[N];
    char s_2[N];
    
	char words_s_1[N][N];
    char words_s_2[N][N];
	
	char words[N][N];
	
	if (read_str(s_1) != OK)
		return INPUT_ERROR;
	
	
	if (read_str(s_2) != OK)
		return INPUT_ERROR;
	
    int len_s_1 = my_split(s_1, words_s_1);
    int len_s_2 = my_split(s_2, words_s_2);
    
	print_words(words_s_1, words_s_2, len_s_1, len_s_2, words);

    return OK;
}
