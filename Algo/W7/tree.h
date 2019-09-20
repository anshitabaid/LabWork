typedef struct node* NODE;

struct node {
	NODE l, r;
	int data, factor, dup;
};

int max(int a, int b) {
	return (a > b ? a : b);
}

int height(NODE cur) {
	if (!cur)
		return 0;

	return 1 + max(height(cur->l), height(cur->r));
}

void calc(NODE root) {
	if (!root)
		return;

	calc(root->l);
	root->factor = height(root->l) - height(root->r);
	calc(root->r);
}

void preorder(NODE root) {
	if (!root)
		return;

	printf("Value: %d\tBalance Factor: %d\n", root->data, root->factor);
	preorder(root->l);
	preorder(root->r);
}