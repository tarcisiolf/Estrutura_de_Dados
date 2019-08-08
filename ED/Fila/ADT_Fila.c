#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void* value;
    struct node* next;
} node;

typedef struct queue
{
	int size;
	node* head;
	node* tail;
}queue;

queue* create_queue()
{
	queue* new_queue = malloc(sizeof(queue));
	(*new_queue).head = NULL;
	(*new_queue).tail = NULL;
	(*new_queue).size = 0;
	return new_queue;
}

queue* enqueue(queue* q, void* value)
{
	node* new_node = malloc(sizeof(node));
	(*new_node).value = value;
	(*new_node).next = NULL;

	if ((*q).size == 0)
	{
		(*q).head = new_node;
		(*q).tail = new_node;
		(*q).size++;	
	}

	else
	{
		(*(*q).tail).next = new_node;
		(*q).tail = new_node;
		(*q).size++;
	}
	return q;
}

queue* dequeue (queue* q)
{
	if ((*q).size == 0)
	{
		printf("Queue underflow\n");
		return q;
	} 

	else
	{
		node* aux;
		aux = (*q).head;
		(*q).head = (*aux).next;
		free(aux);
		(*q).size--;
		return q;
	}
}
