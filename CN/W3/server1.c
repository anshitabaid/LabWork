#include "serverclient.h"
#define arrlen 5

void serverWorker (int sockfd, struct sockaddr_in cadd, int m[][arrlen])
{
	int i, j, len, status, n;
	len = sizeof (cadd);
	//receive no of rows
	status = recvfrom (sockfd, &n, sizeof (int), 0, (struct sockaddr *)&cadd, &len);
	if (status==-1){
		perror("Error!");
		exit (1);
	}
	//recv rows
	for (i=0; i<n; i++)
	{
		status = recvfrom (sockfd, m[i], sizeof (m[0]), 0, (struct sockaddr *)&cadd, &len);
		if (status==-1)
		{
			perror ("Error!");
			exit (1);
		}
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<arrlen; j++)
			printf ("%d\t", m[i][j]);
		printf("\n");
	}

}

int main ()
{
	struct sockaddr_in sadd, cadd;
	int sockfd, newsockfd;
	sadd = createServerSocket (&sockfd);
	int m [10][5];
	while (1)
		serverWorker (sockfd, cadd, m);
	terminateConnection (sockfd);

}