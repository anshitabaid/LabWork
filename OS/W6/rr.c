#include "common.h"
#define q 10

int min (int a, int b)
{
	if (a<b) return a;
	return b;
}
void calculate()
{
	Pcs currp;
	int i,j, minm;
	int currtime=0;
	int completed[n]; //completed processes
	for (i=0; i<n; i++)
		completed[i]=0;
	//sort based on arrival time
	for (i=0; i<n; i++)
	{
		for (j=i; j<n-i-1; j++)
		{
			if ((*(p + i))->at > (*(p+j))->at)
			{
				Pcs temp = *(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
			}
		}
	}

	i=0;
	while (1)
	{
		while (completed[i] && i<n)
			i++;
		if (i==n)
			break;

		for (j=i; j<n ; j++)
		{
			if (completed[j])
				continue;
			currp = *(p+j);
			printf ("\nExecuting process %d\n", currp->pid);
			minm = min (q, currp->bt);
			currp->bt-=minm;
			if (currp->bt==0)
				completed[j]=1;
			//printf ("%d\n", currp->lf);
			currp->wt+=currtime-currp->lf;
			currp->tt=currtime+minm;
			currp->ls=currtime;
			currtime+=minm;
			currp->lf=currtime;

		}
	}
	for (i=0; i<n; i++)
	{
		Pcs c=*(p+i);
		//adjust for arrival times
		c->wt-=c->at;
		c->tt-=c->at; 
		att+=c->tt;
		awt+=c->wt;
	}
	awt/=n;
	att/=n;

}

int main ()
{
	input ();
	calculate ();
	display ();



}