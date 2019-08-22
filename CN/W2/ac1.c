#include "common.h"
int CreateClientSocket(int sockfd,struct sockaddr_in address)
{
	int len,result;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORT);
	len=sizeof(address);
	result=connect(sockfd,(struct sockaddr*)&address,len);
	if(result==-1){
		perror("Client error");
		exit(1);
	}
	return sockfd;	

}	

void clientTask(int sockfd){
	int n=1;
	char buf[BUFLEN],buf2[BUFLEN];
	while(1){
	printf("\nWhat is the time?");
	sprintf(buf, "%s", "What is the time?");
	getchar();
	write(sockfd, buf, sizeof(buf));
	read(sockfd, buf, sizeof(buf));
	read(sockfd, buf2, sizeof(buf2));
	printf("The time is: %s \nProcess ID: %s", buf, buf2);
	}
}

void terminateSocket(int sockfd){
	close(sockfd);
}
int main () {
	int sockfd;
	struct sockaddr_in address;
	sockfd=CreateClientSocket(sockfd,address);
	clientTask(sockfd);
	terminateSocket(sockfd);
	return 0;
}


