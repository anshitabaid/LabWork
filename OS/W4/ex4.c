#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
	pid_t pid;
	pid=fork();
	if (pid<0)
	{
		fprintf (stderr, "Fork failed\n");
		exit (-1);
	}
	else if (pid==0) //child
	{
		execlp ("ls", "ls", NULL);
	}
	else //parent
	{
		wait (NULL);
		printf ("Child complete\n");
		exit (0);
	}
}