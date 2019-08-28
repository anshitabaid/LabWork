#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct fibo{
	int n;
	int arr[20];
}* Fibo;

void * gen_fibo (void * param)
{
	Fibo f = (Fibo) param;
	int f0, f1, f2;
	f0=0;
	f1=1;
	f->arr[0]=0; f->arr[1]=1;
	int counter = 2;
	while (counter<=(f->n))
	{
		f2=f0+f1;
		f->arr[counter++]=f2;
		f0=f1;
		f1=f2;
	}
	return (void *)f;
}

int main ()
{
	pthread_t thread;
	int n;
	printf ("Enter n\t");
	scanf ("%d", &n);
	Fibo f = (Fibo) malloc (sizeof (struct fibo));
	f->n=n;
	pthread_create (&thread, 0, &gen_fibo, (void *)f);
	pthread_join (thread, (void **) &f);
	for (int i=0; i<f->n; i++)
		printf ("%d\t", f->arr[i]);
}