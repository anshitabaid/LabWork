#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
typedef struct node* NODE;

struct node {
	NODE l, r;
	int data, factor;
};

int max(int a, int b) {
	return (a > b ? a : b);
}

int height(NODE cur) {
	if (!cur)
		return 0;

	return 1 + max(height(cur->l), height(cur->r));
}
*/
void left_rotate(NODE cur, NODE par) {
	NODE right = cur->r, right_left = (cur->r)->l;

	(cur->r)->l = cur;
	cur->r = right_left;

	if (par) {
		if (par->l == cur)
			par->l = right;

		else
			par->r = right;
	}

	cur->factor = height(cur->l) - height(cur->r);
	right->factor = height(right->l) - height(right->r);
}

void right_rotate(NODE cur, NODE par) {
	NODE left = cur->l, left_right = (cur->l)->r;

	(cur->l)->r = cur;
	cur->l = left_right;

	if (par) {
		if (par->l == cur)
			par->l = left;

		else
			par->r = left;
	}

	cur->factor = height(cur->l) - height(cur->r);
	left->factor = height(left->l) - height(left->r);
}
/*
void calc(NODE root) {
	if (!root)
		return;

	calc(root->l);
	root->factor = height(root->l) - height(root->r);
	calc(root->r);
}*/

NODE insert(NODE root, int val) {
	NODE cur = root, prev = NULL;
	int dup = 0;

	// Insert Node
	while (cur) {
		prev = cur;

		if (cur->data == val) {
			printf("Duplicate value can't be inserted\n");
			dup = 1;
			break;
		}

		else if (cur->data > val)
			cur = cur->l;

		else
			cur = cur->r;
	}

	if (dup)
		return root;

	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->l = temp->r = NULL;
	temp->data = val;
	temp->factor = 0;

	if (prev == NULL)
		return temp;

	if (prev->data > temp->data)
		prev->l = temp;

	else
		prev->r = temp;

	// Find unbalanced node
	NODE par = NULL, z = root;
	cur = root;
	prev = NULL;

	while (cur != temp) {
		if (cur->data > temp->data) {
			cur->factor = height(cur->l) - height(cur->r);

			if (cur->factor > 1) {
				par = prev;
				z = cur;
			}

			prev = cur;
			cur = cur->l;
		}

		else {
			cur->factor = height(cur->l) - height(cur->r);

			if (cur->factor < -1) {
				par = prev;
				z = cur;
			}

			prev = cur;
			cur = cur->r;
		}
	}


	// Check for no unbalanced
	if (z->factor >= -1 && z->factor <= 1)
		return root;
	
	printf("%d unb %d\n", z->data, z->factor);

	NODE x, y;
	if (z->data > temp->data) {
		y = z->l;

		if (y->data > temp->data) {
			x = y->l;

			if (!par)
				root = y;

			printf("Right Rotation on %d\n", z->data);
			right_rotate(z, par);
		}

		else {
			x = y->r;

			printf("Left Rotation on %d\n", y->data);
			left_rotate(y, z);

			if (!par)
				root = y;

			printf("Right Rotation on %d\n", z->data);
			right_rotate(z, par);
		}
	}

	else {
		y = z->r;

		if (y->data > temp->data) {
			x = y->l;

			printf("Right Rotation on %d\n", y->data);
			right_rotate(y, z);

			if (!par)
				par = y;

			printf("Left Rotation on %d\n", z->data);
			left_rotate(z, par);
		}

		else {
			x = y->r;

			if (!par)
				root = y;

			printf("Left Rotation on %d\n", z->data);
			left_rotate(z, par);
		}
	}

	// Recalculate balance factor for all nodes
	calc(root);
	printf ("\n");
	preorder (root);
	return root;
}
/*
void preorder(NODE root) {
	if (!root)
		return;

	printf("Value: %d\tBalance Factor: %d\n", root->data, root->factor);
	preorder(root->l);
	preorder(root->r);
}*/

int main() {
	NODE root = NULL;
	int c = 1, temp;

	while (c) {
		printf("\n\n1. Insert element\n2. Print balance factor (preorder)\n3. Exit\n");
		scanf("%d", &c);

		if (c == 1) {
			printf("Enter element\n");
			scanf("%d", &temp);

			root = insert(root, temp);
		}

		else if (c == 2)
			preorder(root);

		else if (c == 3)
			c = 0;

		else {
			printf("Enter valid option\n");
			c = 3;
		}
	}

	return 0;
}