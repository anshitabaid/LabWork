#include <stdio.h>
#include <limits.h>
#define fs 3
int refstr[]={7,0,1,2,0,3,0};
int len=7;
int hit=0, miss=0;
int ptr=0;
int frame[fs]={-1};
int refbits[10]={0};
int present[10]={0};
int presents (int ind)
{
    for (int i=0; i<3; i++)
        if (refstr[ind]==frame[i])
            return 1;
    return 0;
}

void shift (int num)
{
    int i;
    for (i=0; i<10; i++)
        refbits[i]/=2;
    refbits[num]+=128;
    /*
    printf ("\n");
    for (i=0; i<10; i++)
        printf ("%d\n", refbits[i]);
    printf ("\n");
    */
}

int choose ()
{
    int i;
    int minm=INT_MAX, ptr=0;
    for (i=0; i<10; i++)
        if (present[i]==1 && refbits[i]<minm )
        {
            minm=refbits[i];
            ptr=i;
        }
    for (i=0; i<3; i++)
        if (frame[i]==ptr)
            return i;
    return -1;
}

void show ()
{
    for (int i=0; i<3; i++)
    {
        printf ("%d\t", frame[i]);
    }
    printf ("\n");
}

void work ()
{
    int i, j;
    ptr=0;
    for (i=0; i<len; i++)
    {
        shift (refstr[i]);
        if (miss<fs)
        {
            miss++;
            printf ("Miss\n");
            frame[ptr]=refstr[i];
            present[refstr[i]]=1;
            ptr++;
        }
        else
        {
            if (present[refstr[i]]==1)
            {
                printf ("Hit\n");
                hit++;

            }
            else
            {
                miss++;
                printf ("Miss\n");
                ptr=choose();
                present[frame[ptr]]=0;
                frame[ptr]=refstr[i];
                present[refstr[i]]=1;
            }
        }
        show();
    }
}

void main ()
{
    work();

}