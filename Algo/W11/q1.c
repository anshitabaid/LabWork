#include <stdio.h>
typedef struct edge {
	int src;
	int dest;
	int wt;
} edge;

int visited[100];
int graph[100][100];

int dfs(int v,int verts,int parent) {
	visited[v] = 1;
	for(int i=1; i<=verts; i++) {
		if(i == v)
			continue;
		if(graph[v][i] == 1) {
			if(visited[i] == 0) {
				if(dfs(i,verts,v) == 1) 
					return 1;
			}
			else {
				if(i!=parent) 
					return 1;
			}
		}
	}
	return 0;
}

int check(int v) {
	for(int i=1; i<=v; i++)
		visited[i] = 0;
	for(int i=1; i<=v; i++) {
		if(!visited[i]) 
			if(dfs(i,v,-1) == 1) 
				return 0;		
	}
	return 1;
}

int main() {
	int v,e;
	printf("Enter number of vertices: \n");
	scanf("%d",&v);
	printf("Enter number of edges: \n");
	scanf("%d",&e);

	edge edges[e];
	edge temp;
	int src,dest,wt;
	printf("Enter the edges: \n");
	for(int i=0; i<e; i++) {
		scanf("%d%d%d",&src,&dest,&wt);
		edges[i].src = src;
		edges[i].dest = dest;
		edges[i].wt = wt;
	}

	for(int i=0; i<e-1; i++) {
		for(int j=0; j<e-1-i; j++) {
			if(edges[j].wt > edges[j+1].wt) {
				temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}

	for(int i=1; i<=v; i++)
		for(int j=1; j<=v; j++)
			graph[i][j] = 0;

	int rem = 0;

	for(int i=0; i<e && rem<v-1; i++) {
		graph[edges[i].src][edges[i].dest] = 1;
		graph[edges[i].dest][edges[i].src] = 1;
		if(check(v) == 1) 
			rem++;
		else {
			graph[edges[i].src][edges[i].dest] = 0;
			graph[edges[i].dest][edges[i].src] = 0;
		}
	}

	for(int i=1; i<=v; i++) {
		printf("%d ->\t",i);
		for(int j=1; j<=v; j++) {
			if(graph[i][j] == 1)
				printf("%d\t",j);
		}
		printf("\n");
	}
}