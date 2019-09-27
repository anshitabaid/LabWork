#include <stdio.h>

int horspool (char T[], int n, char P[], int m)
{
	//construct shift table
	int i, j;
	int shift[26];
	for (i=0; i<26; i++)
		shift[i]=m;
	for (i=0; i<m-1; i++)
		shift[P[i]-97]=m-i-1;
	//printf ("%s", P);
	for (i=0; i<26; i++)
		printf ("%d\t", shift[i]);
	j=0;
	/*
	while (j+m<=n)
	{
		if (P[m-1]==T[j+m-1])
		{
			//compare the rest in brute force manner
			i=m-2;
			while (i>=0 && P[i]==T[i+j])
				i--;
			if (i==-1)
				return j;
		}
		j+=shift[T[j+m-1]];
	}
	*/
	return -1;
}

int main ()
{
	int n, m;
	printf ("Text length:\t");
	scanf ("%d", &n);
	printf ("Pattern length:\t");
	scanf ("%d", &m);
	char P[m], T[n];
	printf ("Enter text:\t");
	scanf ("%s", T);
	printf ("Enter pattern:\t");
	scanf ("%s", P);
	int res=horspool(T,n, P, m);
	printf ("Found at %d\n", res);
}

/*
ainaisestiainainen
ainainen
*/