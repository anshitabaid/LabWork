#include <stdio.h>
#include <limits.h>
#include <string.h>
int permutations[10][20];
int k=0;

void swap (int arr[], int i, int j)
{
    int t = arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

void permute (int arr[], int l, int r)
{
    if (l==r)
    {
        memcpy (permutations[k++], arr, (r+1)*sizeof (int));
    }
    else
    {
        for (int i=l; i<=r; i++)
        {
            swap (arr, i, l);
            permute (arr, l+1, r);
            swap (arr, i, l);
        }

    }

}

int main ()
{
    int n, i, j;
    printf ("No of nodes: "); 
    scanf ("%d", &n);
    int m[n][n];
    printf ("Enter cost matrix \n");
    for (i=0;i<n; i++)
        for (j=0; j<n; j++)
            scanf ("%d", &m[i][j]);

    int arr[n];
    for (i=0; i<n; i++)
        arr[i]=i+1;
    permute (arr, 1, n-1);

    //permutations found
    int mincost=INT_MAX;
    int tcost=0;
    int minindex=0;
    int a,b;
    for (i=0; i<k; i++)
    {
        tcost=0;
        for (j=1; j<n; j++)
        {
            a=permutations[i][j-1];
            b=permutations[i][j];
            tcost+=m[a-1][b-1];
        }
        //from last node back to node 1 aka starting node
        a=permutations[i][n-1];
        b=1;
        tcost+=m[a-1][b-1];
        if (tcost<mincost)
        {
            mincost=tcost;
            minindex=i;
        }
    }
    printf ("Min cost:\t%d\n", mincost);
    for (i=0; i<n; i++)
        printf ("%d\t", permutations[minindex][i]);
    printf ("1\n");
}