#include "common.h"

int createServerSocket(int sockfd, struct sockaddr_in seraddr){
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORT);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	return sockfd;
}

void terminateSocket(int sockfd){
	close(sockfd);
}

void serverTask(int sockfd, int newsockfd, struct sockaddr_in cliaddr){
	int n = 1, result, clilen;
	char buf[BUFLEN];
	fd_set readfds, testfds;

	listen(sockfd, 5);
	FD_ZERO(&readfds);
	FD_SET(sockfd, &readfds);
	while(1){
		char ch;
		int fd, nread;
		testfds = readfds;
		printf("Server waiting...");

		result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
		if(result<1){
			perror("Server error");
			exit(1);
		}
		for(fd=0; fd<FD_SETSIZE; fd++){
			if(FD_ISSET(fd, &testfds)){
				if(fd == sockfd){
					clilen = sizeof(cliaddr);
					newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
					FD_SET(newsockfd, &readfds);
					printf("Adding client on fd %d\n", newsockfd);
				}
				else{
					ioctl(fd, FIONREAD, &nread);
					if(nread == 0){
						close(fd);
						FD_CLR(fd, &readfds);
						printf("Removing client on fd %d\n", fd);
					}
					else{
						n = read(newsockfd, buf, sizeof(buf));
						sleep(5);
						printf("Serving client on fd %d\n", fd);
						printf("\nMessage from Client: %s \n", buf);
						printf("Sending time and PID to client...\n");

						time_t rawtime;
				    	struct tm *timex;
						time(&rawtime);
						timex = localtime(&rawtime);
						sprintf(buf, "%s", asctime(timex));
						write(newsockfd, buf, sizeof(buf));

						sprintf(buf, "%d", getpid());
				        write(newsockfd, buf, sizeof(buf));
					}
				}
			}
		}
	}
}

int main(){
	int sockfd, newsockfd, clilen;
	struct sockaddr_in seraddr, cliaddr;

	sockfd = createServerSocket(sockfd, seraddr);
	serverTask(sockfd, newsockfd, cliaddr);
	terminateSocket(sockfd);
}
