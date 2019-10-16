#include <stdio.h>

int framesz;
int pages[100];
int refstr[100];
int n, ptr=-1;
int hit=0, miss=0;

void init ()
{
	printf ("Enter framse size\t");
	scanf ("%d", &framesz);
	printf ("Enter reference string size\t");
	scanf ("%d",&n);
	int i;
	printf ("Enter reference string\n");
	for (i=0; i<n; i++)
		scanf ("%d", &(refstr[i]));
	//initialise frames to -1
	for (i=0; i<framesz; i++)
		pages[i]=-1;
}

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
