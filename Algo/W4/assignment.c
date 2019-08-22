#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int perms [100][10];
int k = 0;
void swap (int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void permute (int n[], int l, int r)
{
	if (l==r)
		//perms[k++] = n;
	{
		//memcpy (&perms[k++], &n, (r+1)*sizeof (int));
		for (int j = 0; j<=r; j++)
			perms[k][j]=n[j];
		k++;	
	}
	else
	{
		for (int i = l; i<=r; i++)
		{
			swap (&n[l], &n[i]);
			permute (n, l+1, r);
			swap (&n[l], &n[i]); //undo
		}
	}
}

int main ()
{
	int n, i, j;
	printf ("N: ");
	scanf ("%d", &n);
	printf ("\nEnter cost matrix\n");
	int a[n][n];
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			scanf ("%d", &a[i][j]);
	//generate permutations of 0..n-1 and calculate cost
	int num[n];
	for (i=0; i<n; i++)
		num[i]=i;
	permute (num, 0, n-1);
	int mincost = INT_MAX;
	int cost, opcount=0;
	for (i=0; i<k; i++)
	{
		cost = 0;
		for (j=0; j<n; j++)
		{
			//person j is assigned job perm[j]
			cost+=a[j][perms[i][j]];
		}
		opcount++;
		if (cost<mincost)
			mincost = cost;
	
	}
	printf ("\nMin cost:\t%d\n", mincost);
	printf ("Opcount:\t%d\n", opcount);
}