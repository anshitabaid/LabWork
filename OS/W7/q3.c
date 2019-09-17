#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <ctype.h>
#include <sys/shm.h>

#define TEXT_SZ 2048

struct shared_use_st{
    int written_by_you;
    char c;
};


int main ()
{
    int running = 1;
    void * shared_memory = (void *)0;
    struct shared_use_st * shared_stuff;
    int shmid;
    pid_t pid;
    char ch;
    shmid = shmget ((key_t)1234, sizeof (struct shared_use_st), 0666|IPC_CREAT);
    if (shmid == -1)
    {
        perror ("SHMGET");
        exit (1);
    }
    shared_memory = shmat (shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        perror ("shmat");
        exit (1);
    }
    printf ("Memory attached at %X\n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;

    pid = fork();
    if (pid==-1)
    {
        perror ("Error");
        exit(1);
    }
    shared_stuff->written_by_you=0;
    if (pid==0)
    {
        while (1)
        {
        //child process
        while (shared_stuff->written_by_you==0);
        //if (shared_stuff->written_by_you==1)
        //{
            //printf ("HELLO");
            shared_stuff->c=toupper (shared_stuff->c);
            shared_stuff->written_by_you=0;
            sleep(1);
        //}
        }
    
    }
    else
    {
        while (1)
        {
            printf ("Enter letter\n");
            scanf ("%c", &ch);
            //printf ("%d", ch);
            if (ch=='0')
                break;
            
            shared_stuff->c = ch;
            shared_stuff->written_by_you=1;
            while (shared_stuff->written_by_you==1);
            printf ("In uppercase: %c\n", shared_stuff->c);
            
            //wait (NULL);
           
        }
    }
    if (shmdt (shared_memory)==-1)
    {
        perror ("SHMDT");
        exit(1);
    }
    exit (0);
}