#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define COUNT 4
#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main ()
{
    int pipe_fd;
    int res, n, count=0;
    int open_mode = O_RDONLY;
    //printf ("Process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open (FIFO_NAME, open_mode);
    //printf ("Process %d result %d\n", getpid(), pipe_fd);
    if (pipe_fd!=-1)
    {
        while (count<COUNT) 
        {
            res = read (pipe_fd, &n, sizeof (n));
            if (res<0)
            {
                perror ("READ");
                exit(1);
            }
            count++;
            printf ("%d\t", n);
        }
        (void)close (pipe_fd);
    }
    else
    {
        exit (1);
    }
    //printf ("Process %d finished %d bytes read\n", getpid(), bytes_read);
   exit(0);
}
