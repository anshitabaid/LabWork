#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORTNO 10200
#define IP "127.0.0.1"

struct sockaddr_in createServerSocket (int * sockfd,fd_set * readfds)
{
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr (IP);
    sa.sin_port = htons (PORTNO);
    bind (*sockfd,(struct sockaddr*) &sa, sizeof (sa));
    printf ("Server started\n");
    listen (*sockfd, 5);
    FD_ZERO (readfds);
    FD_SET (*sockfd, readfds);
    return sa;
}

int doWork (fd_set * readfds, int server_sockfd)
{
    int fd;
    fd_set * testfds = readfds;
    int clien_len;
    struct sockaddr_in client_address;
    for (fd=0; fd<FD_SETSIZE; fd++)
    {
        if (FD_ISSET (fd, testfds))
        {
            if (fd==server_sockfd)
            {
                client_len = sizeof (client_address);
                client_sockfd = accept (server_sockfd, (struct sockaddr * )&client_address, &client_len);
                FD_SET (client_sockfd, readfds);
                printf ("Adding client on fd %d\n", client_sockfd);
            }
            else
            {
                ioctl (fd, FIONREAD, &nread);
                if (nread==0)
                {
                    close (fd);
                    FD_CLR (fd, readfds);
                    printf ("Removing client on fd %d\n", fd);
                }
                else
                {

                }
            }

            }
        }
    }
}