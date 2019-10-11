
// Simple C++ implementation for Kruskal's 
// algorithm 
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
int V,e;
int parent[100]; 
int mat[100][100];
// Find set of vertex i 
int find(int i) 
{ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 


void input ()
{
    int i, j, a, b, wt;
    printf ("Enter v, e\n");
    scanf ("%d%d", &V, &e);
    for (i=0; i<V; i++)
    {
        for (j=0; j<V; j++)
        {
                mat[i][j]=INF;
            
        }
    }
    
    printf ("Enter the %d edges and weights\n", e);
    for (i=1; i<=e; i++)
    {
        scanf ("%d%d%d", &a, &b, &wt);
        mat[a][b]=wt;
        mat[b][a]=wt;//undirectional
    }
}

//unionn of i, j
void unionn(int i, int j) 
{ 
    int a = find(i); 
    int b = find(j); 
    parent[a] = b; 
} 
  
// Finds MST using Kruskal's algorithm 
void kruskalMST(int mat[][V]) 
{ 
    int mincost = 0; // Cost of min MST. 
  
    // Initialize sets of disjoint sets. 
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
  
    // Include minimum weight edges one by one 
    int edge_count = 0;

    printf ("Source\t\tDestination\t\tCost\t\t\n"); 
    while (edge_count < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (find(i) != find(j) && mat[i][j] < min) { 
                    
                    min = mat[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
        unionn(a, b);
        printf ("%d\t\t%d\t\t%d\n", a, b, min); 
        //printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min); 
        mincost += min; 
        edge_count++;
    } 
    printf("\nMinimum cost=%d \n", mincost); 
} 
  
// driver program to test above function 
int main() 
{ 
    /* Let us create the following graph 
          2    3 
      (0)--(1)--(2) 
       |   / \   | 
      6| 8/   \5 |7 
       | /     \ | 
      (3)-------(4) 
            9          
    input ();
        int mat[][V] = { 
        { INT_MAX, 2, INT_MAX, 6, INT_MAX }, 
        { 2, INT_MAX, 3, 8, 5 }, 
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 }, 
        { 6, 8, INT_MAX, INT_MAX, 9 }, 
        { INT_MAX, 5, 7, 9, INT_MAX }, 
    }; 
    */
    input();
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
            printf ("%d\t", mat[i][j]);
        printf ("\n");
    }
    // Print the solution 
    kruskalMST(mat); 
  
    return 0; 
} 
/*
5
7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/
