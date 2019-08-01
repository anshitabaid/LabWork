#include "serverclient.h"

void clientWorker (int sockfd)
{
    while (1)
    {
        int n;
        char buf[256], ch[256];
        fgets (ch, 256, stdin);
        ch [strlen (ch)] = '\0';
        write (sockfd, ch, strlen (ch));
        printf ("String sent back from the server:\t");
        n = read (sockfd, buf, sizeof (buf));
        puts (buf);

    }
}

int main ()
{
    struct sockaddr_in cliaddr;
    int sockfd;
    cliaddr = createClientSocket (&sockfd);
    clientWorker (sockfd);
}