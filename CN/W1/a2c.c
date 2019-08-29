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

struct sockaddr_in createSocket (int * sockfd)
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

void clientWorker(int sockfd)
{
    char buf [100];
    while (1)
    {
        fgets(buf,100, stdin);
        if (strcmp (buf, "STOP")==0)
            return;
        int n = write (sockfd, buf, strlen(buf));
        n=read (sockfd, buf, sizeof (buf));
        if (n<0)
        {
            perror ("Error");
            exit (1);
        }
        fputs (buf, stdout);
    }
}

int main ()
{
    int sockfd;
    struct sockaddr_in s = createSocket (&sockfd);
    clientWorker (sockfd);
    close (sockfd);
}