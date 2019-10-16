#include <stdio.h>
int framesz;
int pages[100];
int refstr[100];
int n, ptr=-1;
int hit=0, miss=0;

void showtable ()
{
	printf ("Frames\t");
	for (int i=0; i<framesz; i++)
		printf ("%d\t", pages[i]);
	printf ("\n\n");
}

int lookup(int ref)
{
	for (int i=0; i<framesz; i++)
		if (pages[i]==ref)
			return 1;
	return 0;
}

void dofifo()
{
	int i, j;
	for (i=0; i<n; i++)
	{
		printf ("%d\n", refstr[i]);
		if (lookup(refstr[i])==1)
		{
			hit++;
			printf ("Page hit\n");
		}

		else
		{
			ptr=(ptr+1)%framesz;
			pages[ptr]=refstr[i];
			miss++;
			printf ("Page miss\n");
		}
		showtable();
	}

}

void init ()
{
	printf ("Enter framse size\t");
	scanf ("%d", &framesz);
	printf ("Enter n\t");
	scanf ("%d",&n);
	int i;
	printf ("Enter reference string\n");
	for (i=0; i<n; i++)
		scanf ("%d", &(refstr[i]));
	//initialise frames to -1
	for (i=0; i<framesz; i++)
		pages[i]=-1;
}

int main ()
{
	init();
	dofifo();
	printf ("\nPage hits\t\t%d\nPage misses\t\t%d\n", hit, miss);

}

/*
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/