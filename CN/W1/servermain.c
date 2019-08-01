#include "serverclient.h"
#include <stdio.h>
#include <stdlib.h>

int serverWorker (int newsockfd)
{ 
	while (1)
	{
	char buf [256];
	//logical part
	int n = read (newsockfd, buf, sizeof (buf));
	if (strcmp (buf, "QUIT")==0)
		return 0;
	printf ("Message from client: %s\n", buf);
	n = write (newsockfd, buf, sizeof (buf));
	}

	
}

int main ()
{
	int sockfds,clilen, newsockfd;
	struct sockaddr_in seraddr, cliaddr;
	seraddr = createServerSocket (&sockfds);
	while (1)
	{
		//
		clilen = sizeof (clilen);
		newsockfd = accept (sockfds,(struct sockaddr*) &cliaddr, &clilen);
		int status = serverWorker (newsockfd);
		if (status == 0 )
			status = terminateConnection (newsockfd);

	}
	


}
