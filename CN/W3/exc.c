#include "serverclient.h"

void clientworker (int sockfd, struct sockaddr_in c)
{
    char buf [256], buf1[256];
    fgets (buf, 256, stdin);
    int cl = sizeof (c);
    int n  =sendto (sockfd, buf, 256, 0, (struct sockaddr *)&c, cl);
    n = recvfrom (sockfd, buf1, 256, 0, (struct sockaddr *)&c, &cl);
    fputs (buf1, stdout);
}

int main ()
{
    int sockfd;
    struct sockaddr_in c = createClientSocket (&sockfd);
    clientworker (sockfd, c);

}