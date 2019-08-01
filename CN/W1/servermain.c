#include "server.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>

void serverWorker (int newsockfd)
{
	char buf [256];
	//logical part
	int n = read (newsockfd, buf, sizeof (buf));
	printf ("Message from client %s\n", buf);
	n = write (newsockfd, buf, sizeof (buf));

	
}

int main ()
{
	int sockfds,clilen, newsockfd;
	struct sockaddr_in seraddr, cliaddr;
	createServerSocket (&seraddr, &sockfds);
	//createClientSocket (&cliaddr, &sockfdc);
	printf ("Server waiting");
	listen (sockfds, 5);
	while (1)
	{
		//
		clilen = sizeof (clilen);
		newsockfd = accept (sockfds,(struct sockaddr*) &cliaddr, &clilen);
		serverWorker (newsockfd);

	}

}
