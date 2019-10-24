#include <stdio.h>
int n, s;

int subsetSum(int sumsf /*sum so far */, int ind, int arr[])
{
    sumsf+=arr[ind];
    if (sumsf==s)
    {
        return 1;
    }
    else if (sumsf>s)
        return 0;
    int i;
    for (i=ind+1; i<n; i++)
        if (subsetSum(sumsf, i, arr)==1)
        {
            printf ("%d\t", arr[i]);
            return 1;
        }
    return 0;
}

int main ()
{
    int i;
    printf ("Enter n\n");
    scanf ("%d", &n);
    int arr[n];
    printf ("Enter %d numbers\n", n);
    for (i=0; i<n; i++)
        scanf ("%d", &arr[i]);
    printf ("Enter sum\n");
    scanf ("%d", &s);
    for (i=0; i<n; i++)
    if (subsetSum(0, i, arr)==1)
    {
        flag=1;
        break;
    }
    if (flag)
        printf ("Solution exists\n");
    else
        printf ("No solution\n");
}
/*
6
3 34 4 12 5 2
9
*/