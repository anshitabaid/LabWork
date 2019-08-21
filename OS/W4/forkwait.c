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
		printf ("I'm the child\n");
		exit (0);
	}
	else
	{
		wait (&status);
		printf ("I'm the parent\n");
		printf ("Child returned: %d\n", status);
	}
}