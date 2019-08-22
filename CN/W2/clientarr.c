#include "common.h"

struct array{
	int arr[100];
	int num;
};
typedef struct array ARRAY;
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
	ARRAY A;
	int n;
	printf("No of elems: ");
	scanf("%d",&A.num);
	int arr[A.num],arr1[A.num];
	printf("\nEnter Elements:\n");
	for(int i=0;i<A.num;i++){
		scanf("%d",&A.arr[i]);
	}

	for(int i=0;i<A.num;i++){
		printf("%d\t",A.arr[i]);
	}
	write(sockfd,&A,sizeof(struct array));
	printf("\nArray recieved back from server after sorting\n");
	while(n){
		n=read(sockfd,&A,sizeof(struct array));
		for(int i=0;i<A.num;i++){
			printf("%d\t",A.arr[i]);
		}
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