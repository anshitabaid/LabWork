#include "common.h"
#include <limits.h>
void calculate ()
{
    /*
    check at every second if a process arrived whose priority is greater than current process.
    If so, preempt current process
    Else, dont preempt
    */
    int currtime=0, i, flag;
    int completed[n];
    for (i=0; i<n; i++)
        completed[i]=0;
    int pri;
    int minind=0;
    int prev=-1;
    do
    {
        i=0;
        while (completed[i]  && i<n)
            i++;
        if (i==n)
            break;
        pri=INT_MAX;
        //chectk if process arrived has a higher priority (lower number)
        for (i=0; i<n; i++)
        {
            Pcs curp=*(p+i);
            if (!completed[i] && curp->at <=currtime && curp->pr <= pri)
            {
                pri=curp->pr;
                minind=i;
            }
        }
        Pcs ex = *(p+minind);
        printf ("Executing process %d\n", minind+1);
        if (!(ex->pid==prev))
            //context switch
            ex->wt=currtime;

        ex->bt-=1;
        if (ex->bt==0)
        {
            completed[minind]=1;
            ex->tt=currtime+1;
        }
        currtime++;
        prev=ex->pid;


    }while (1);

}

int main ()
{
    input();
    calculate();
    display();
}

//0 6 3 3 3 2 4 4 1 9 1 4