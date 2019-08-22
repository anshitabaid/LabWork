#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int createServerSocket(int sockfd, struct sockaddr_in seraddr){
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	return sockfd;
}

void performServerTask(int sockfd, int newsockfd, struct sockaddr_in cliaddr){
	int n = 1, clilen;

	listen(sockfd, 5);
	printf("Server waiting...\n");
	while(1){
		char hello[]="HTTP/1.1 200 OK\nConnection: Keep-Alive\nVary: Cookie, Accept-Encoding\nContent-Type: text/html;charset=utf-8\nContent-Encoding: gzip, deflate, br\n";

		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,&clilen);
		char buf[256];
		n = read(newsockfd, buf, sizeof(buf));
		puts(buf);
		n = write(newsockfd, hello, sizeof(hello));
		exit(0);
	}
}

void terminateSocket(int sockfd){
	close(sockfd);
}

int main(){
	int sockfd, newsockfd, clilen;
	struct sockaddr_in seraddr, cliaddr;

	sockfd = createServerSocket(sockfd, seraddr);
	performServerTask(sockfd, newsockfd, cliaddr);
	terminateSocket(sockfd);
	terminateSocket(newsockfd);
}
