#include <stdio.h>

int par(int a)
{
	if (a%2 == 0) printf("%d\n", a);
}

int impar(int b)
{
	if (b%2 != 0) printf("%d\n", b);
}

void filter(int(*func)(int a), int *array, int control, int size)
{

	if (control == size)
	{
		return;
	}
	else
	{
		func(array[control]);
		filter(func, array, control++, size);
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

	scanf("%d", &leu);

	if (leu%2 == 0) filter(par, array, 0, 3);
	else filter(impar, array, 0, 3);

	return 0;
}