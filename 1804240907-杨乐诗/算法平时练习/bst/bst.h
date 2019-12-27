#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<stdio.h>
#include <stdlib.h>
struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int n);
struct node *insert(struct node *root, int n);
void inOrder(struct node *root);
void preOrder(struct node *root);


#endif // BST_H_INCLUDED
