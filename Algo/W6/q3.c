#include <stdio.h>
int opcount = 0;
void merge (int arr[], int l, int m, int r)
{
	//one array in a[l..m]
	//other is a[m+1.. r]
	//final array is arr[l..r]
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;

	int a[n1], b[n2];

	for (i=0; i<n1; i++)
		a[i]=arr[l+i];
	for (i=0; i<n2; i++)
		b[i]=arr[m+1+i];

	i=0; j=0; k=l;
	while (i<n1 && j<n2)
	{
		opcount++;
		if (a[i]<=b[j])
		{
			arr[k]=a[i];
			i++;
		}
		else //(b[j]<a[i])
		{
			arr[k]=b[j];
			j++;
		}
		/*
		else //equal
		{
			arr[k]=a[i];
			i++; 
			j++;
		}
		*/
		k++;
	}
	while (i<n1)
		arr[k++]=a[i++];
	while (j<n2)
		arr[k++]=b[j++];
}

void mergeSort (int arr[], int l, int r)
{
	if (l<r)
	{
		int m = (l+r)/2;
		mergeSort (arr, l, m);
		mergeSort (arr, m+1, r);
		merge (arr, l, m, r);
	}
}

int main ()
{
	int n, i;
	scanf ("%d", &n);
	int arr [n];
	for (i=0; i<n; i++)
		scanf ("%d", &arr[i]);
	mergeSort (arr, 0, n-1);
	for (i =0; i<n; i++)
		printf ("%d\t", arr[i]);
	printf ("\nOpcount:\t%d\n", opcount);
}