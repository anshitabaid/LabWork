#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct sum{
	int n;
	int arr[20];
}* Sum;

void * gen_sum (void * param)
{
	Sum f = (Sum) param;
	int i;
	int s = 0;
	for (i=0; i<f->n; i++)
		if (f->arr[i]>=0)
			s+=f->arr[i];
	return (void *)s;
}

int main ()
{
	pthread_t thread;
	up
	int n, i, s;
	printf ("Enter n\t");
	scanf ("%d", &n);
	Sum f = (Sum) malloc (sizeof (struct sum));
	f->n=n;
	printf ("Enter n numbers\n");
	for (i=0; i<n; i++)
		scanf ("%d", &f->arr[i]);
	pthread_create (&thread, 0, &gen_sum, (void *)f);
	pthread_join (thread, (void **) &s);
	printf ("Sum = %d \n", s);
}