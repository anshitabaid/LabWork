#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#define IP "127.0.0.1"
#define PORTNO 10200
#define key 4

struct sockaddr_in createSocket (int * sockfd)
{
    struct sockaddr_in s;
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    s.sin_family=AF_INET;
    s.sin_addr.s_addr = inet_addr (IP);
    s.sin_port = htons (PORTNO);
    bind (*sockfd, (struct sockaddr *)&s, sizeof (s));
    listen (*sockfd, 5);
    return s;
}

void serverWorker (int sockfd)
{
    char buf[256];
    struct sockaddr_in client;
    int clilen = sizeof (client);
    int newsockfd;
    int n, i;
    newsockfd = accept (sockfd, (struct sockaddr *)&client, &clilen);
    n = read (newsockfd, buf, sizeof (buf));
    if (n<0)
    {
        perror ("Error");
        exit (1);
    }
    for (i=0; i<n; i++)
        buf[i]=buf[i]-key;
    printf ("%s\n", buf);
    
}

int main ()
{
    int sockfd;
    struct sockaddr_in s = createSocket (&sockfd);
    serverWorker (sockfd);
}