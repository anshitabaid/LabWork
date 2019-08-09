#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned int ui;

int main() {
	char text[100],patt[100];
	printf("Enter text: \n");
	gets(text);
	printf("Enter pattern: \n");
	gets(patt);

	ui n = strlen(text),m = strlen(patt);
	ui i,j,f=0;

	for(i=0; i<n-m; i++) {
		for(j=0; j<m; j++) {
			if(text[i+j]!=patt[j]) 
				break;
		}
		if(j==m) {
			f = 1;
			break;
		}
	}

	if(f==1)
		printf("Pattern found in text\n");
	else
		printf("Pattern not found in text\n");
}
