#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NODE create(NODE root, int val) {
	if (!root) {
		root = (NODE)malloc(sizeof(struct node));
		root->l = root->r = NULL;
		root->data = val;
		root->factor = 0;
		root->dup = 0;
	}

	else if (root->data == val) {
		printf("Duplicate Value Cannot Be Inserted\n");
		root->dup = 1;
	}

	else if (root->data > val) {
		root->l = create(root->l, val);

		if ((root->l)->dup)
			root->dup = 1;

		else {
			root->dup = 0;
			root->factor = height(root->l) - height(root->r);
		}
	}

	else {
		root->r = create(root->r, val);

		if ((root->r)->dup)
			root->dup = 1;

		else {
			root->dup = 0;
			root->factor = height(root->l) - height(root->r);
		}
	}

	calc(root);

	return root;
}

int main() {
	NODE root = NULL;
	int c = 1, temp;

	while (c) {
		printf("\n\n1. Insert element\n2. Print balance factor (preorder)\n3. Exit\n");
		scanf("%d", &c);

		if (c == 1) {
			printf("Enter element\n");
			scanf("%d", &temp);

			root = create(root, temp);
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