#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	struct node* left;
	struct node* right;
	float freq;
	char val;
};
struct table
{
	float freq;
	char val;
	char code[10];
};
typedef struct table TABLE;
typedef struct node* NODE;
void sort(NODE list[],int n) {
	NODE temp = (NODE) malloc(sizeof(struct node));
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-1-i; j++) {
			if(list[j]->freq > list[j+1]->freq)	{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}
void inorder(NODE root,char ch,char arr[],char cod[]) {
	if(root==NULL)
		return;
	int len = strlen(cod);
	if(root->val==ch)
		strcpy(arr,cod);
	char a[10]="";
	strcpy(a,cod);
	a[len]='0';
	inorder(root->left,ch,arr,a);
	char b[10]="";
	strcpy(b,cod);
	b[len]='1';
	inorder(root->right,ch,arr,b);
}