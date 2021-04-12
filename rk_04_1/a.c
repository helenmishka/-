#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

int input_name(town new[N], int *size)
{
	int i = 0;
	char s[N] = "end";
	int flag = 0;
	while (flag == 0)
	{
		scanf("%s", new[i].name);
		if (strcmp(new[i].name, s) == 0)
			break;
		scanf("%s", new[i].region);
		scanf("%s", new[i].okrug);
		scanf("%d", &new[i].people);
		scanf("%d", &new[i].year);
		i += 1;
		*size += 1;
	}
	return 0;
}

void print(town a)
{

	printf("%s\n", a.name);
	printf("%s\n", a.region);
	printf("%s\n", a.okrug);
	printf("%d\n", a.people);
	printf("%d\n", a.year);
}

void sort(town a[N], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (a[i].people < a[j].people)
			{
				town temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
			if (a[i].people == a[j].people)
			{
				if (strcmp(a[j].name, a[i].name) < 0)
				{
					town temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			}
			
		}
	}
}

void input_list(node **head, town data)
{
	node *current = *head; 
	node *new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while(current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void input(town data[N], int size, node **head)
{
	for (int i = 0; i <size; i++)
		input_list(head, data[i]);
}


void print_list(node *head)
{
	node *p = head;
	do
	{
		print(p->data);
		p = p->next;
	}while(p!= NULL);
}

void free_list(node *head)
{
	node *p = head;
	for (; head; head = p)
	{
		p = head->next;
		free(head);
	}
}

int main()
{
	town a[255];
	node *head = NULL;
	int size;
	input_name(a, &size);
	sort(a, size);
	input(a, size, &head);
	print_list(head);
	puts("end");
	free_list(head);
}
