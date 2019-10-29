#include <stdio.h>
#include <string.h>

int compare (int a1[], int a2[], int n)
{
    int i;
    for (i=0; i<n; i++)
        if (a1[i]<a2[i])
            return -1;
        if (a1[i]>a2[i])
            return 1;
    return 0;
}

void add (int a1[], int a2[], int n)
{
    int i;
    for (i=0; i<n; i++)
        a1[i]+=a2[i];
}

void subtract (int a1[], int a2[], int n)
{
    for (int i =0; i<n; i++)
        a1[i]-=a2[i];
}
void zero (int arr[], int n)
{
    for (int i =0; i<n; i++)
        arr[i]=0;
}
int bankersDA (int n, int m, int available[], int allocation[][10], int need[][10])
{
    int work[m];
    memcpy (work, available, m); //work=available
    int finish[n];
    zero (finish, n);
    int flag, i;
    do
    {   
        flag=0;
        for (i=0; i<n; i++)
        {
            if (finish[i]==0 && compare (need[i], work,m)<0)
            {
                add (work, allocation[i], m);
                zero (allocation[i], m);
                //allocation[i]={0};
                finish[i]=1;
                flag=1;
            }

        }
        if (flag==0)
            break;
    }while (1);

    for (i=0; i<n; i++)
        if (finish[i]==0)
        {
            //not safe
            return 0;
        }
    return 1;
}

void input (int n, int m, int available[], int allocation[][10], int max[][10], int need[][10])
{
    int i, j;
    printf ("Enter available\n");
    for (i=0; i<m; i++)
        scanf ("%d", &available[i]);
    printf ("Enter max\n");
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf ("%d", &max[i][j]);
    printf ("Enter allocation\n");
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf ("%d", &allocation[i][j]);
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            need[i][j]=max[i][j]-allocation[i][j];
}

void resource_request (int n, int m, int available[], int allocation[][10], int need[][10])
{
    int p, request[m], i;
    printf ("Enter requesting process\n");
    scanf ("%d", &p);
    printf ("Enter request\n");
    for (i=0; i<m; i++)
        scanf ("%d", &request[i]);
    if (compare (request, need[i], m)>1)
    {
        printf ("Error\n");
        return;
    }
    if (compare (request, available, m)>1)
    {
        printf ("Cant be allocated\n");
        return;
    }
    add (allocation[i], request, m);
    subtract (available, request, m);
    subtract (need[i], request, m);
    int fl = bankersDA (n,m, available, allocation, need);
    if (fl==0)
    {
        //unsafe
        //undo changes
        printf ("Not safe, undoing\n");
        add (need[i], request, m);
        add (available, request, m);
        subtract(allocation[i], request, m);
    }
    else
        printf ("Safe and allocated\n");

}

void main ()
{
    int n, m;
    printf ("No of processed and type of resources ?\n");
    scanf ("%d%d", &n, &m);
    int available[m], allocation[n][m], max[n][m], need[n][m];
    input (n, m , available, allocation, max, need);
    int fl = bankersDA(n,m,available, allocation, need);
    if (fl==0)
        printf ("Not safe\n");
    else
        printf ("Safe\n");
    resource_request (n, m, available, allocation, need);
    resource_request (n, m, available, allocation, need);


}
/*
5
3
3 3 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
*/