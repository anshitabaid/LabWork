#include "serverclient.h"
#define arrsize 5
void clientWorker (int sockfd, struct sockaddr_in addr)
{
	int n, status, len, i, j;
	len = sizeof (addr);
	printf ("Enter no of rows:\t");
	scanf ("%d", &n);
	status = sendto (sockfd, &n, sizeof (n), 0, (struct sockaddr *)&addr, len);
	if (status==-1)
	{
		perror ("Error!");
		exit (1);
	}
	int arr[arrsize];
	for (j=0; j<n; j++)
	{
		for (i=0; i<arrsize; i++)
			scanf ("%d", &arr[i]);
		status = sendto (sockfd, arr, sizeof (arr), 0, (struct sockaddr *)&addr, len);
	}
}

int main ()
{
	struct sockaddr_in cadd;
	int sockfd;
	cadd = createClientSocket (&sockfd);
	clientWorker (sockfd, cadd);
	terminateConnection (sockfd);
}