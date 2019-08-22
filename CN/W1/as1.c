#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>


int CreateServerSocket(char* ipaddress, int portno)
{
	struct sockaddr_in mysockstruct;
	mysockstruct.sin_family = AF_INET;
	mysockstruct.sin_addr.s_addr = inet_addr(ipaddress);
	mysockstruct.sin_port = htons(portno);
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,  (struct sockaddr*)  &mysockstruct ,sizeof(mysockstruct) );
	return sockfd;
}

void PerformServerTask(int newsockfd, struct sockaddr_in clientsocket)
{
	char buf[256]; 
	memset(buf,'\0',256*sizeof(char));
	int n;
	n=read(newsockfd,buf,sizeof(buf));
	printf("Encrypted message from client is %s\nDecrypting...\n",buf);
	for(int i=0;i<strlen(buf);i++)
	{
		buf[i]-=4;
	}
	printf("Decrypted message is %s\n",buf);
}
int main()
{
	char ipaddress[] = "127.0.0.1";
	int portno = 10200;
	int sockfd = CreateServerSocket(ipaddress,portno);
	struct sockaddr_in clientsocket;
	int clientlength,newsockfd;
	while(1)
	{
		listen(sockfd,5);
		clientlength = sizeof(clientsocket);
		newsockfd = accept(sockfd,(struct sockaddr *)&clientsocket,&clientlength);
		PerformServerTask(newsockfd, clientsocket);
	}
	return 0;
}
