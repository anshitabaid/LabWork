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
	int n=1,k;
	char ch[BUFLEN],buf[BUFLEN],b[100][100],st[]="stop";
	printf("Enter a String: ");
	//gets(ch);
	scanf("%[^\n]s",ch);
	//ch[strlen(ch)]="\0";
	write(sockfd,ch,strlen(ch));
	if(strcmp(ch,st)==0){
		printf("Client ends.");
		terminateSocket(sockfd);
		exit(1);
	}
	printf("\nString back from server:\n ");
	while(n){
		n=read(sockfd,&k,sizeof(int));
		n=read(sockfd,b,sizeof(b));
		for(int i=0;i<=k;i++){
			puts(b[i]);
		}
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
