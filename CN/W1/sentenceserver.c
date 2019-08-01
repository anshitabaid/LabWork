#include "serverclient.h"

int serverWorker (int sockfd, struct sockaddr_in cliaddr)
{
    while (1)
    {
        char buf [256];
        int n = read (sockfd, buf, sizeof (buf));
        if (strcmp (buf, "QUIT")==0)
            return 0;
        buf [sizeof (buf)] = '\0';
        printf ("Client sent:\t%s", buf);
        printf ("Client IP Address:\t%d", cliaddr.sin_addr.s_addr);
        printf ("Port Number:\t%d", cliaddr.sin_port);
        n = write (newsockfd, buf, sizeof (buf));
    }
    return 1;
}

int main ()
{
    struct sockaddr_in seraddr, cliaddr;
    int sockfd, newsockfd, clilen;
    seraddr = createServerSocket (&sockfd);
    while (1)
    {
        clilen = sizeof (clilen);
        newsockfd = accept (sockfd, (struct sockaddr* )&cliaddr, &clilen);
        int status = serverWorker (newsockfd);
        if (status==0)
        {
            status=terminateConnection (newsockfd, cliaddr);
            if (status==-1)
            {
                perror ("\nServer error!!\n");
                exit (1);
            }
        }
        else
            printf ("\nConnection closed!\n");


    }
}