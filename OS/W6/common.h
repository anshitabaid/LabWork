#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
	int pid;
	int at; //arrival time
	int bt; //burst time
	int pr; //priority
	int wt; //waiting time
	int tt; //turnaround time
	int ls; //last started for RR
	int lf; //last finished
} pcs, *Pcs;

Pcs * p;
int n; //no of pcs
float awt=0; //avg waiting time
float att = 0; //avg turnaround time
int ttt, twt; //temporary TT and WT

void input ()
{
	printf ("Number of processes:\t");
	scanf ("%d", &n);
	p = (Pcs *)calloc (n, sizeof (Pcs)); 
	int i;
	for (i=0; i<n; i++)
	{
		*(p+i)=(Pcs)malloc (sizeof (pcs));
		Pcs pt = *(p+i);
		pt->pid=i+1;
		scanf ("%d", &(pt->at));
		scanf ("%d", &(pt->bt));
		scanf ("%d", &(pt->pr));
		pt->tt=0;
		pt->wt=0;
		pt->ls=0;
		pt->lf=0;
		/*
		printf ("Arrival time\t");
		scanf ("%d", &(pt->at));
		printf ("Burst time\t");
		scanf ("%d", &(pt->bt));
		printf ("Priority\t");
		scanf ("%d", &(pt->pr));
		*/
	}
}

void display ()
{
	int i;
	printf ("Process\tWaiting Time\tTurnaround Time\n");
	for (i=0; i<n; i++)
	{
		Pcs c=*(p+i);
		//adjust for arrival times
		c->wt-=c->at;
		c->tt-=c->at; 
		att+=c->tt;
		awt+=c->wt;
		printf ("%d\t\t%d\t\t%d\n", c->pid, c->wt, c->tt);
	}
	awt/=n;
	att/=n;
	printf ("Average waiting time\t%0.3f\nAverage turnaround time\t%0.3f\n", awt, att);


}
//0 60 3 3 30 2 4 40 1 9 10 4