#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// MAX queue size

typedef struct queue
{
	int current_size
	int head;
	int tail;
	int itens[MAX]
}queue;

queue* create_queue()
{
	queue* n_q = malloc(sizeof(queue));
	(*n_q).current_size = 0;
	(*n_q).head = 0;
	(*n_q).tail = (MAX - 1);
}

void enqueue(queue *q, int item)
{
	if((*q).current_size >= MAX) printf("QUEUE OVERFLOW\n");
	else
	{
		(*q).tail = (((*q).tail + 1) % MAX);
		(*q).itens[(*q).tail] = item;
		(*q).current_size++;
	}
}

int dequeue(queue *q)
{
	if ((*q).current_size == 0)
	{
		printf("QUEUE UNDERFLOW\n");
		return -1;
	}

	else
	{
		int dequeued = (*q).itens[(*q).head];
		(*q).head = (((*q).head + 1) % MAX);
		(*q).current_size--;
		return dequeued;
	}
}