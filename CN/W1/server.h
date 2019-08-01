#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200
#define IP "172.16.58.225"

void createServerSocket (struct sockaddr_in * seraddr, int * sockfd)
{
	*sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in sa = *seraddr;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr (IP);
	sa.sin_port = htons (PORTNO);
	bind (*sockfd,(struct sockaddr_in*) &sa, sizeof (sa));

}