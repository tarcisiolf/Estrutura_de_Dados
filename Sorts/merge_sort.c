#include <stdio.h>

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void merge(int *a, int begin, int middle, int end)
{
	int size1 = (middle - begin + 1);
	int size2 = (end - middle);
	int i, j, k, array1[size1 - 1], array2[size2 - 1];

	for (i = 0; i < size1; ++i)
	{
		array1[i] = a[begin+i];
	}
	for (j = 0; j < size2; ++j)
	{
		array2[j] = a[(middle + 1) + j];
	}

	array1[size1] = 1000000;
	array2[size2] = 1000000;

	i = 0;
	j = 0;

	for (k = begin; k <= fim ; ++i)
	{
		if(array1[i] <= array2[j])
		{
			a[k] = array1[i];
			i++;
		}
		else 
		{
			a[k] = array2[j];
			j++;
		}
	}
}

void merge_sort(int *a, int begin, int end)
{
	if (begin < end)
	{
		int middle = ((begin + end)/2);
		merge_sort(a, begin, middle);
		merge_sort(a, middle + 1, end);
		merge(a, begin, middle, end) 
	}
}
int main()
{
	int i, array[8] = {10, 5, 7 , 3, 2, 9, 1};
	merge_sort(a, 0, 8-1);

	for (i = 0; i < 8; ++i)
	{
		printf("%d\n", a[i]);
	}
	
	return 0;
}