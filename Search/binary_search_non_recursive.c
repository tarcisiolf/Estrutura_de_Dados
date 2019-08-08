#include <stdio.h>

int binary_search (int *array, int size, int element)
{
	int begin = 0;
	int end = size -1;
	int middle;

	while(begin <= end)
	{
		middle = (begin + end)/2;
		if (array[middle] < element) end = middle + 1;
		else if (array[middle] > element) begin = middle - 1;
		else return middle;
	} 

	return -1;
}

int main()
{
	return 0;
}