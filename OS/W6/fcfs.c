#include "common.h"

void calculate ()
{
	int i,j;
	int currtime=0;
	int twt, ttt; //temp waiting time and turnaround time
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
	for (i=0; i<n; i++)
	{
		Pcs curp = *(p+i); //current process to execute
		printf ("Executing process ID %d\n\n", curp->pid);
		twt =currtime- curp->at;
		currtime+=curp->bt;
		ttt = currtime - curp->at;
		curp->tt=twt;
		curp->wt=twt;

		printf ("Waiting time\t%d\nTurnaround time%d\n", curp->wt, curp->tt);
		awt+=twt;
		att+=ttt;
	}
	awt/=n;
	att/=n;
}

int main ()
{
	input();

	calculate ();
	
	printf ("Average waiting time\t%0.3f\nAverage turnaround time\t%0.3f\n", awt, att);


}
