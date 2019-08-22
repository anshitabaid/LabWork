#include "common.h"
struct inputs{
	int num1;
	int num2;
	char op;
};

typedef struct inputs INPUTS;
typedef struct inputs* INPUTSS;
int CreateServerSocket(int sockfd,struct sockaddr_in seraddr)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORT);
	bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
	return sockfd;	

}	

double findres(INPUTS i1){
	double res;
	char op;
	op=i1.op;
	printf("%c",op);
	switch(op){
		case '+': res=(i1.num1+i1.num2);
		printf("\n%f",res);
		return res;

		case '-':res=(i1.num1-i1.num2);
		printf("\n%f",res);
		return res;

		case '/':res=(i1.num1/i1.num2);
		return res;

		case '*':
		res=(i1.num1*i1.num2);
		return res;
	}
	
}
void serverTask(int sockfd,int newsockfd,struct sockaddr_in cliaddr,int clilen){
		int n=1;
		listen(sockfd,5);
		double res;
		while(1){
			INPUTS i1;
			printf("\nServer Waiting");
			clilen=sizeof(clilen);
			newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
			if(fork()==0){
				n=read(newsockfd,&i1,sizeof(struct inputs));
				//printf("Message::%d",n);
				printf("\nBuffer: %c\n",i1.op);
				printf("\nMessage from client \n");
				res=findres(i1);
				printf("here");
				printf("%f",res);
				n=write(newsockfd,&res,sizeof(double));
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