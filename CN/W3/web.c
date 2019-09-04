/*
    char ch[]="GET /home.html HTTP/1.1\r\n
    Accept-Language: en-US\r\n
    Host: developer.mozilla.org\r\n
    Accept: text/html\r\n
    Accept-Encoding: gzip, deflate, br\n";

*/
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <netdb.h>

#define PORTNO 10200
#define IP "127.0.0.1"

struct sockaddr_in createServerSocket (int * sockfd)
{
    *sockfd = socket (AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons (PORTNO);
    bind (*sockfd,(struct sockaddr*) &sa, sizeof (sa));
    printf ("Server started\n");
    listen (*sockfd, 5);
    return sa;
}

struct sockaddr_in createClientSocket (int* sockfd)
{
    //int portno =        443;
    //char *host =        "google.com";
     //struct hostent *server;
     //server = gethostbyname(host);
    //if (server == NULL) perror("ERROR, no such host");
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ca;
    ca.sin_family = AF_INET;
    ca.sin_addr.s_addr = inet_addr ("216.58.196.164");

    //memcpy(&ca.sin_addr.s_addr,server->h_addr,server->h_length);
    ca.sin_port=htons(80);
    int result = connect (*sockfd, (struct sockaddr * )&ca, sizeof (ca));
    if (result==-1)
    {
        perror ("\nClient Error!\n");
        exit (1);
    }
    return ca;
}
//Accept-Language: en-US\r\nHost: developer.mozilla.org\r\nAccept: text/html\r\n

void clientworker(int sockfd)
{
    char buf [500];
    char ch[]="GET / HTTP/1.1\r\nAccept-Language: en-US\r\nHost: google.com\r\nAccept: text/html\r\n\r\n";
    int n  =write (sockfd, ch, sizeof (ch));
    if (n<0)
    {
        perror ("Error\n"); exit (1);
    }
    n = read (sockfd, buf, 500);
    fputs (buf, stdout);
}

int terminateConnection (int sockfd)
{
    return close (sockfd);
}
int main ()
{
    int sockfd;
    struct sockaddr_in c = createClientSocket (&sockfd);
    clientworker (sockfd);

}
