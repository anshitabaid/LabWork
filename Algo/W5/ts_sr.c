#include <stdio.h>
#include <stdlib.h>


int g[101][101];

int V,E;

int visited[101];

int indegree (int ind)
{
	int i;
	for (i=1; i<=V; i++)
		if (g[i][ind]==1)
			return 1;
	return 0;
}

void deleteOutgoingEdges (int ind)
{
	int i;
	for (i=1; i<=V; i++)
		g[ind][i]=0;
}

void source_removal ()
{
	int i, j, count=0;
	for (j=1; j<=V; j++)
	{
		for (i=V; i>=1; i--)
		{
			if (visited [i]==0 && indegree(i)==0) //indegree 0 
			{
				printf ("%d\t", i);
				visited[i]=1;
				count++;
				deleteOutgoingEdges (i);
			}
		}
		if (count==V)
			break;
	}
}

int main () {
	printf("Enter no of vertices: ");
	scanf("%d", &V);
	int i, j, a, b;
	printf("Enter number of edges: ");
	scanf("%d",&E);
	printf("Enter the edges: \n");
	for(i=0; i<E; i++) {
		scanf("%d%d",&a,&b);
		g[a][b] = 1;
		//g[b][a] = 1;
	}
	/*
	for (i=1; i<=V; i++){
		for (j=1; j<=V; j++)
			printf ("%d\t", g[i][j]);
		printf ("\n");
	}
	*/
	printf ("\nTopological sort:\n");
	
	for (i=1; i<=V; i++)
		visited[i]=0;
	source_removal ();
	printf ("\n");

//sample input
/* 
1 4
1 3
1 5
3 4
3 6
5 6
5 2
6 2
*/

/*

3 4
4 2
5 1
5 2
6 1
6 3

*/
}