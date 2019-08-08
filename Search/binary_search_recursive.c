#include <stdio.h>

int binary_search (int *a, int b, int m, int e, int element)
{
	if(b > e) return -1;

	else if(a[m] == element) return m;

	else if (a[m] > element)
	{
		e = m - 1;
		m = ((b+e)/2);
		binary_search(a, b, m, e, element);		
	}

	else if (a[m] > element)
	{
		b = m + 1;
		m = ((b+e)/2);
		binary_search(a, b, m, e, element);		
	}
}

int main()
{
	int size, leu, element, b, m, e, i;
	scanf("%d", &size);

	int a[size];

	for (i = 0; i < size; ++i)
	{
		scanf("%d", &leu);
		a[i] = leu;
	}

	scanf("%d", &element);

	b = 0;
	e = size - 1;
	m = ((b+e)/2);

	binary_search(a, b, m, e, element);
	return 0;
}
