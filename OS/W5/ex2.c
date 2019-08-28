#include <pthread.h>
#include <stdio.h>

void * child_thread (void * param)
{
	int id = (int) param;
	printf ("Start thread %d\n", id);
	return (void * ) id;
}

int main ()
{
	pthread_t thread [10];
	int return_value [10];
	int i;
	for (i=1; i<11; i++)
		pthread_create (&thread[i], 0, &child_thread, (void *)i);

	for (i=1; i<11; i++)
	{
		pthread_join (thread[i], (void **)&return_value[i]);
		printf ("End thread %i\n", return_value[i]);
	}
	printf ("Ending main thread\n");	
}
