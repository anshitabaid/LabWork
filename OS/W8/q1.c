#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5
sem_t semaphore;
int consumedcount=0;

int buf[100], f, r;
sem_t mutex, full, empty;

void * produce (void * arg)
{
	int i;
	for (i=0; i<10; i++)
	{
		sem_wait (&empty);
		sem_wait(&mutex);
		printf ("Produced item is %d\n", i);
		buf[(++r)%(consumedcount+10)]=i;
		sleep(1);
		sem_post (&mutex);
		sem_post (&full);
		printf ("full %u\n", full);
	}
}

void * consume (void * arg)
{
	int item, i;
	for (i=0; i<10; i++)
	{
		sem_wait (&full);
		printf ("full %u\n", full);
		sem_wait (&mutex);
		item=buf [(++f)%N];
		consumedcount++;
		printf ("Consumed item is %d\n", item);
		sleep (1);
		sem_post (&mutex);
		sem_post (&empty);
	}
}

int main ()
{
	pthread_t tid1, tid2;
	sem_init (&mutex, 0, 1);
	sem_init (&full, 0, 0);
	sem_init (&empty, 0, N);

	pthread_create (&tid1,NULL, produce,NULL);
	pthread_create (&tid2,NULL,consume, NULL);
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);
}