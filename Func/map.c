#include <stdio.h>

int square(int a)
{
	return (a*a);
}

void map(int(*square)(int a), int *array, int control, int size)
{

	if (control == size)
	{
		return;
	}
	else
	{
		array[control] = square(array[control]);
		control++;
		map(square, array, control, size);
	}
}


int main()
{
	int array[3];
	int i, leu;

	for (i = 0; i < 3; ++i)
	{
		scanf("%d", &leu);
		array[i] = leu;
	}

	map(square, array, 0, 3);

	for (i = 0; i < 3; ++i)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}