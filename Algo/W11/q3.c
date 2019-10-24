#include"q3.h"
int main()
{
	int n;
	char ch;
	float freq;

	printf("Enter number of symbols: \n");
	scanf("%d",&n);

	NODE list[10];
	TABLE arr[10];

	printf("Enter frequency and symbol: \n");
	for(int i=0; i<n; i++) {
		scanf("%f",&freq);
		scanf("%c",&ch);
		ch = getchar();

		arr[i].freq = freq;
		arr[i].val = ch;
		strcpy(arr[i].code,"");

		list[i] = (NODE) malloc(sizeof(struct node));
		list[i]->left = list[i]->right = NULL;
		list[i]->freq = freq;
		list[i]->val = ch;
	}

	int temp = n;

	while(temp>1) {
		sort(list,temp);
		NODE newnd = (NODE) malloc(sizeof(struct node));
		newnd->val = '\0';
		newnd->freq = list[0]->freq + list[1]->freq;
		newnd->left = list[0];
		newnd->right = list[1];
		list[0] = newnd;
		list[1] = list[--temp];
	}

	char cod[10];

	for(int i=0; i<n; i++) {
		strcpy(cod,"");
		inorder(list[0],arr[i].val,arr[i].code,cod);
		printf("%c ",arr[i].val);
		puts(arr[i].code);
	}
}
