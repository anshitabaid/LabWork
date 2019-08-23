#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int globmval = INT_MIN;

int max (int a, int b)
{
	if (a>b) return a;
	return b;
}

int knap_recur (int wts[], int vals[], int ind, int n, int cap)
{
	if (ind==pow (2, n))
		return INT_MIN;
	int mval=0;
	int i, j, temp, twt;
	temp=ind;
	twt=0;

	for (i=0; i<n; i++)
	{
		if (temp & 0x1==1)
		{
			//include jth item
			twt+=wts[i];
			mval+=vals[i];
		}
		temp=temp>>1;
	}
	if (twt<=cap && mval >globmval)
		globmval = mval;
	if (twt>cap)
		return  knap_recur (wts, vals, ind+1,n, cap);
	else
		return max (globmval, knap_recur (wts, vals, ind+1, n, cap));
	
}

int main ()
{
	
	int n, i, j, cap, res;
	printf ("Enter no of items\t");
	scanf ("%d", &n);
	int val[n], wt[n];
	printf ("Values \n");
	for (i=0; i<n; i++)
		scanf ("%d", &val[i]);
	printf ("Weights \n");
	for (i=0; i<n; i++)
		scanf ("%d", &wt[i]);

	printf ("Capacity\t");
	scanf ("%d", &cap);
	res = knap_recur (wt, val, 0, n, cap );
	if (res==INT_MIN)
		printf ("No solution\n");
	else printf ("Result %d\n", res);
}