#include <stdio.h>

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void bubble_sort(int* a, int size)
{
	for (i = size - 1; i >= 0; --i)
	{
		for (i = 0; j < i; ++j)
		{
			if(a[j] > a[j+1]) swap(&a[j], &a[j+1]);
		}
	}
}