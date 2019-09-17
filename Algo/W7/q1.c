#include "../headers/bintree.h"

Node rightRotate (Node root)
{
    Node r = root->left;
    Node temp = r->right;
    root->left = temp;
    r->right = root;

    return r;

}

void createTree (Node root, int key)
{
    if (!root)
        return newNode (key);

    if (key<root->data)
        root->left = createTree (root->left, key);

    else if (key > root->data)
        root->right = createTree (root->right, key);


    int balance = findBalance (root);

    //right rotation
    if (balance>1 && key < root->left->data)
        return rightRotate (root);
    //left rotate
    if (balance<1  && key > root->right->data)
        return leftRotate (root);
}

int main ()
{

}