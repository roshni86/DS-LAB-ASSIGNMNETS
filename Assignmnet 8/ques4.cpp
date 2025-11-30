#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x){
    struct Node *n = new  Node;
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int isBSTUtil(struct Node *root, int min, int max){
    if(root == NULL) return 1;

    if(root->data <= min || root->data >= max)
        return 0;

    return  isBSTUtil(root->left, min, root->data)
        &&  isBSTUtil(root->right, root->data, max);
}

int isBST(struct Node *root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    struct Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->right->left = newNode(15);

    if(isBST(root))
        printf("Tree IS a BST\n");
    else
        printf("Tree is NOT a BST\n");

    return 0;
}