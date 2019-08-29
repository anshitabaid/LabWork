
#include<sys/socket.h>
#include<unistd.h>
#include<ctype.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>

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

void TerminateSocket(int sockfd)
{
	int status = close(sockfd);
	exit(0);
}

void PerformClientTask(int sockfd)
{
	char ch[256], buf[256];
	printf("\nEnter String:\n Enter QUIT to Exit\n");
	fgets(ch, sizeof(ch), stdin); 
	if(!strcmp(ch,"QUIT"))
	{
		TerminateSocket(sockfd);
	}
	for(int i=0;ch[i]!='\0';i++)
	{
		ch[i]+=4;
	}

	printf("This is the encryted sentence which will be sent: %s\n",ch);
	write(sockfd,ch,strlen(ch));
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
