#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORTNO 10200
#define IP "172.16.58.225"

struct sockaddr_in createServerSocket (int * sockfd)
{
	*sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr (IP);
	sa.sin_port = htons (PORTNO);
	bind (*sockfd,(struct sockaddr*) &sa, sizeof (sa));
    printf ("Server started\n");
    listen (*sockfd, 5);
    return sa;
}

struct sockaddr_in createClientSocket (int* sockfd)
{
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ca;
    ca.sin_family = AF_INET;
    ca.sin_addr.s_addr = inet_addr (IP);
    ca.sin_port=htons(PORTNO);
    int result = connect (*sockfd, (struct sockaddr * )&ca, sizeof (ca));
    if (result==-1)
    {
        perror ("\nClient Error!\n");
        exit (1);
    }
    return ca;
}

int terminateConnection (int sockfd)
{
    return close (sockfd);
}