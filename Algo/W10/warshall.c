#include "graph.h"
#include <string.h>


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

void warshallAlgo (int mat[sz][sz], int v)
{
	int i, j,k;

		printArr(mat, v, "\n");
	for (k=1; k<=v; k++)
	{
		for (i=1; i<=v; i++)
			for (j=1; j<=v; j++)
				if (mat[i][j] || (mat[i][k] && mat[k][j]))
					mat[i][j]=1;

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
	warshallAlgo(g->mat, g->v);
	//printArr (mat, g->v, "Transitive closure");

}
/*

4
4
1 2
2 4
4 1
4 3
*/