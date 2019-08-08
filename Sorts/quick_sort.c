#include <stdio.h>

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void qsort(int *a, int left_i, int right_i)
{
	int left, right, pivot;

	if(left_i >= right_i) return;

	left = left_i;
	right = right_i;
	pivot = a[(left_i + right_i)/2];

	while(left <= right)
	{
		while(a[left] < pivot) left++;
		while(a[right] > pivot) right--;

		if (left <= right)
		{
			swap(&a[left], &a[right]);
			left++;
			right--;
		}

		qsort(a, left_i, right);
		qsort(a, left, right_i);
	}
}

int main()
{
	int size, leu, i;
	scanf("%d", &size);
	int a[size];

	for (i = 0; i < size; ++i)
	{
		scanf("%d", &leu);
		a[i] = leu;
	}

	qsort(a, 0, size - 1);

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}