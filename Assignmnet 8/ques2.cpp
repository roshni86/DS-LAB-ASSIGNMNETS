#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x){
    struct Node *n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    return n;
}
struct Node* insert(struct Node *root, int x){
    if(root == NULL) return newNode(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}
struct Node* searchRec(struct Node *root, int key){
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}
struct Node* searchNonRec(struct Node *root, int key){
    while(root != NULL){
        if(key == root->data) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
int bstMax(struct Node *root){
    if(root == NULL) return -1;
    while(root->right) root = root->right;
    return root->data;
}
int bstMin(struct Node *root){
    if(root == NULL) return -1;
    while(root->left) root = root->left;
    return root->data;
}
struct Node* inorderSuccessor(struct Node *root, struct Node *x){
    struct Node *succ = NULL;

    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
struct Node* inorderPredecessor(struct Node *root, struct Node *x){
    struct Node *pred = NULL;

    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main(){
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 35);

    struct Node *node = searchRec(root, 15);

    printf("Min: %d\n", bstMin(root));
    printf("Max: %d\n", bstMax(root));

    struct Node *s = inorderSuccessor(root, node);
    if(s) printf("Successor of 15 = %d\n", s->data);

    struct Node *p = inorderPredecessor(root, node);
    if(p) printf("Predecessor of 15 = %d\n", p->data);

    return 0;
}