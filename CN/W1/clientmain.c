#include "server.h"
#include "client.h"
#include <stdio.h>

void clientWorker(int sockfd)
{
	int n;
	char ch [256], buf [256];
	printf ("Enter string");
	gets (ch);
	ch[strlen (ch)] = '\0';
	write (sockfd, ch, strlen (ch));
	printf ("String sent back from server....");
	while (1)
	{
		n = read (sockfd, buf, sizeof (buf));
		puts (buf);
	}

}

int main ()
{
	struct sockaddr_in cliaddr;
	int sockfd;
	createClientSocket (&cliaddr, &sockfd);
	//connect to server
	int result = connect (sockfd, &cliaddr, sizeof (cliaddr));
	if (result==-1)
	{
		perror ("\nClient Error!\n");
		exit (1);
	}
	clientWordker (sockfd);
}