#include <stdio.h>
#include <stdlib.h>
#define arrsize 4

int q[100];
int f=0, r=0;


typedef struct adjListNode
{
	int d;
	struct adjListNode * next;
}*AdjListNode;

typedef struct adjList
{
	AdjListNode head;
}*AdjList;

typedef struct graph 
{
	int v; //no of vertices
	AdjList array;
}*Graph;

//create adjacency list node
AdjListNode newAdjListNode (int d)
{
	AdjListNode n = (AdjListNode) malloc (sizeof (struct adjListNode));
	n->d = d;
	n->next=NULL;
	return n;
}

//create graph on v vertices
Graph createGraph (int v)
{
	Graph g = (Graph) malloc (sizeof (struct graph));
	g->v = v;
	g->array = (AdjList)malloc(v*sizeof (struct adjList));

	//each list empty, head is null
	int i;
	for (i=0; i<v; i++)
		g->array[i].head = newAdjListNode(i+1);

	return g;
}

void initMatrix (int mat [][arrsize], int v)
{
	int i, j;
	for (i=0; i<v; i++)
	{
		for (j=0; j<v; j++)
			mat [i][j]=0;
		//mat[i][i]=1; //self connection
	}

}

void insertToList(AdjList a, int d)
{
	AdjListNode temp = a->head;
	while (temp->next)
		temp=temp->next;
	temp->next = newAdjListNode (d);
}

void insertToMatrix (int  mat [][arrsize], int i, int j)
{
	mat[i][j]=1;
}
//make list

void makeList(Graph g,int v)
{
	int i, j,vertex;

	for (i=0; i<v; i++)
	{
		printf("\nVertex %d, Enter the connected vertices (1 - %d), 0 to break:\n", i+1, v);	
		do
		{
			scanf ("%d", &vertex);
			if (vertex!=0)
			{
				insertToList (((g->array)+i), vertex);
			}

		}while (vertex!=0);
	}
}

void makeMatrix (int mat [][arrsize], int v)
{
	int i, j,vertex;

	for (i=0; i<v; i++)
	{
		printf("\nVertex %d, Enter the connected vertices (1 - %d), 0 to break:\n", i+1, v);	
		do
		{
			scanf ("%d", &vertex);
			if (vertex!=0)
			{
				insertToMatrix (mat, i, vertex-1);
			}

		}while (vertex!=0);
	}
}


void printAdjLists (Graph g)
{
	int i;
	int v = g->v;
	for (i=0; i<v; i++)
	{
		AdjListNode temp = ((g->array)+i)->head;
		while (temp->next)
		{
			printf ("%d -> ", temp->d);
			temp=temp->next;
		}
		printf ("%d\n", temp->d);
	}
}

/*
int ** makeMatrix (int v)
{
	int i, j, vertex;
	int ** mat = (int**)calloc (v, sizeof (int *));
	for (i=0; i<v; i++)
	{
		*(mat+i) = (int*)calloc (v, sizeof (int));
		for (j=0; j<v; j++)
			*(*(mat+i)+j)=0;
	}

	for (i=0; i<v; i++)
	{	
		*(*(mat+i)+i)=1;
		printf("\nVertex %d, Enter the connected vertices (1 - %d), 0 to break:\n", i+1, v);	
		do
		{
			scanf ("%d", &vertex);
			if (vertex!=0)
				*(*(mat+i)+vertex)=1;
		}while (vertex!=0);
	}

	return mat;

}
*/
void printAdjMat (int mat[][arrsize], int v)
{
	int i, j;
	printf ("\t");
	for (i=0; i<v; i++)
		printf ("%d\t", i+1);
	printf ("\n");
	for (i=0; i<v; i++)
	{
		printf ("%d\t", i+1);
		for (j=0; j<v; j++)
		{
			int d = mat[i][j];
			printf ("%d\t", d);
		}
		printf ("\n");
	}

}

void dfs_util (int m[][arrsize], int v, int i, int visited[])
{
	printf ("%d\t" ,  i+1);
	visited [i]=1;
	int j;
	for (j=0; j<v; j++)
	{
		if ((!visited[j]) && m[i][j]==1 && i!=j)
		{
			dfs_util (m, v, j, visited);
		}
	}

}

void dfs (int mat[][arrsize], int v)
{
	int visited[v];
	int i;
	for (i=0; i<v; i++)
		visited[i]=0;

	for (i=0; i<v; i++)
	{
		if (!visited[i])
		{			dfs_util (mat,v,i,visited);
			printf ("\n");
		}
	}
}

void enqueue (int i)
{
	q[r++]=i;
}

int dequeue ()
{
	if (f==r)
		return -1;
	return q[f++];
}

void bfs_util (int mat[][arrsize], int v, int visited[])
{
	int next = dequeue ();
	if (next==-1)
		return;
	if (visited[next]==0)
		printf ("%d\n", next+1);
	visited[next]=1;
	int j;
	//push all connected vertices to queue
	for (j=0; j<v;j++)
		if (!visited[j]&&mat[next][j]==1 && next!=j)
			enqueue (j);
	
	bfs_util (mat, v, visited);
}

void bfs (int mat[][arrsize], int v)
{
	int visited[v];
	int i;
	for (i=0; i<v; i++)
		visited[i]=0;
	for (i=0; i<v; i++)
	{
		if (!visited[i])
		{
			enqueue (i);
			bfs_util(mat,v,visited);
			printf ("\n");
		}
	}
}