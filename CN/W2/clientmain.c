#include "serverclient.h"
#include <stdio.h>
#include <stdlib.h>

void clientWorker(int sockfd)
{
	while (1)
	{
	int n;
	char ch [256], buf [256];
	printf ("Enter string: ");
	fgets (ch, 256, stdin);
	//printf ("\n%d\n", strlen (ch));
	ch[strlen (ch)] = '\0';
	write (sockfd, ch, strlen (ch));
	printf ("\nString sent back from server: ");
	n = read (sockfd, buf, sizeof (buf));
	puts (buf);
	}

}

int main ()
{
	struct sockaddr_in cliaddr;
	int sockfd;
	cliaddr = createClientSocket ( &sockfd);
		//connect to server
	/*
	int result = connect (sockfd, (struct sockaddr * )&cliaddr, sizeof (cliaddr));
	if (result==-1)
	{
		perror ("\nClient Error!\n");
		exit (1);
	}
	*/
	clientWorker (sockfd);
}
