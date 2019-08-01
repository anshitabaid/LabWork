#include "serverclient.h"
#include <time.h>

void serverWorker (int sockfds)
{
    char buf [256];
    time_t curtime;
    struct tm * loc_time;
    curtime = time (NULL);
    loc_time = localtime (&curtime);
    strncpy (buf, asctime (loc_time), 256);
    buf[sizeof (buf)]='\0';
    write (sockfds, buf, sizeof (buf));

}


int main ()
{
    struct sockaddr_in seraddr, cliaddr;
    int sockfds, newsockfds, clilen, status;
    seraddr = createServerSocket (&sockfds);
    while (1)
    {
        clilen = sizeof (clilen);
        newsockfds = accept (sockfds, (struct sockaddr *)&cliaddr, &clilen);
        serverWorker (newsockfds);
        status = terminateConnection (newsockfds);
        if (status == -1)
        {
            perror ("\nCould not close connection\n");
            exit (1);
        }
        

    }


}