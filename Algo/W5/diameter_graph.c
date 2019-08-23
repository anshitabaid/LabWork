#include <stdio.h>
#include <stdlib.h>

 
typedef struct node 
{
	int data;
	struct node * left;
	struct node * right;
}*Node;

Node newNode (int d)
{
	Node n = (Node)malloc (sizeof (struct node));
	n->data=d;
	n->left=n->right=NULL;
	return n;
}

void constructTree (Node root)
{
	int n;
	printf ("Enter left and right children\n");
	scanf ("%d", &n);
	if (n!=-1)
		root->left = newNode (n);
	scanf ("%d", &n);
	if (n!=-1)
		root->right = newNode (n);
	if (root->left)		
		constructTree (root->left);
	if (root->right)
		constructTree (root->right);

}

void inorder (Node root)
{
	if(root){
		inorder (root->left);
		printf ("%d\t", root->data);
		inorder (root->right);
	}
}

int max (int a, int b)
{
	if (a>b) return a;
	return b;
}

int height (Node root)
{
	if (!root)
		return 0;
	return 1 + max (height(root->left), height (root->right));
}

int diameter (Node root)
{
	if (!root)
		return 0;
	int ld = diameter (root->left);
	int rd = diameter (root->right);
	
	int current = height(root->left)+height (root->right)+1;
	return max (max (ld, rd), current);
	//return current;


}

int main ()
{
	Node n = newNode (1);
	constructTree (n);
	inorder (n);
	printf ("Diameter %d\n", diameter (n));
}