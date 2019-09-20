
#include <stdio.h>
int opc1=0, opc2;
void heapify (int heap[], int n)
{
	int isHeap, i, j, k, v;
	for (i=n/2; i>=1; i--)
	{
		v=heap[i];
		isHeap=0;
		k=i;
		while (!isHeap && 2*k<=n)
		{
			j=2*k; //children
			if (j<n)
				//there is another child
				if (heap[j+1]>heap[j])
					j++;
			if (v>=heap[j])
			{
				opc2++;
				isHeap=1;
			}
			else
			{
				heap[k]=heap[j];
				k=j;
			}
		}
		heap[k]=v;

	}
}
void display (int heap[], int n)
{
	int i;
	for (i=1; i<=n; i++)
		printf ("%d\t", heap[i]);
	printf ("\n");
}



void heapSort (int heap[], int n)
{
	int i;
	for (i=n; i>1; i--)
	{
		opc1++;
		//swap root and last leaf
		int t = heap[1];
		heap[1]=heap[i];
		heap[i]=t;
		//decrease size by one
		n--;
		//heapify
		heapify (heap, n);

	}
}



int main ()
{
	int n, i;
	scanf ("%d", &n);
	int heap[n+1];
	for (i=1; i<=n; i++)
		scanf ("%d", &heap[i]);
	heapify (heap, n);
	heapSort (heap, n);
	display (heap, n);
	printf ("Opcount:\t%d\n", opc1*opc2);
}
/*
6
2
9
7
6
5
8
*/