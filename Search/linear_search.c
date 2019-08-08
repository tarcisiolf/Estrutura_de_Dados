#include <stdio.h>

int linear_search (int *array, int element, int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		if (array[i] == element) return i;
	}

	return -1; 
}