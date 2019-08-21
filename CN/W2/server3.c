//#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>


#define PORTNO 10200
#define IP "127.0.0.1"

int CreateServerSocket(int server_sockfd,struct sockaddr_in seraddr)
{
	int server_len;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr = inet_addr(IP);
	seraddr.sin_port = htons(PORTNO);
	server_len=sizeof(seraddr);
	bind(server_sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	return server_sockfd;	

}	
void serverTask(int server_sockfd,int client_sockfd,fd_set readfds,fd_set testfds, struct sockaddr_in cliaddr){
	int clilen;
	int n=1,result;
	listen(server_sockfd,5);
	FD_ZERO(&readfds);
	FD_SET(server_sockfd,&readfds);
	while(1){
		char buf[256],ch;
		int fd,nread;
		testfds=readfds;
		printf("\nServer Waiting\n");
		result=select(FD_SETSIZE,&testfds,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
		if(result<1){
			perror("Server Error");
			exit(1);
		}
		for(fd=0;fd<FD_SETSIZE;fd++){
			if(FD_ISSET(fd,&testfds)){
				if(fd==server_sockfd){
					clilen=sizeof(cliaddr);
					client_sockfd=accept(server_sockfd,(struct sockaddr*)&cliaddr,&clilen);
					FD_SET(client_sockfd,&readfds);
					printf("adding clinet on fd %d\n",client_sockfd);
					}
				else{
					ioctl(fd,FIONREAD,&nread);
					if(nread==0){
						close(fd);
						FD_CLR(fd,&readfds);
						printf("removing client on fc %d\n",fd);
					 }
					 else{
					 	read(fd,&ch,1);
					 	sleep(5);
					 	printf("serving client on fd %d\n",fd);
					 	ch++;
					 	write(fd,&ch,1);
					 }
					}
				}
			}
	  }
}

void terminateSocket(int sockfd){
	close(sockfd);
}
int main () {
	
	int server_sockfd,client_sockfd;
	fd_set readfds,testfds;
	struct sockaddr_in seraddr,cliaddr;
	server_sockfd=CreateServerSocket(server_sockfd,seraddr);
	serverTask(server_sockfd,client_sockfd,readfds,testfds,cliaddr);
	terminateSocket(server_sockfd);
	//terminateSocket(newsockfd);
	return 0;
}