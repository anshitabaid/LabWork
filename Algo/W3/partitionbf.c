#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	int isFirstFound = 0;
	int temp[10];
	int n, i, j, k, sum=0, size, count, s;
	int a [10];
	printf ("Enter n < 10\n");
	scanf ("%d", &n);
	for (i=0; i<n; i++)
		scanf ("%d", a+i);
	//find sum
	for (i=0; i<n; i++)	sum+=a[i];
	if (sum%2!=0)
	{
		printf ("\nNo soln\n");
		return 0;
	}
	sum/=2; //find subsets of this sum
	size=pow(2, n);
	for (i=0; i<size; i++)
	{
		s=0;
		k=0;
		for (j=0; j<n; j++)
		{
		printf ("%d",i & (1<<j));
		if (i & (1<<j)>0)
		{
			printf ("%d\t", a[j]);
			s+=a[j];
			printf ("%d\n", s);
			temp[k++]=a[j];
		}

	}
		/*
		if (s==sum)
		{
			if (isFirstFound==0)
			{	
				s1=sb;
				isFirstFound = 1;
			}
			else
			{
				s2=sb;
				break;
			}
		}
		*/
		printf ("%d\n", s);
		if (s==sum)
		{
			count++;
			for (i=0; i<k; i++)
				printf ("%d\t", temp[i]);
			printf ("\n");
		}
		
	}
	if (count==0)
		printf ("No solution exists");
	/*
	for (i=0; i<s1->n; i++)
		printf ("%d\t", s1->s[i]);
	printf ("\n");
	for (i=0; i<s2->n; i++)
		printf ("%d\t", s2->s[i]);
		*/
}