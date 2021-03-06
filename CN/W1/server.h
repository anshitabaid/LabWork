#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORTNO 10200
#define IP "10.70.3.93"

struct sockaddr_in createServerSocket (int * sockfd)
{
	*sockfd = socket (AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr (IP);
	sa.sin_port = htons (PORTNO);
	bind (*sockfd,(struct sockaddr*) &sa, sizeof (sa));
    return sa;
}

struct sockaddr_in createClientSocket (int* sockfd)
{
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ca;
    ca.sin_family = AF_INET;
    ca.sin_addr.s_addr = inet_addr (IP);
    ca.sin_port=htons(PORTNO);
    return ca;
}