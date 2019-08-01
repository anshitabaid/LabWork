#include "serverclient.h"

void clientWorker (int sockfd)
{
    char buf [256];
    int n = read (sockfd, buf, sizeof (buf));
    puts (buf);
    printf ("\nProcess ID: %d\n", getpid());
}

int main ()
{
    struct sockaddr_in cliaddr;
    int sockfd;
    cliaddr = createClientSocket (&sockfd);
    clientWorker (sockfd);
    terminateConnection (sockfd);
}