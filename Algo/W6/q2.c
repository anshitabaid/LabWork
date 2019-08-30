#include <stdio.h>
int opcount=0;
int swap (int arr[], int i, int j)
{
	int t = arr[i];
	arr[i]=arr[j];
	arr[j]=t;
}

int partition (int arr[], int l, int r)
{
	int i, j, pivot;
	pivot = arr[r];
	i = l-1;
	for (j=l; j<r; j++)
	{
		opcount++;
		if (arr[j]<pivot)
		{
			i++;
			swap (arr, i, j);
		}
	}
	swap (arr, i+1, r);
	return i+1;
}

void quickSort (int arr[], int l, int r)
{
	if (l<r)
	{
		int pi = partition (arr, l, r);
		quickSort (arr, l, pi-1);
		quickSort (arr, pi+1, r);
	}
}

int main ()
{
	int n;
	scanf ("%d", &n);
	int arr[n];
	for (int i=0; i<n; i++)
		scanf ("%d", &arr[i]);
	quickSort (arr, 0, n-1);
	for (int i =0; i<n; i++)
		printf ("%d\t", arr[i]);
	printf ("\nOpcount:\t%d\n", opcount);
}