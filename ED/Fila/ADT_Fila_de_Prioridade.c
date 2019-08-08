#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void* value;
    int priority;
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

queue* enqueue(queue *pq, void* value, int priority)
{
	node* new_node = malloc(sizeof(node));
	(*new_node).value = value;
	(*new_node).priority = priority;
	(*new_node).next = NULL;

	if ((*pq).size == 0)
	{
		(*pq).head = new_node;
		(*pq).tail = new_node;
		(*pq).size++;	
	}

	else if((*(*pq).head).priority < (*new).priority)
  {
    (*new).next = (*pq).head;
    (*pq).head = new;
    (*pq).size++;
  }
  else
  {
    node* current = (*pq).head;
    int put = 1;
    while((*current).next != NULL)
    {
      if((*current).priority >= (*new).priority && (*(*current).next).priority <= (*new).priority)
      {
        (*new).next = (*current).next;
        (*current).next = new;
        (*pq).size++;
        put = 0;
        break;
      }
      current = (*current).next;
    }
    if(put)
    {
      (*(*pq).tail).next = new;
      (*pq).tail = new;
      (*pq).size++;
    }
  }
  return pq;
}

queue* dequeue(queue *pq)
{
	if ((*pq).size == 0)
	{
		printf("Queue underflow\n");
		return pq;
	} 

	else
	{
		node* aux;
		aux = (*pq).head;
		(*pq).head = (*aux).next;
		free(aux);
		(*pq).size--;
		return pq;
	}
}

int maximum(queue *pq)				//TESTAR
{
	if ((*pq).size == 0)
	{
		printf("Queue underflow\n");
		return -1;
	} 

	else
	{
		return (*((int*) (*(*pq).head).value));
	}
}

int is_empty(queue *pq)				//TESTAR
{
	if (pq.size == 0) return 0;
	else return 1;
}

void print_pq(queue *pq)			//TESTAR
{
	if( (*pq).head == NULL) return;
	int aux = (*((int*) (*(*pq).head).value));
	printf("[%d]",aux);
	if( (*(*pq).head).next == NULL) printf("\n");
	else printf(" -> ");
	print_list_int( (*(*pq).head).next);
}