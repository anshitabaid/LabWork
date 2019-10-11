#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* next;
    int data;
}NODE;
int comp = 0;
NODE* getNode(int data){
    NODE* t = (NODE*)malloc(sizeof(NODE));
    t->data = data;
    t->next = NULL;
}
void insert(NODE* head, int data){
    NODE* t = getNode(data);
    NODE* p = head;
    while(p->next!=NULL)
        p = p->next;
    p->next = t;
    return;
}
int search(NODE* table[], int x, int m){
    int k = x%m;
    NODE* p = table[k]->next;
    while(p!=NULL){
        comp++;
        if(p->data==x)
            return 1;
        else
            p = p->next;
    }
    return 0;
}

void main(){
    printf("Enter m(no. of buckets)\n");
    int m;
    scanf("%d", &m);
    NODE* table[m];
    for(int i = 0; i<m;i++){
        table[i] = getNode(i);//make header nodes with hash function range as data
    }
    printf("Enter all values into hash table(-1 to stop).\n");
    int t, k;
    for(int i = 0;;i++){
        scanf("%d", &t);
        if(t==-1)
            break;
        k = t%m;
        insert(table[k], t);
    } 
    while(1){
        comp = 0;
        printf("Enter value to be searched.\n");
        int x;
        scanf("%d", &x);

        if(x==-1)
            break;

        if(search(table, x, m))
            printf("Search successful");
        else
            printf("Search unsuccessful");
        printf("\nNumber of key comparisons: %d\n", comp);
    }
}