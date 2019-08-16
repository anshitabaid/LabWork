#include <stdio.h>
#include <stdlib.h>

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

int ** initMatrix (int v)
{
	int i, j;
	int ** mat = (int**)calloc (v, sizeof (int *));
	for (i=0; i<v; i++)
	{
		*(mat+i) = (int*)calloc (v, sizeof (int));
		for (j=0; j<v; j++)
			*(*(mat+i)+j)=0;
		*(*(mat+i)+i)=1; //self connection
	}
	return mat;

}

void insertToList(AdjList a, int d)
{
	AdjListNode temp = a->head;
	while (temp->next)
		temp=temp->next;
	temp->next = newAdjListNode (d);
}

void insertToMatrix (int ** mat, int i, int j)
{
	*(*(mat+i)+j) = 1;
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
				//insertToMatrix (mat, i, vertex-1);
			}

		}while (vertex!=0);
	}
}
/*
void makeListAndMatrix (Graph g, int ** mat, int v)
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
				insertToMatrix (mat, i, vertex-1);
			}

		}while (vertex!=0);
	}
}

*/
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
void printAdjMat (int ** mat, int v)
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
			int d = *(*(mat+i)+j);
			printf ("%d\t", d);
		}
		printf ("\n");
	}

}

