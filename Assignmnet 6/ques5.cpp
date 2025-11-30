#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* makeNode(int v){
    struct Node *n = new Node();
    n->data = v; n->next = NULL;
    return n;
}
void insert(int v){
    struct Node *n = makeNode(v);
    if(!head){ head=n; return; }
    struct Node *t=head;
    while(t->next) t=t->next;
    t->next=n;
}
int isCircular(struct Node *h){
    if(!h) return 0;

    struct Node *t=h->next;
    while(t!=NULL && t!=h){
        t=t->next;
    }
    return (t==h);
}

int main(){
    insert(10);
    insert(20);
    insert(30);
 if(isCircular(head))
        printf("Circular\n");
    else
        printf("Not circular\n");

    return 0;
}