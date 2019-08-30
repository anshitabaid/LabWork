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
	Node n = newNode (1);
	constructTree (n);
	inorder (n);
	printf ("Diameter %d\n", diameter (n));
}
