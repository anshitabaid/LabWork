#include <stdio.h>
#include <stdlib.h>
#include "../headers/bintree.h"


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
	int r;
	printf ("Enter root:\t");
	scanf ("%d", &r);
	Node n = newNode (r);
	constructTree (n);
	inorder (n);
	printf ("\nDiameter %d\n", diameter (n));
}
