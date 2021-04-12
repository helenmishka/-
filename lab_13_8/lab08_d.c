#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "darray_lib.h"

typedef int (*proc_read)(double **, double **);
typedef void (*proc_print)(double *, double *);
typedef double (*proc_find_m1)(double *, double *);
typedef double (*proc_find_m2)(double *, double *);
typedef int (*proc_del)(double **, double **, double);
typedef int (*proc_add_m2)(double **, double **, double, int);
typedef int (*proc_scanf_pos)(int *);
int main()
{
	setbuf(stdout, NULL);
	
	HMODULE hlib;
	
	proc_read read_array;
	proc_print print_array;
	proc_find_m1 find_m1;
	proc_del del;
	proc_find_m2 find_m2;
	proc_scanf_pos scanf_pos;
	proc_add_m2 add_m2;
	
	double *end;
	double *start;
	
	hlib = LoadLibrary("darray.dll");
	
	read_array = (proc_read) GetProcAddress(hlib, "read_array");
    if (!read_array)
		return ERR;
	
	if ((read_array)(&end, &start) != OK)
	{
		return INPUT_ERROR;
	}
	
	find_m1 = (proc_find_m1) GetProcAddress(hlib, "find_m1");
    if (!find_m1)
		return ERR;
	
	double m_1 = (find_m1)(start, end);
	
	del = (proc_del) GetProcAddress(hlib, "del");
    if (!del)
		return ERR;
	
	if ((del)(&start, &end, m_1) != OK)
	{
		free(start);
		return ERR;
	}
	
	find_m2 = (proc_find_m2) GetProcAddress(hlib, "find_m2");
    if (!find_m2)
		return ERR;
	
	double m_2 = (find_m2)(start, end);
	
	scanf_pos = (proc_scanf_pos) GetProcAddress(hlib, "scanf_pos");
    if (!scanf_pos)
		return ERR;
	
	int pos;
	
	if ((scanf_pos)(&pos) != OK)
	{
		free(start);
		return INPUT_ERROR;
	}
	
	add_m2 = (proc_add_m2) GetProcAddress(hlib, "add_m2");
    if (!add_m2)
		return ERR;
	
	if ((add_m2)(&start, &end, m_2, pos) != OK)
	{
		free(start);
		return ERR;
	}
	
	print_array = (proc_print) GetProcAddress(hlib, "print_array");
    if (!print_array)
		return ERR;
	(print_array)(start, end);
	free(start);
	FreeLibrary(hlib);
	return OK;
}