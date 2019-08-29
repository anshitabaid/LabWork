#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define IP "127.0.0.1"
#define PORTNO 10200

struct sockaddr_in createSocket (int * sockfd)
{
    struct sockaddr_in s;
    *sockfd = socket (AF_INET, SOCK_STREAM, 0);
    s.sin_family = AF_INET;
    s.sin_addr.s_addr = inet_addr (IP);
    s.sin_port = htons (PORTNO);
    bind (*sockfd, (struct sockaddr *)&s, sizeof (s));
    listen (*sockfd, 5);
    return s;
}

void serverWorker (int sockfd)
{
    printf ("%s\n", "Server started");
    struct sockaddr_in c;
    int clilen=sizeof (c);
    int newsockfd, n;
    char sent[100], nsent[100];
    char words [10][100];
    int words_ind = 0;
    int i, j, l;
    newsockfd = accept (sockfd, (struct sockaddr *)&c, &clilen);
    while (1)
    {
        n=read (newsockfd, sent, sizeof (sent));
        char word [100];
        int k=0;
        for (i=0; i<=n; i++)
        {
            if (sent[i]==' ' || sent[i]=='\0')
            {
                word[k]='\0';
                //search for word in words
                //if not found, insert
                for (j=0; j<words_ind; j++)
                    if (strcmp (word, words[j])==0){
                        break;
                    }
                if (j==words_ind) //not found
                {
                    strcpy (words[words_ind++], word);
                }

                k=0;
            }
            else
                word[k++]=sent[i];

        }
        k=0;
        for (i=0; i<words_ind; i++)
        {
            l = strlen (words[i]);
            for (j=0; j<l; j++)
                nsent [k++]=words[i][j];
            nsent[k++]=' ';
        }
        nsent[i]='\0';
        fputs (nsent, stdout);
        n=write (newsockfd, nsent, strlen (nsent));
        printf ("%d\n", n);
    }
}

int main ()
{
    int sockfd;
    struct sockaddr_in s = createSocket (&sockfd);
    serverWorker(sockfd);
    close (sockfd);
}