#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main ()
{
	pid_t pid;
	char * message;
	int n, status=-1;
	printf ("fork program starting\n");
	pid = fork ();
	switch (pid)
	{
		case -1:
		perror ("fork failed");
		exit (1);
		break;
		case 0:
		message="We are child";
		n=5;
		break;
		default:
		wait (&status);
		message="We are parent";
		n=3; 
		break;
	}
	for (; n>0; n--)
	{
		printf ("%s\t%d\n", message, status);
		sleep (1);
	}
	exit (0);
}