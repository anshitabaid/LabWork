#include "serverclient.h"
#include <time.h>

void serverworker (int sockfd)
{
    struct sockaddr_in c;
    int cl = sizeof (c);
    while (1)
    {
        
    int newsockfd = accept (sockfd, (struct sockaddr *)&c, &cl);
        if (fork()==0)
        {
            //child process
            time_t t1;
            struct tm * t2;
            char * t3;
            time (&t1);
            t2 = localtime (&t1);
            t3 = asctime (t2);
            char buf [256];
            strncpy (buf, t3, 256);
            int n = write (newsockfd, buf, 256);
            if (n<1)
            {
                perror ("error here");
                exit (1);
            }
            pid_t pid = getpid ();
            n = write (newsockfd, &pid, sizeof(pid_t));
            if (n<1)
            {
                perror ("Error");
                exit (1);
            }
            close (newsockfd);
            exit (0);
        }
        else
            close (newsockfd);
    }
}

int main ()
{
    int sockfd;
    struct sockaddr_in s = createServerSocket (&sockfd);
    serverworker(sockfd);
    close (sockfd);

}