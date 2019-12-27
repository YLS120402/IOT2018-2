#include "bst.h"


struct node *newNode(int n)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        printf("Error!\n");
        exit(-1);
    }
    p->key = n;
    p->left = p->right = NULL;
    return p;
}

struct node *insert(struct node *root, int n)
{
    if(root == NULL){
        return newNode(n);
    }
    if (root->key > n)
    {
        root->left = insert(root->left, n);
    }
    else if (root->key < n)
    {
        root->right = insert(root->right, n);
    }
    else
    {
        return root;
    }
}

void inOrder(struct node *root)
{
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    if(root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

