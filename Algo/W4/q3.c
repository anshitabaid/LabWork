#include <stdio.h>
#include <stdlib.h>

int g[101][101];

int V,E;

int visited[101];

int queue[101], f = 0, r = 0;

void enqueue (int v) {
	queue[r++] = v;
}

int dequeue () {
	if (f == r) 
	    return -1;
	return queue[f++];
}

void printqueue() {
	if(f == r)
		return;
	for(int i = f; i<r; i++)
		printf("%d\t",queue[i]);
}

void bfsv (int v) {
	visited[v] = 1;
	printf("Visiting %d\n", v);
	enqueue(v);
	while(1) {
		int vert = dequeue();
		if(vert == -1)
			break;
		for(int i = 1; i<=V; i++) {
			if(!visited[i] && g[vert][i] == 1 && i!=vert) {
				visited[i] = 1;
				printf("Visiting %d\n",i);
				enqueue(i);
			}
		}
	}
}

void bfs () {
	int i;
	for (i = 1; i <= V; ++i) {
		if (!visited[i]) {
			bfsv(i);
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
		g[b][a] = 1;
	}
	bfs();
	return 0;
}