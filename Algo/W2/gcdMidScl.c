#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define maxm 1024
typedef struct factorization
{
	int factors [maxm+1];
	int exponent[maxm+1];
	int size;
}*Factors;


Factors findFactorization (int n)
{
	Factors f = (Factors)malloc (sizeof (struct factorization));
	f->factors[0]=1;
	f->exponent[0]=1;
	int i, c, k=1;
	for (i=2; i<=n; i++)
	{
		c=0;
		while (n%i==0)
		{
			c++;
			n/=i;
		}
		if (c>0)
		{
			f->factors[k]=i;
			f->exponent[k]=c;
			k++;
		}
	}
	f->size=k;
}
int min (int a, int b)
{
	if (a<b) return a;
	return b;
}

int findGCD (Factors mf, Factors nf)
{
	int gcd=1;
	int i=0, j=0;
	int opcount=0;
	while (i<mf->size)
	{
		j=1;
		while (j<nf->size)
		{
			opcount++;
			if (nf->factors[j]==mf->factors[i])
			{

				gcd *= pow (nf->factors[j],min (mf->exponent[i], nf->exponent[j]));
				break;
			}
			j++;
		}
		i++;
	}
	printf ("OPCOUNT: %d\n", opcount);
	return gcd;
}


int main ()
{
	int m,n;
	scanf ("%d", &m);
	scanf ("%d", &n);
	Factors f1 = findFactorization(m);
	Factors f2 = findFactorization (n);
	int gcd = findGCD(f1, f2);
	printf ("%d\n", gcd);
}