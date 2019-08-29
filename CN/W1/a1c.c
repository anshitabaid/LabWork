#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
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
    int n = connect (*sockfd, (struct sockaddr *)&s, sizeof(s));
    return s;
}

void clientWorker (int sockfd)
{
    char msg [20];
    printf ("Enter string\n");
    fgets (msg, 20, stdin);
    for (int i = 0; i<strlen (msg); i++)
    {

        msg[i]=msg[i]+key;
    }
    int n = write (sockfd, msg, strlen (msg));
    if (n<0)
    {
        perror ("Error");
        exit (1);
    }
}

int main ()
{
    int sockfd;
    createSocket (&sockfd);
    clientWorker (sockfd);
}