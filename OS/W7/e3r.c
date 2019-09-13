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

#define MAX_TEXT 512

typedef struct my_msg
{
	long int msgtype;
	char text [MAX_TEXT];
}msg;

int main ()
{
	int running = 1;
	msg somemsg;
	int msgid;
	long int msgtorecv = 0;
	msgid = msgget ((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1 )
	{
		perror ("MSGGET");
		exit(1);
	}
	while (running)
	{
		if (msgrcv(msgid, (void *)&somemsg, BUFSIZ, msgtorecv, 0)==-1)
		{
			perror ("msgrcv");
			exit (1);
		}
		printf ("You wrote: %s", somemsg.text);
		if (strncmp (somemsg.text, "end", 3)==0)
			running=0;
	}
	if (msgctl (msgid, IPC_RMID,0)==-1)
	{
		perror ("msgctl");
		exit (1);
	}
	exit (0);
}