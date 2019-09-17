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

#define MAX_TEXT 513

struct my_msg_st
{
    long int my_msg_type;
    int num;
};

int main ()
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    int num;
    msgid = msgget ((key_t)1234, 0666|IPC_CREAT);
    if (msgid == -1 )
    {
        perror ("MSGGET");
        exit (1);
    }
    printf ("Enter some text\t");
    scanf ("%d", &num);
    some_data.my_msg_type = 1;
    some_data.num=num;
    if (msgsnd (msgid, (void *)&some_data, sizeof (int), 0)==-1)
    {
        perror ("MSGSEND");
        exit(1);
    }
    
    exit (0);
}