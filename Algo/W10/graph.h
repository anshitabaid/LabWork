#include <stdlib.h>
#include <stdio.h>
#define sz 100
typedef struct graph
{
	int v;
	int e;
	int mat[][sz];
}*Graph;

Graph initGraph ()
{
	int v, e;
	printf ("Enter no of vertices:\t");
	scanf ("%d", &v);
	printf ("Enter no of edges:\t");
	scanf ("%d", &e);
	Graph g = (Graph) malloc (sizeof (int)+ sizeof(int) + sizeof(int)*(v+1)*(v+1));
	g->v=v;
	g->e=e;
	return g;
}

void createGraph (Graph g)
{
	int i, a, b;
	printf ("Enter edges\n");
	for (i=0; i<g->e; i++)
	{
		scanf("%d%d", &a, &b);
		g->mat[a][b]=1;
	}

}

void display(Graph g)
{
	int i, j;
	for (i=1; i<=g->v; i++)
	{
		for (j=1; j<=g->v; j++)
			printf ("%d\t", g->mat[i][j]);
		printf ("\n");
	}
}

