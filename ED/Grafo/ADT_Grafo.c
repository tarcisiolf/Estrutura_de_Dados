#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Fila
typedef struct node
{
    int value;
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

queue* enqueue(queue* q, int value)
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

int dequeue (queue* q)
{
	if ((*q).size == 0)
	{
		printf("Queue underflow\n");
		return -999;
	} 

	else
	{
		node* aux;
		aux = (*q).head;
		(*q).head = (*aux).next;
		int value = (*aux).value;
		free(aux);
		(*q).size--;
		return value;
	}
}

// Grafo
typedef struct adj_list
{
	int item;
	struct adj_list *next;
}adj;

typedef struct graph
{
	adj* vertices[MAX];
	short visited[MAX];	
}graph;

graph* create_graph(int size)
{
	graph* gp = malloc(sizeof(graph));
	int i;

	for (i = 0; i < size; ++i)
	{
		(*gp).vertices[i] = NULL;
		(*gp).visited[i] = 0;
	}

	return gp;
}

// Para criar um grafo

/*
	graph *undirected_graph = create_graph();

	add_edge(undirected_graph,1,2)
*/

// Adicionando Arestas

void add_edge(graph* gp, int v1, int v2, int undirected)
{
	adj* v = create_adj_list(v2);
	(*v).next = (*gp).vertices[v1];
	(*gp).vertices[v1] = vertex;

	if (undirected)
	{
		v = create_adj_list(v1);
		(*v).next = (*gp).vertices[v2];
		(*gp).vertices[v2] = vertex;	
	}
}

adj* create_adj_list(int item)
{
	adj_list* n_adj_list = malloc(sizeof(adj_list));
	(*n_adj_list).item = item;
	(*n_adj_list).next = NULL;
	return n_adj_list;
}

void dfs(graph* gp, int source)
{
	(*graph).visited[source] = 1;
	printf("%d\n", source);

	adj *aux = (*gp).vertices[source];

	while(aux != NULL)
	{
		if (!(*gp).visited[(*aux).item])
		{
			dfs(gp, (*aux).item);
		}
		aux = (*aux).next;
	}
}

void bfs(graph* gp, int source)
{
	queue* q = create_queue();
	int dequeued;
	adj *aux = (*gp).vertices[source];
	(*gp).visited[source] = 1;
	q = enqueue(q, source);

	while(!((*q).size == 0))
	{
		dequeued = dequeue(q);
		aux = (*gp).vertices[dequeued];

		while(aux != NULL)
		{
			if (!(*gp).visited[(*aux).item])
			{
				printf("%d\n", (*aux).item);
				(*gp).visited[(*aux).item] = 1;
				q = enqueue(q, (*aux).item);
			}
			aux = (*aux).next;
		}
	}
}