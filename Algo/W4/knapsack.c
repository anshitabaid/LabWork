#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int knapsack (int w[], int v[], int cap, int n, int mbool[])
{
    int maxval=0, tval, tweight, i, j, temp;
    int tbool[n];
    //generate 2^n subsets
    for (i=0; i<pow (2,n); i++)
    {
        tval=tweight=0;
        temp=i;
        for (j=0; j<n; j++)
        {
            tbool[j]=0;
            if (temp & 0x1)
                //include jth item
            {
                tval+=v[j];
                tweight+=w[j];
                tbool[j]=1; //this item is included
            }
            temp=temp>>1;
        }
        if (tweight <= cap && tval>maxval)
        {
            maxval=tval;
            memcpy (mbool, tbool, n*sizeof (int));
        }
            
    }
    return maxval;
}

int main ()
{
    int n, i, cap;
    printf ("Enter n: ");
    scanf ("%d", &n);
    printf ("Enter capacity: ");
    scanf ("%d", &cap);
    int w[n], v[n];
    printf ("Enter weights\n");
    for (i=0; i<n; i++)
        scanf ("%d", &w[i]);
    printf ("Enter values\n");
    for (i=0; i<n; i++)
        scanf ("%d", &v[i]);
    int mbool[n];
    int result = knapsack (w,v,cap, n, mbool);
    printf ("Items:\n");
    for (i=0; i<n; i++)
        if (mbool[i])
            printf ("%d\t", i+1);
    printf ("\nValue: \t%d\n", result);

}