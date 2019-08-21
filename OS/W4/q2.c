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
		printf ("Q2 child\n");
		int status = execl ("./q1", "q1", NULL);
		if (status == -1)
		{
			perror ("Error");
			exit (1);
		}
		exit (0);
	}
	else
	{
		wait (&status);
		printf ("Q2 parent\n");
		printf ("Q2 Child returned: %d\n", status);
	}
}