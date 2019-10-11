#include <stdio.h>
typedef struct 
{
	int src;
	int dest;
	int wt;	
}edge;

int v, e;
int mat[100][100];
edge edges[100];
void input ()
{

	int a, b, wt;
	printf ("enter v and e\n");
	scanf ("%d%d", &v, &e);
	for (i=1; i<=v; i++)
		for (j=1; j<=v; j++)
			if(i==j)
				mat[i][j]=0;
			else
				mat[i][j]=INF;
	printf ("enter %d edges and weights\n");
	for (i=0; i<e; i++)
	{
		scanf ("%d%d%d", &a, &b, &wt);
		edges[i].src=a;
		edges[i].dest=b;
		edges[i].wt=wt;
	}
}

int main ()
{
	input ();
}