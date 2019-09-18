#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readcount;
int data;
void *  write_func (void * param)
{
	for (int i = 0; i<5; i++)
	{
		sem_wait (&wrt);
		//writing
		printf ("Updated %d\n", data);
		data++;
		sem_post (&wrt);
	}
}

void * read_func (void * param)
{
	for (int i = 0; i<5; i++)
	{
	sem_wait (&mutex);
	readcount++;
	if (readcount==1)
		sem_wait (&wrt);
	sem_post (&mutex);
	printf ("Reading %d\n", data);
	//sleep(1);
	sem_wait (&mutex);
	readcount--;
	if (readcount==0)
		sem_post (&wrt);
	sem_post (&mutex);
	}

}

int main ()
{
	sem_init (&mutex, 0, 1);
	sem_init (&wrt, 0, 1);
	readcount=0;
	data=0;
	pthread_t writerth1, readerth1, writerth2,readerth2;
	pthread_create (&writerth1,0, write_func, 0);
	pthread_create(&readerth1, 0, read_func, 0);
	pthread_create (&writerth2,0, write_func, 0);
	pthread_create(&readerth2, 0, read_func, 0);
	pthread_join (writerth1,0);
	pthread_join (readerth1, 0);
	pthread_join (writerth2,0);
	pthread_join (readerth2, 0);
}