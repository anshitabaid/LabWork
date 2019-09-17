#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TEXT_SZ 2048

struct shared_use_st{
    int written_by_you;
    char some_text [TEXT_SZ];
};



int main ()
{
    int running = 1;
    void * shared_memory = (void *)0;
    struct shared_use_st * shared_stuff;
    int shmid;
    srand ((unsigned int)getpid ());
    shmid = shmget ((key_t)1234, sizeof (struct shared_use_st), 0666|IPC_CREAT);
    if (shmid == -1)
    {
        perror ("SHMGET");
        exit (1);
    }
    shared_memory = shmat(shmid, (void *)0, 0);
    if (shared_memory == (void *)-1)
    {
        perror ("SHMAT");
        exit (1);
    }
    printf ("Memory attahed at %X\n", (int)shared_memory);
    shared_stuff = (struct shared_use_st *)shared_memory;
    while (running)
    {
        if (shared_stuff->written_by_you==1)
        {
            printf ("You wrote %s\n", shared_stuff->some_text);
            sleep (rand()%4);
            shared_stuff->written_by_you = 0;
            if (strncpy (shared_stuff->some_text, "end", 3)==0)
                running=0;
        }
    }

    if (shmdt (shared_memory)==-1)
    {
        perror ("SHMDT");
        exit (1);
    }
    if (shmctl (shmid, IPC_RMID, 0)==-1)
    {
        perror ("shmctl");
        exit (1);
    }
    exit (0);
}