#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORTNO 10200
#define IP "172.16.58.225"
/*
void createServerSocket (struct sockaddr_in * seraddr, int * sockfd)
{
	*sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in sa = *seraddr;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr (IP);
	sa.sin_port = htons (PORTNO);
	bind (*sockfd, &sa, sizeof (sa));

}
*/

void createClientSocket (struct sockaddr_in* cliaddr, int* sockfd)
{
	*sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in ca = *cliaddr;
	ca.sin_family = AF_INET;
	ca.sin_addr.s_addr = inet_addr (IP);
	ca.sin_port=htons(PORTNO);
}
/*

void clientWorker (int sockfds, struct sockaddr_in * cliaddr, int * clilen)
{
	listen (sockfds, 5);
	while (1)
	{
		char buf[256];
		printf ("Server waiting\n");
		//accept connection
		*clilen = sizeof (*clilen);
		struct sockaddr_in newsockfd = accept (sockfds, cliaddr, clilen);

		//logical part
		int n = read (newsockfd, buf, sizeof (buf));
		printf ("Message from client %s\n", buf);
		n = write (newsockfd, buf, sizeof (buf));

	}
}


int main ()
{
	int sockfds, sockfdc, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliadd;
	int i, value;
	createServerSocket (&seraddr, &sockfds);
	createClientSocket (&cliaddr, &sockfdc);


}
*/