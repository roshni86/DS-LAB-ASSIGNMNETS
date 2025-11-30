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
struct Node* minNode(struct Node *node){
    while(node->left != NULL)
        node = node->left;
    return node;
}

struct Node* deleteNode(struct Node *root, int key){
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL){
            struct Node *t = root->right;
            free(root);
            return t;
        }
        else if(root->right == NULL){
            struct Node *t = root->left;
            free(root);
            return t;
        }
        struct Node *t = minNode(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}
int maxDepth(struct Node *root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}
int minDepth(struct Node *root){
    if(root == NULL) return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if(l == 0 || r == 0)   // handle skewed case
        return l + r + 1;

    return (l < r ? l : r) + 1;
}
void inorder(struct Node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);

    root = deleteNode(root, 30);

    printf("\nInorder after deletion: ");
    inorder(root);

    printf("\nMax Depth = %d", maxDepth(root));
    printf("\nMin Depth = %d", minDepth(root));

    return 0;
}