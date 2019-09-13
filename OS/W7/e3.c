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
	char buffer [BUFSIZ];
	msgid = msgget ((key_t)1234, 0666 |IPC_CREAT);
	if (msgid == -1 )
	{
		perror ("MSGGET");
		exit (1);
	}
	while (running)
	{
		printf ("Enter some text\t");
		fgets (buffer, BUFSIZ, stdin);
		somemsg.msgtype=1;
		strcpy (somemsg.text, buffer);
		if (msgsnd (msgid, (void *)&somemsg, MAX_TEXT, 0)==-1)
		{
			perror ("msgsend");
			exit (1);
		}
		if (strncmp (buffer, "end", 3)==0)
		{
			running=0;
		}
	}
}