#include "serverclient.h"

void serverworker (int sockfd)
{
    struct sockaddr_in c;
    int cl = sizeof (c);
    char buf[256];
    int n = recvfrom (sockfd, buf, sizeof(256), 0, (struct sockaddr *)&c, &cl);
    fputs (buf, stdout);
    n = sendto (sockfd, buf, 256, 0, (struct sockaddr *)&c, cl);

}

int main ()
{
    int sockfd;
    struct sockaddr_in s = createServerSocket (&sockfd);
    serverworker (sockfd);
}