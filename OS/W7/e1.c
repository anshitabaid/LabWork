#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char * argv[])
{
    int pfd [2];
    pid_t cpid;
    char buf;
    assert (argc == 2);
    if (pipe(pfd)==-1)
    {
        perror ("Pipe");
        exit(1);
    }
    cpid = fork ();

    if (cpid == -1)
    {
        perror ("Fork");
        exit(1);
    }
    if (cpid ==0) //child will only read
    {
        close (pfd[1]);
        while (read(pfd[0], &buf, 1)>0)
            write (STDOUT_FILENO, &buf, 1);
        write (STDOUT_FILENO, "\n", 1);
        close (pfd[0]); //done reading
        exit (0);
    }

    else //parent
    {
        //writes
        close (pfd[0]);
        write (pfd[1], argv[1], strlen (argv[1]));
        close (pfd [1]); //done writing
        wait (NULL); //wait for child
        exit (0);
    }
}