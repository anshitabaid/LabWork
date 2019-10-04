#include <stdlib.h>
#include <stdio.h>
#define sz 100
#include <string.h>
#define INF 99999;

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
	for (int i=1; i<=v; i++)
	{
		for (int j=1; j<=v; j++)
		{
			if (i!=j)
			{
				g->mat[i][j]=INF;
			}
			else
				g->mat[i][j]=0;
		}
	}
	return g;
}

void createGraph (Graph g)
{
	int i, a, b, wt;
	printf ("Enter edges\n");
	for (i=0; i<g->e; i++)
	{
		scanf("%d%d%d", &a, &b, &wt);
		g->mat[a][b]=wt;
	}

}
void printArr (int mat[sz][sz], int v,  char * msg)
{
	int i, j;
	printf ("%s\n", msg);
	for (i=1; i<=v; i++)
	{
		for (j=1; j<=v; j++)
			printf ("%d\t", mat[i][j]);
		printf ("\n");
	}
}

int min (int a, int b)
{
	if (a<b)
		return a;
	return b;
}


void floydAlgo (int mat[sz][sz], int v)
{
	int i, j,k;
	printArr(mat, v, "\n");
	for (k=1; k<=v; k++)
	{
		for (i=1; i<=v; i++)
			for (j=1; j<=v; j++)
				mat[i][j]=min(mat[i][j], mat[i][k] + mat[k][j]);
				
		printArr(mat, v, "\n");
	}
}
int main ()
{
	int i, j;
	Graph g = initGraph ();
	createGraph (g);
	int v=g->v;
	int mat[g->v + 1][g->v + 1];
	for ( i=1; i<=v; i++)
		for ( j = 1; j<=v; j++)
			mat[i][j]=g->mat[i][j];

	//memcpy (mat, g->mat , sizeof (int)*((g->v)+1)*((g->v)+1));
	//printArr (g->mat, g->v, "Adjacency matrix");
	floydAlgo(g->mat, g->v);
	//printArr (mat, g->v, "Transitive closure");

}
/*

4
5
1 3 3
2 1 2
3 2 7
3 4 1
4 1 6
*/