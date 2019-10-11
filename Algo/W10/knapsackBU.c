#include <stdio.h>
#include <stdlib.h>
#define sz 100
int w, n;
int wt[SZ], val[SZ];
input ()
{
	printf ("Enter W and N:\t");
	scanf ("%d%d", &w, &n);
	int i;
	printf ("Enter weight and values");
	for (i=0; i<n; i++)
		scanf ("%d%d", &wt[i], &val[i]);

}

int max (int a, int b)
{
	if (a>b)
		return a;
	return b;
}

int knapsack (int mat[n+1][w+1], int i, int j)
{	
	if (j-wt[i]>=0)
		mat[i][j]=max (knapmat[i-1][j], val[i]+mat[i-1][j-wt[i]]);
	else
		mat[i][j]=
}

int main ()
{
	input ();
	int d[n+1][w+1];
	int i, j;
	for (i=0;i<=n; i++)
		for (j=0; j<=w; j++)
			d[i][j]=0;
	knapsack (d, n, w);


}