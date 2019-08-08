#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
	int size;
	int data[MAX];
}heap;

heap* create_heap()
{
	heap* nhp = malloc(sizeof(heap));
	(*nhp).size = 0;
	int i;

	for (i = 0; i < MAX; ++i)
	{
		(*nhp).data[i] = 0;
	}
}

int get_parent_index(heap* hp, int i)
{
	return (i/2);
}

int get_left_index(heap* hp, int i)
{
	return (2*i);
}

int get_right_index(heap* hp, int i)
{
	return ((2*i)+1);
}

int item_of(heap* hp, int i)
{
	return (*hp).data[i];
}

void enqueue(heap* hp, int i)
{
	if ((*hp).size >= MAX) printf("Heap overflow\n");

	else
	{
		(*hp).data[++(*hp).size] = item;

		int key_index = (*hp).size;
		int parent_index = get_parent_index(hp, (*hp).size);

		while (parent_index >= 1 && (*hp).data[key_index] > (*hp).data[parent_index])
		{
			swap(&(*hp).data[key_index], &(*hp).data[parent_index]);
			key_index = parent_index;
			parent_index = get_parent_index(hp, key_index);
		}
	}
}

int dequeue(heap *hp)
{
	if ((*hp).size == 0)
	{
		printf("Heap Underflow\n");
		return -1;
	}
	else
	{
		int item = (*hp).data[1];
		(*hp).data[1] = (*hp).data[(*hp).size]
		(*hp).size--;
		max_heapify(heap, 1);
	}

	return item;
}

void max_heapify(heap *hp, int i)
{
	int largest;
	int left_index = get_left_index(hp, i);
	int right_index = get_right_index(hp, i);

	if (left_index <= (*hp).size && (*hp).data[left_index] > (*hp).data[i])
	{
		largest = left_index;
	}
	else
	{
		largest = i;
	}

	if (right_index <= (*hp).size && (*hp).data[right_index] > (*hp).data[largest])
	{
		largest = right_index;
	}

	if ((*hp).data[i] != (*hp).data[largest])
	{
		swap(&(*hp).data[i], &(*hp).data[largest]);
		max_heapify(hp, largest);
	}
}

void heapsort(heap* hp)
{
	int i;

	for (i = (*hp).size; i >= 2 ; i--)
	{
		swap(&(*hp).data[1], &(*hp).data[i]);
		(*hp).size--;
		max_heapify(hp, 1);
	}
}

