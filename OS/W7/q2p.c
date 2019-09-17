#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
#define COUNT 4

int main ()
{
    int pipe_fd;
    int res;
    int count=0, n;
    int open_mode = O_WRONLY;
    if (access (FIFO_NAME, F_OK)==-1)
    {
        res = mkfifo (FIFO_NAME, 0777);
        if (res!=0)
        {
            perror ("MKFIFO");
            exit (1);
        }
    } 
    //printf ("Process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open (FIFO_NAME, open_mode);
    //printf ("Process %d result %d\n, getpid(), pipe_fd");
    if (pipe_fd!=-1)
    {
        while (count<COUNT)
        {
            scanf ("%d", &n);
            res=write (pipe_fd, &n, sizeof (n));
            if (res==-1)
            {
                perror ("Write");
                exit(1);
            }
            count++;
        }
        (void)close(pipe_fd);
    }
    else
    {
        exit (1);
    }
    //printf ("Process %d finished \n", getpid());
    exit(0);
}