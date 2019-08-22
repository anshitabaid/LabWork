#include "common.h"
int CreateServerSocket(int sockfd,struct sockaddr_in seraddr)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORT);
	bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	return sockfd;	

}	
void serverTask(int sockfd,int newsockfd,struct sockaddr_in cliaddr,int clilen){
		int n=1;
		listen(sockfd,5);
		while(1){
			char buf[BUFLEN];
			printf("\nServer Waiting");
			clilen=sizeof(clilen);
			newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
			if(fork()==0){
				n=read(newsockfd,buf,sizeof(buf));
				printf("\nMessage from client %s\n",buf);
				//n=write(newsockfd,buf,sizeof(buf));
				printf("Sending time and PID to client...\n");
				time_t rawtime;
		    	struct tm *timex;
				time(&rawtime);
				timex = localtime(&rawtime);
				sprintf(buf, "%s", asctime(timex));
				write(newsockfd, buf, sizeof(buf));
				sprintf(buf, "%d", getpid());
		        write(newsockfd, buf, sizeof(buf));
				terminateSocket(newsockfd);
			}
			else terminateSocket(newsockfd);
	    }
}

void terminateSocket(int sockfd){
	close(sockfd);
}
int main () {
	
	int sockfd,newsockfd,clilen;
	struct sockaddr_in seraddr,cliaddr;
	sockfd=CreateServerSocket(sockfd,seraddr);
	serverTask(sockfd,newsockfd,cliaddr,clilen);
	terminateSocket(sockfd);
	//terminateSocket(newsockfd);
	return 0;
}
