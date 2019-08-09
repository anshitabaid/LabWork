#include<stdio.h>
#include<stdlib.h>
typedef unsigned int ui;

int main() {
	ui n;
	ui opcount=0;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	printf("Enter elements: \n");
	ui arr[n],i,j,temp;

	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			opcount++;
			if(arr[j]>arr[j+1]) {
            	temp = arr[j];
            	arr[j] = arr[j+1];
            	arr[j+1] = temp;
			}
		}
	}

	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf ("%d\n", opcount);
}