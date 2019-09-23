#include "common.h"
#include <limits.h>

void calculate ()
{
    int currtime = 0;
    //find process with shortest burst time at each iteration, and complete it 
    int i, j;
    int min = INT_MAX, minind;
    int flag;
    int completed[n];
    for (i=0; i<n; i++)
        completed[i]=0;
    for (i=0; i<n; i++)
    {
        flag=0;
        min = INT_MAX;
        for (j=0; j<n; j++)
        {
            Pcs currp = *(p+j);
            if (currp->at<=currtime && !completed[j] && currp->bt <= min)
            {
                flag=1;
                minind = j;
                min=currp->bt;
            }
        }
        //no such process is available, wait and check again
        if (!flag)
        {
            currtime++;
            continue;
        }
        Pcs ex = *(p + minind);
        /*
        for (j=0; j<ex->bt; j++)
            printf ("%d", pid+1);
            */
        printf ("Executing process %d\n", minind+1);
        completed[minind]=1;
        ex->wt=currtime;
        currtime+=ex->bt;
        ex->tt = currtime;
        ttt+=ex->tt;
        twt+=ex->wt;
    }

}

int main ()
{
    input ();
    calculate ();
    display ();
}