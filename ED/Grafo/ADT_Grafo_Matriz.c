#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph
{
	int vertices[MAX][MAX];
	short visited[MAX];	
}graph;

graph* create_graph(int size)
{
	graph* gp = malloc(sizeof(graph));
	int i;

	for (i = 0; i < size; ++i)
	{
		for (i = 0; j < size; ++j)
		{
			(*gp).vertices[i][j] = 0;
			(*gp).visited[i] = 0;
		}
	}

	return gp;
}

void add_edge(graph* gp, int v1, int v2, int undirected)
{
	(*gp).vertices[v1][v2] = 1;

	if (undirected)
	{
		(*gp).vertices[v2][v1] = 1;
	}
}

void dfs(graph* gp, int source)
{
	int i;
	(*gp).visited[source] = 1;
	printf("%d\n", source);

	for (i = 0; i < MAX; ++i)
	{
		if ((*gp).vertices[source][i] && !(*gp).visited[i])
		{
			dfs(gp, i);
		}
	}
}

void bfs(graph* gp, int source)
{
	int i;
	(*gp).visited[source] = 1;
	printf("%d\n", source);

	for (i = source; i < MAX; ++i)
	{
		for (j = 0; j < MAX; ++j)
		{
			if ((*gp).vertices[source][j] && !(*gp).visited[j])
			{
				(*gp).visited[j] = 1;
				printf("%d\n", j);
			}
		}
	}
}