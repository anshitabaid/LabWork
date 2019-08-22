#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void PerformClientTask(int sockfd)
{
	char ch[256], buf[256];
	printf("\nEnter String\n Enter stop to exit\n");
	fgets(ch, sizeof(ch), stdin);
	if(!strcmp(ch,"Stop"))
	{
		TerminateSocket(sockfd);
	}

	char *p = strchr(ch,'\0');
	int lastindex = (int)(p-ch);
	ch[lastindex-1] = ' ';
	write(sockfd,ch,strlen(ch));
	int n=read(sockfd,buf,sizeof(buf));
	printf("Received from server: %s\n",buf);
}
void TerminateSocket(int sockfd)
{
	int status = close(sockfd);
	exit(0);
}
int CreateClientSocket(char* ipaddress, int portno)
{
	struct sockaddr_in mysockstruct;
	mysockstruct.sin_family = AF_INET;
	mysockstruct.sin_addr.s_addr = inet_addr(ipaddress);
	mysockstruct.sin_port = htons(portno);
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	int len=sizeof(mysockstruct);
	int result = connect(sockfd,(struct sockaddr *)&mysockstruct,len);
	return sockfd;
}


int main()
{
	char ipaddress[] = "127.0.0.1";
	int portno = 10200;
	while(1)
	{
		int sockfd = CreateClientSocket(ipaddress,portno);
		PerformClientTask(sockfd);
	}
}
