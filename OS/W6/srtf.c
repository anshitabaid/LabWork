#include "common.h"
#include <limits.h>

void calculate ()
{
	int curtime = 0;
	int i, j, minbt, minpid;
	Pcs curp, tempp;
	int completed[n]; //completed processes
	for (i=0; i<n; i++)
		completed[i]=0;
	/*
	Find process with shortest burst time remaining such that
	1. at <= curtime
	2. bt > 0 or completed[i]=0
	Update remaining burst time at each pass
	*/
	i=0;
	while(1)
	{
		while (completed[i]  && i<n)
			i++;
		if (i==n)
			break;
		Pcs curp = *(p+i);
		minbt = INT_MAX;
		minpid = INT_MAX;
		for (j=i; j<n; j++)
		{
			tempp = *(p+j);
			if (!completed[j] && tempp->bt <= minbt && tempp->at <= curtime)
			{
				minbt = tempp->bt;
				minpid = j;
			}
		}
		curp = *(p+minpid);
		printf ("\nExecuting process %d\n", minpid+1);
		twt=curtime-curp->at;
		curp->wt=twt;
		curtime+=curp->bt;
		ttt=curtime-curp->at;
		completed[minpid]=1;//process completed
		curp->tt=ttt;
		curp->wt=twt;
		att+=ttt;
		awt+=twt;
		printf ("Waiting time\t%d\nTurnaround time %d\n", curp->wt, curp->tt);
	}
	awt/=4;
	att/=4;

}

int main ()
{
	input();

	calculate();
	printf ("Average waiting time\t%0.3f\nAverage turnaround time\t%0.3f\n", awt, att);

}
