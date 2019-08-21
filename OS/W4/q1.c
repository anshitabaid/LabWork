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
		printf ("Q1 child\n");
		exit (0);
	}
	else
	{
		wait (&status);
		printf ("Q1 parent\n");
		printf ("Q1 Child returned: %d\n", status);
	}
}