#include <stdio.h>
#include <string.h>
#define OK 0
#define ERROR -1

char *my_strpbrk(char *s_1, char *s_2)
{
    int i = 0;
    int j;

    while (s_1[i])
    {
        j = 0;
        while (s_2[j])
        {
            if (s_1[i] == s_2[j])
            {
                return &s_1[i];
            }
            j++;
        }
        i++;
    }
    return NULL;
}

int my_strspn(char *s_1, char *s_2)
{
    int i = 0;
    int j;
    while (s_1[i])
    {
        j = 0;
        while (s_2[j])
        {
            if (s_1[i] == s_2[j])
            {
                break;
            }
            j++;
        }
        if (!s_2[j])
        {
            return i;
        }
        i++;
    }
    return i;
}

int my_strcspn(char *s_1, char *s_2)
{
    int i = 0;
    int j;
    while (s_1[i])
    {
        j = 0;
        while (s_2[j])
        {
            if (s_1[i] != s_2[j])
            {
                j++;
            }
            else
                return i;
        }
        i++;
    }
    return i;
}

char *my_strchr(char *s, int ch)
{
	int i = 0;
	
	while (s[i])
    {
		if (s[i] == ch)
			return &s[i];
		i++;
	}
	if (s[i] == ch)
		return &s[i];
		
	return NULL;
}

char *my_strrchr(char *s, int ch)
{
    int i = 0;
    int j;

    while (s[i])
    {
        i++;
    }

    for (j = i; j >= 0; j--)
    {
        if (s[j] == ch)
            return &s[j];
    }

    return NULL;
}

int main()
{
    char *test1_strpbrk_s1 = "gabc";
    char *test1_strpbrk_s2 = "abc";

    char *test2_strpbrk_s1 = "grte";
    char *test2_strpbrk_s2 = "abc";

    char *test1_strspn_s1 = "gabcabc";
    char *test1_strspn_s2 = "abc";

    char *test2_strspn_s1 = "grte";
    char *test2_strspn_s2 = "abc";

    char *test1_strcspn_s1 = "grtabcabc";
    char *test1_strcspn_s2 = "abc";

    char *test2_strcspn_s1 = "abcbac";
    char *test2_strcspn_s2 = "abc";

    char *test1_strchr_s1 = "gabcabc";
    int strchr_sym_test1 = 'a';

    char *test2_strchr_s1 = "abcbac";
    int strchr_sym_test2 = 'r';
	
	char *test3_strchr_s1 = "abcbac";
    int strchr_sym_test3 = '\0';

    char *test1_strrchr_s1 = "gabcabc";
    int strrchr_sym_test1 = 'b';

    char *test2_strrchr_s1 = "abcbac";
    int strrchr_sym_test2 = 'y';
	
	char *test3_strrchr_s1 = "abcbac";
    int strrchr_sym_test3 = '\0';


    if (my_strpbrk(test1_strpbrk_s1, test1_strpbrk_s2) != \
		strpbrk(test1_strpbrk_s1, test1_strpbrk_s2))
		return ERROR;

    if (my_strpbrk(test2_strpbrk_s1, test2_strpbrk_s2) != \
		strpbrk(test2_strpbrk_s1, test2_strpbrk_s2))
		return ERROR;

    if (my_strspn(test1_strspn_s1, test1_strspn_s2) != \
		strspn(test1_strspn_s1, test1_strspn_s2))
		return ERROR;

    if (my_strspn(test2_strspn_s1, test2_strspn_s2) != \
		strspn(test2_strspn_s1, test2_strspn_s2))
		return ERROR;
		
	if (my_strcspn(test1_strcspn_s1, test1_strcspn_s2) != \
		strcspn(test1_strcspn_s1, test1_strcspn_s2))
		return ERROR;

    if (my_strcspn(test2_strcspn_s1, test2_strcspn_s2) != \
		strcspn(test2_strcspn_s1, test2_strcspn_s2))
		return ERROR;

    if (my_strchr(test1_strchr_s1, strchr_sym_test1) != \
		strchr(test1_strchr_s1, strchr_sym_test1))
		return ERROR;
		
	if (my_strchr(test2_strchr_s1, strchr_sym_test2) != \
		strchr(test2_strchr_s1, strchr_sym_test2))
		return ERROR;
		
	if (my_strchr(test3_strchr_s1, strchr_sym_test3) != \
		strchr(test3_strchr_s1, strchr_sym_test3))
		return ERROR;
	
    if (my_strrchr(test1_strrchr_s1, strrchr_sym_test1) != \
		strrchr(test1_strrchr_s1, strrchr_sym_test1))
		return ERROR;
		
	if (my_strrchr(test2_strrchr_s1, strrchr_sym_test2) != \
		strrchr(test2_strrchr_s1, strrchr_sym_test2))
		return ERROR;
	
	if (my_strrchr(test3_strrchr_s1, strrchr_sym_test3) != \
		strrchr(test3_strrchr_s1, strrchr_sym_test3))
		return ERROR;

    return OK;
}

