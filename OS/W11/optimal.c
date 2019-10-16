#include "common.h"

int replace (int ind)
{
	int i, j;
	int distances[framesz];
	//find distances of each frame and chose maximum distance to replace
	for (i=0; i<framesz; i++)
	{
		for (j=ind+1; j<n; j++)
			if (refstr[j]==pages[i])
			{
				break;
			}
		distances[i]=j-ind;
	}

	int maxm=distances[0];
	int repl=0;
	for (i=0; i<framesz; i++)
	{
		if (distances[i]>maxm)
		{
			maxm=distances[i];
			repl=i;
		}
	}
	return repl;
}

void doOptimal()
{
	int count=0, ptr=-1;
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
			miss++;
			printf ("Page miss\n");
			//check if page table is full. 
			//If not full we don't need to replace a page
			if (count<framesz)
			{
				count++;//frame added
				pages[++ptr]=refstr[i];
			}
			else
			{
				//replace a page
				//find index in table of the page to replace
				ptr=replace (i);
				pages[ptr]=refstr[i];
			}
		}
		showtable();
	}
}

void main()
{
	init();
	doOptimal();
	printf ("\nPage hits\t\t%d\nPage misses\t\t%d\n", hit, miss);

}


/*
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/