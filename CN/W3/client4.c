#include "common.h"

struct inputs{
	int num1;
	int num2;
	char op;
};
typedef struct inputs INPUTS;
int CreateServerSocket(int sockfd,struct sockaddr_in address)
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
	int n=1,a,b;
	char arr[20],c;
	INPUTS i1;
	double res;
	printf("Enter first number:\n");
	scanf("%d",&i1.num1);
	printf("here");
	//i1.num1=a;
	printf("Enter second number: \n");
	scanf("%d",&i1.num2);
	//i1.num2=b;
	printf("Enter an operator: \n");
	scanf("%s",&i1.op);
	//strcpy(c,i1.op);
	write(sockfd,&i1,sizeof(struct inputs));
	printf("\nResult recieved back from server\n");
	while(n){
		n=read(sockfd,&res,sizeof(double));
		printf("%f\t",res);
		
	}
}

void terminateSocket(int sockfd){
	close(sockfd);
}
int main () {
	int sockfd;
	struct sockaddr_in address;
	sockfd=CreateServerSocket(sockfd,address);
	clientTask(sockfd);
	terminateSocket(sockfd);
	return 0;
}