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
		printf("\nServer Waiting");
		while(1){
			char a[BUFLEN],b[100][100],st[]="stop";
			clilen=sizeof(clilen);
			newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
			if(fork()==0){
				n=read(newsockfd,a,sizeof(a));
				printf("\nMessage from client %s\n",a);
				if(strcmp(a,st)==0){
				//printf("Server Ends.");
				terminateSocket(sockfd);
				terminateSocket(newsockfd);
				exit(1);

			    }
				int k=0,j=0,m;
				for(int i=0;a[i]!='\0';i++){
					if(a[i]==' '){
						b[k][j]='\0';
						k++;
						j=0;
					}
					else{
						b[k][j]=a[i];
						j++;
					}
				}
				b[k][j]='\0';
				for(int i=0;i<=k;i++){
				for(j=i+1;j<=k;j++){
					if (strcmp(b[i],b[j])==0){
						for(m=j;m<=k;m++)
							strcpy(b[m],b[m+1]);
						k--;
			        }
		        }
	        	}
			n=write(newsockfd,&k,sizeof(int));
			n=write(newsockfd,b,sizeof(b));
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




