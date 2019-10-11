#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp;
typedef struct 
{
	char ch;
	int shift;
}entry;
int hit = 0, miss = 0;
entry * init(char pattern[],int len){
	entry * table = (entry *) malloc(sizeof(entry)*28);
	char a = 'a';
	for(int i = 0;i<26;i++){
		table[i].ch = a;
		table[i].shift = len;
		a++;
	}
	table[26].ch = '_';
	table[26].shift = len;
	table[27].ch = ' ';
	table[27].shift = len;
	for(int j = 0;j<len-1;j++){
		char c = pattern[j];
		for(int k = 0;k<28;k++){
			if (table[k].ch == c){
				table[k].shift = len - 1 - j;
			}
		}
	}
	return table;
}
int getEntry(entry * table,char a){
	for(int i = 0;i<28;i++){
		if(table[i].ch == a){
			return table[i].shift;
		}
	}
}
int search(char str[],char pattern[],entry * table,int m,int n){
	int i = m-1;
	while (i<=n-1){
		int k = 0;
		while(k<=m-1 && pattern[m-1-k]==str[i-k]){
			comp ++;
			hit++;
			k++;
		}
		comp++;
		if (k == m){
			return i-m+1;
		}
		else{
			miss++;
			i = i+getEntry(table,str[i]);
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	comp = 0;
	char str[80];
	char pattern[80];
	gets(str); 
	gets(pattern);
	int patlen = strlen(pattern);
	int strlen1 = strlen(str);
	entry * table = init(pattern,patlen);
	int ind = search(str,pattern,table,patlen,strlen1);
	if(ind  == -1){
		printf("Not found\n");
		printf("Hits: %d, misses: %d", hit, miss);
	}
	else{
		printf("Found at %d\n",ind+1);
		printf("Hits: %d, misses: %d", hit, miss);
	}
	printf("Number of key cmparisons: %d",comp);
	return 0;
}