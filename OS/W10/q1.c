#include <stdio.h>
#include <string.h>
#include <limits.h>
#define ms 5
#define ps 4
int mem[]={100,500,200,300, 600};
int pcsm [] = {212, 417, 112, 426};
void firstfit()
{
	printf ("First fit\n");
	int memory[ms];
	memcpy(memory, mem, sizeof (int)*ms);
	int i, j, flag;
	for (i=0; i<ps; i++)
	{
		flag=0;
		for (j=0; j<ms; j++)
		{
			if (memory[j]>=pcsm[i])
			{
				printf("Process %d of memory need %d allocated memory %d\n",i, pcsm[i], memory[j] );
				flag=1;
				memory[j]=0;
				break;
			}

		}
		if (!flag)
			printf ("Process %d is not allocated memory\n", i);
	}

}

void bestfit()
{
	printf ("Best fit\n");
	int memory[ms];
	memcpy(memory, mem, sizeof (int)*ms);
	int i, j, minm=INT_MAX, ind;
	for (i=0; i<ps; i++)
	{
		ind=-1;
		minm=INT_MAX;
		for (j=0; j<ms; j++)
		{
			if (memory[j]>=pcsm[i] && memory[j]<minm)
			{
				ind=j;
				minm=memory[j];
			}

		}

		if (ind==-1)
		{
			printf ("Process %d is not allocated memory\n", i);
		}
		else
		{
			printf ("Process %d of memory need %d allocated memory %d\n", i, pcsm[i], memory[ind]);
			memory[ind]=0;
		}
	}

}

void worstfit()
{
	printf ("Worst fit\n");
	int memory[ms];
	memcpy(memory, mem, sizeof (int)*ms);
	int i, j, maxm, ind;
	for (i=0; i<ps; i++)
	{
		ind=-1;
		maxm=INT_MIN;
		for (j=0; j<ms; j++)
		{
			if (memory[j]>=pcsm[i] && memory[j]>=maxm)
			{
				ind=j;
				maxm=memory[j];
			}

		}

		if (ind==-1)
		{
			printf ("Process %d is not allocated memory\n", i);
		}
		else
		{
			printf ("Process %d of memory need %d allocated memory %d\n", i, pcsm[i], memory[ind]);
			memory[ind]=0;
		}
	}

}


int main ()
{
	firstfit();
	bestfit();
	worstfit();

}