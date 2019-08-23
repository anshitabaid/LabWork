#include <stdio.h>
#include <stdlib.h>

int stack [100]; 
int top = -1;

void push (int i)
{
	stack[++top]=i;
}

int pop ()
{
	return stack[top--];
}

int g[101][101];

int V,E;

int visited[101];

void dfsv (int v) {
	printf("Visiting %d\n", v);
	visited[v] = 1;
	int i;
	for (i = 1; i <= V; ++i) {
		if (!(visited[i]) && (g[v][i] == 1) && (i != v)) {
			{
				dfsv(i);
			}

		}

	}
	push (v);
}

void dfs () {
	int i;
	for (i = 1; i <= V; ++i) {
		if (!visited[i]) {

			dfsv(i);
			//push (i);
		}
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
	for (i=1; i<=V; i++){
		for (j=1; j<=V; j++)
			printf ("%d\t", g[i][j]);
		printf ("\n");
	}
	dfs();
	printf ("Topological sorting order:\n");
	while (top>=0)
		printf ("%d\t", pop());
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