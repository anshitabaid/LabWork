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
	n->data = d;
	n->left = NULL;
	n->right = NULL;
}

Node insert (Node root, int d)
{
	if (!root)
		return newNode (d);
	if (d==root->data)
	{
		printf ("key found");
		return NULL;
	}
	if (d<root->data)
		root->left = insert (root->left, d);
	else if (d>root->data)
		root->right = insert (root->right, d);
	return root;

}

void inorder (Node root)
{
	if(root){
		inorder (root->left);
		printf ("%d\t", root->data);
		inorder (root->right);
	}
}

void preorder (Node root)
{
	if (root){
		printf ("%d\t", root->data);
		preorder (root->left);
		preorder (root->right);
	}
}

void postorder (Node root)
{
	if (root){
		postorder (root->left);
		postorder (root->right);
		printf ("%d\t", root->data);
	}
}


int main ()
{
	Node root=NULL;
	int d;
	printf ("Enter numbers, 0 to quit\n");
	while (1)
	{
		scanf ("%d", &d);
		if (d==0)
			break;
		root=insert (root, d);
	}

	printf ("\nInorder:\n");
	inorder (root);

	printf ("\nPreorder:\n");
	preorder (root);

	printf ("\nPostorder:\n");
	postorder (root);
}