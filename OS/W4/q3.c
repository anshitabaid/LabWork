#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void main ()
{
	int status;
	pid_t pid;
	pid = fork();
	if (pid==-1)
		printf ("\nERROR Child not created");
	else if (pid==0)
	{
		printf ("Q3 child\t%d\n", getpid());
		exit (0);
	}
	else
	{
		//wait (NULL);
		printf ("Q3 parent PID\t%d\n", getpid());
	}
}