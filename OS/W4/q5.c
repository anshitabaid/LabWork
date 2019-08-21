#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main ()
{
	int fd = creat ("/home/170905404/Desktop/file.txt", S_IRWXU);
	if (fd==-1)
	{
		perror ("Error");
		printf ("%d\n", errno);
		exit (1);
	}
	//fd = open ("file.txt", O_RDWR);
	char msg [100];
	printf ("Enter message\n");
	scanf ("%s", msg);
	msg[strlen (msg)]='\0';
	char buf [100];
	//int status = write (fd, msg, sizeof (msg));
	write(fd, "hello geeks\n", strlen("hello geeks\n")); 
	int sz = read(fd, &buf, 100);
	buf [sz]='\0';
	printf ("%s\n", buf);
	close (fd);
}