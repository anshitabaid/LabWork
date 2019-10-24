#include <limits.h> 
#include <stdio.h> 
int findVert(int v, int dist[], int curSet[]) {  
	int min = INT_MAX, min_index; 
	for (int i=1; i<=v; i++) {
		if (curSet[i] == 0 && dist[i] <= min) {
			min = dist[i];
			min_index = i; 
		}
	}
	return min_index; 
}  
void dijkstra(int v,int graph[100][100], int src) { 
	int dist[v+1];
	int curSet[v+1]; 
	for (int i=1; i<=v; i++) {
		dist[i] = INT_MAX;
		curSet[i] = 0; 
	}
	dist[src] = 0; 
	for (int count = 0; count <= v - 1; count++) {  
		int u = findVert(v,dist, curSet); 
		curSet[u] = 1;  
		for (int i=1; i<=v; i++) {
			if (!curSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i]) 
				dist[i] = dist[u] + graph[u][i];
		}			 
	} 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i=1; i<=v; i++) 
		printf("%d \t\t %d\n", i, dist[i]);
} 

int main() { 
	int v;
	printf("Enter V: \n");
	scanf("%d",&v);
	int graph[100][100];

	for(int i=0; i<=v; i++)
		graph[0][i] = 0;

	for(int j=0; j<=v; j++)
		graph[j][0] = 0;

	printf("Enter adj matrix: (0 if no edge)\n");

	for(int i=1; i<=v; i++) {
		for(int j=1; j<=v; j++) {
			scanf("%d",&graph[i][j]);
		}
	}

	printf("Enter source: \n");
	int src;
	scanf("%d",&src);
	dijkstra(v,graph, src); 

	return 0; 
} 

/*
Enter V: 
5
0 3 0 7 0
3 0 4 2 0
0 4 0 5 6
7 2 5 0 4
0 0 6 4 0
Enter source: 
1
Vertex 		 Distance from Source
1 		 0
2 		 3
3 		 7
4 		 5
5 		 9
*/