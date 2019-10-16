#include "common.h"

int refbits[100];
int bits[100];
int replace (int ind)
{
	while (1)
	{
		ptr=(ptr+1)%framesz;
		if (refbits[pages[ptr]]==0)
			return ptr; //replace this page
		else
			refbits[pages[ptr]]==0; //give second chance
			
	}
	return -1; //unreachable
}

void doSecondChance ()
{
	int i, j, count=0;
	ptr=-1;
	for (i=0; i<n; i++)
	{
		printf ("%d\n", refstr[i]);
		//refbits[refstr[i]]==0 or 1 then that means the page is in the table
		//else it is -1
		if (refbits[refstr[i]]!=-1)
		{
			hit++;
			printf ("Page hit\n");
		}
		else
		{
			miss++;
			printf ("Page miss\n");
			if (count<framesz)
			{
				count++;
				refbits[refstr[i]=0];
				pages[++ptr]=refstr[i];
			}
			else
			{
				ptr=replace (i);
				refbits[pages[ptr]]=-1; //removing this page
				refbits[refstr[i]]=bits[i]; //adding this page
				pages[ptr]=refstr[i];
			}
		}
		showtable();
	}
}

int main ()
{
	int i;
	for (i=0; i<framesz; i++)
		refbits[i]=-1;
	init();
	printf ("Enter reference bits\n");
	for (i=0; i<n; i++)
	{
		scanf ("%d", &refbits[i]);
	}
	doSecondChance();
	printf ("\nPage hits\t\t%d\nPage misses\t\t%d\n", hit, miss);

}
/*
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
0 1 1 1 0 1 0 0 1 0 0 1 0 1 0 1 0 0 1 0
*/