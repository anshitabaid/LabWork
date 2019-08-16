#include "graph.h"

void dfs(Graph g)
{
	int i, j, v;
	v=g->v;
	int visited[v+1];
	for (i=0; i<=v; i++)
		visited[i]=0;

	int top=0;
	AdjListNode stack[v];

}

int main ()
{
	Graph g = createGraph (6);
	makeList (g, g->v);
	printAdjLists (g);
	dfs (g);
}