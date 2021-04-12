#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "a.h"
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