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
    int num;
};

int palin (int num)
{
    int rev=0;
    int copy = num;
    while (copy>0)
    {
        rev = rev*10 + copy%10;
        copy/=10;
    }
    if (num==rev)
        return 1;
    return 0;

}

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
    if (msgrcv (msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0)==-1)
    {
        perror ("MSGRCV");
        exit (1);
    }
    printf ("You wrote %d\n", some_data.num);
    if (palin(some_data.num))
        printf ("It is a palindrome\n");
    else
        printf ("Not a palindrome\n");
    if (msgctl (msgid, IPC_RMID, 0)==-1)
    {
        perror ("MSGCTL");
        exit(1);
    }
    exit (0);
}