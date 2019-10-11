#include <stdio.h>
#include <limits.h>
#define INF 99999
int v, e;
int mat[100][100];
int set[100];
int distance[100];
void input ()
{
	int i, j, a, b, wt;
	printf ("Enter v, e\n");
	scanf ("%d%d", &v, &e);
	for (i=1; i<=v; i++)
	{
		for (j=1; j<=v; j++)
		{
			if(i==j)
			{

				mat[i][j]=0;
			}
			else
			{
				mat[i][j]=INF;
			}
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

//find vertix not in set with minm distance value
int pick()
{
	int i, minm=INT_MAX, u;
	for (i=1; i<=v; i++)
	{
		if (distance[i]<=minm && set[i]!=1)
		{
			minm=distance[i];
			u=i;
		}

	}
	return u;
}

void dijkstra ()
{
	int i, j, u;
	int count=0; //track no of vertices in set
	//set is empty
	for (i=1; i<=v;i++)
		set[i]=0;
	//distances are INF
	for (i=1; i<=v; i++)
		distance[i]=INF;
	//to start from first vertex
	distance[1]=0;
	while (count<v)
	{
		u=pick();
		//add u to set
		set[u]=1;
		//update distance of all vertices next to u
		for (i=1; i<=v; i++)
			if (mat[u][i]>0 && i!=u  && distance[u]!=INF)
			{
				//printf ("%d\n", i);
				if (distance[u]+mat[u][i]<distance[i])
					distance[i]=distance[u]+mat[u][i];
			}
		count++;
	}

}

void display()
{
	int i;
	printf ("Vertex\t\tDistance from source\n");
	for (i=1; i<=v; i++)
		printf ("%d\t\t%d\t\t\n", i, distance[i]);
}

int main ()
{
	
	input();

	for (int i=1; i<=v; i++)
	{
		for (int j=1; j<=v; j++)
			printf ("%d\t", mat[i][j]);
		printf ("\n");
	}
	dijkstra();
	display();
}

/*
6
9
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 6 2
3 4 11
4 5 6
5 6 9
*/