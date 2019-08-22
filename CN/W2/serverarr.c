#include "common.h"

struct array{
	int arr[100];
	int num;
};
typedef struct array ARRAY;

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
			
			ARRAY buf;
			printf("\nServer Waiting");
			clilen=sizeof(clilen);
			newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
			if(fork()==0){
				n=read(newsockfd,&buf,sizeof(struct array));
				//printf("Message::%d",n);
				printf("\nBuffer: %d\n",z);
				printf("\nMessage from client \n");
				for(int i=0;i<buf.num-1;i++){
					for(int j=0;j<buf.num-i-1;j++){
						if(buf.arr[j+1]<buf.arr[j]){
							int temp=buf.arr[j];
							buf.arr[j]=buf.arr[j+1];
							buf.arr[j+1]=temp;
						}
					}
				}
				for(int i=0;i<buf.num;i++){
					printf("%d\t",buf.arr[i]);
				}
				n=write(newsockfd,&buf,sizeof(struct array));
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