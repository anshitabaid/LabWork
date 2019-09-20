/*
Insert element to last position in heap
compare with its parent, and exhange them if it violates the parental domincance
Continue comparing the new element with nodes up the tree until parent dominance satisfied
*/

#include <stdio.h>
int opcount=0;
void topDownConstruct (int heap[], int n, int i)
{
	int parent, v, k;
	int isHeap=0;
	isHeap=0;
	v=heap[i];
	k=i;
	while (!isHeap && k/2>=1)
	{
		parent = k/2; //parent of node k at floor (k/2)
		if (v<heap[parent]) //parental dominance in maxheap satisfied
		{
			isHeap=1;
			opcount++;
		}
		else
		{
			heap[k]=heap[parent];
			k=parent;
		}
	}
	heap[k]=v;
}


void display (int heap[], int n)
{
	int i;
	for (i=1; i<=n; i++)
		printf ("%d\t", heap[i]);
	printf ("\n");
}


int main ()
{
	int n, i;
	scanf ("%d", &n);
	int heap[n+1];
	for (i=1; i<=n; i++)
	{
		scanf ("%d", &heap[i]);
		topDownConstruct (heap, n, i);
		display (heap, i);
	}
	display (heap, n);
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