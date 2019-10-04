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

int main ()
{
	input ();

}