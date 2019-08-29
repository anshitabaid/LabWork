#include "serverclient.h"

void clientworker (int sockfd)
{
    char buf[256];
    pid_t pid;
    int n = read (sockfd, buf, 256);
    if (n<1)
    {
        perror ("Error");
        exit (1);
    }
    n = read (sockfd, &pid, sizeof (pid_t));
    fputs (buf, stdout);
    printf ("%d\n", pid);
}

int main ()
{
    int sockfd;
    struct sockaddr_in c = createClientSocket (&sockfd);
    clientworker (sockfd);

}