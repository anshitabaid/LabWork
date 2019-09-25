
#include <string.h>
#include <stdio.h>
#include "Bankers.h"
void add (int * dest, int *a, int*b, int size)
{
	int i;
	for (i=0; i<size; i++)
		dest[i]=a[i]+b[i];
}
int safetyAlgo (BankersDs ds, int m, int n)
{
	int work[m];
	int finish[n];
	int equal=1, deadlock=0,i, j;
	memcpy (work, ds->available, sizeof (work));
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			if (ds->allocation[j]!=0)
			{
				equal=0; 
				break;
			}
		if (equal)
			finish[i]=0;
		else
			finish[i]=1;
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{	
			if (finish[j]==0 && memcmp (ds->need[j], work, sizeof (work))<=0)
			{
				add(work, work, ds->allocation[j], sizeof(m));
				finish[j]=1;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		if (finish[i]==0)
			return i;
	}
	return -1;
}

void display (int ** arr, int m, int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
			printf ("%d\t", arr[i][j]);
		printf ("\n");
	}
}

int main ()
{
	int n, m, i, j;
	printf ("Enter n, m");
	scanf ("%d %d", &n, &m);
	BankersDs ds= init (n, m);
	for (i=0; i<n; i++)
	{
		printf ("%d\n", i);
		for (j=0; j<m; j++)
			scanf("%d", &(ds->allocation[i][j]));
		for (j=0; j<m; j++)
			scanf ("%d", &(ds->max[i][j]));
		for (j=0; j<m; j++)
			ds->need[i][j]=ds->max[i][j]-ds->allocation[i][j];

	}
	//available
	for (i=0; i<m; i++)
		scanf ("%d", &(ds->available[i]));
	printf ("Need matrix");
	//display (ds->need, n, m);
	//printf("%d", safetyAlgo(ds, m, n));
}
// 0 1 0 7 5 3 2 0 0 3 2 2 3 0 2 9 0 2 2 1 1 2 2 2 0 0 2 4 3 3 3 3 2