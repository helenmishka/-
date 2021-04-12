#ifndef STRUCT_H
#define STRUCT_H

#define N 255

typedef struct town
{
	char name[N];
	char region[N];
	char okrug[N];
	int people;
	int year;	
}town;

typedef struct node
{
	town data;
	struct node *next;
}node;
#endif