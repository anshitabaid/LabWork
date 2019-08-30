#include <stdio.h>
#include <string.h>
#include "../headers/bintree.h"
int opcount = 0;
int countNodes (Node root)
{
	if (!root)
		return 0;
	int ln = countNodes (root->left);
	int rn = countNodes (root->right);
	opcount++;
	return 1 + ln + rn;
}

int main ()
{
	int n;
	printf ("Enter root:\t");
	scanf ("%d", &n);
	Node root = newNode (n);
	constructTree (root);
	n = countNodes (root);
	printf ("Number of nodes:\t%d\nOpcount\t%d\n", n, opcount);
}