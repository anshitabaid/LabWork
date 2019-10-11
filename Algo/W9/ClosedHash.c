#include <stdio.h>
#include <stdlib.h>
int comp;
int probe(int table[],int t, int m){
	int i = t+1;
	printf("\n%d",t);
	while(i%m != t){
		printf("\t%d", i%m);
		if(table[i%m] == -1) return i%m;
		i++;
	}
	return -1;
}
int search_probe(int table[],int a,int ele, int m){
	int i = a+1;
	
	while(comp++&&i%m != a){
		
		if(table[i%m] == ele) return i%m;
		i++;
	}
	return -1;
}
void insert(int table[],int a, int m){
	int mod = a%m;
	if(table[mod]>-1){
		int p = probe(table,mod, m);
		if(p>=0){
			table[p] = a;
			printf("inserted %d at %d\n",a,p);
		}
		else
			printf("Hash table full.\n");
	}
	else{
		table[mod]=a;
		printf("inserted %d at %d\n",a,mod);
	}
}
void search(int a,int table[], int m){
	int mod = a%m;
	comp++;
	if(table[mod]!=a){
		int p = search_probe(table,mod,a, m);
		if(p == -1) printf("Not found\n");
		else{
			printf("Found at %d\n",p);
		}
	}
	else{
		printf("Found at %d\n",mod);
	}
}
int main(int argc, char const *argv[])
{
	printf("Enter value of m(no of buckets)\n");
	int m;
	scanf("%d", &m);
	int table[m];
	for(int i =0;i<m;i++) 
		table[i]=-1;
	printf("Enter all values into hash table(-1 to stop).\n");
    int t, k;
    for(int i = 0;;i++){
        scanf("%d", &t);
        if(t==-1)
            break;
        insert(table, t, m);
	}
	comp = 1;

	printf("Enter value to be searched for\n");
	int x;
	scanf("%d", &x);
	search(x, table, m);
	printf("%d",comp);
	return 0;
}