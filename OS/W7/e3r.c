#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st {
    long int my_msg_type;
    char some_text [BUFSIZ];
};

int main ()
{
    int running=1;
    int msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;
    msgid = msgget ((key_t)1234, 0666| IPC_CREAT);
    if (msgid == -1)
    {
        perror ("Msgget");
        exit (1);
    }
    while (running)
    {
        if (msgrcv (msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0)==-1)
        {
            perror ("MSGRCV");
            exit (1);
        }
        printf ("You wrote %s\n", some_data.some_text);
        if (strncmp (some_data.some_text, "end", 3)==0)
        {
            running=0;
        }
    }
    if (msgctl (msgid, IPC_RMID, 0)==-1)
    {
        perror ("MSGCTL");
        exit(1);
    }
    exit (0);
}