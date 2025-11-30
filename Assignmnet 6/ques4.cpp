#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

struct Node* makeNode(int v){
    struct Node *n = new Node;
    n->data = v; n->next = n->prev = NULL;
    return n;
}

void insertEnd(int v){
    struct Node *n = makeNode(v);
    if(!head){
        head=n;
        return;
    }
    struct Node *t=head;
    while(t->next) t=t->next;

    t->next=n;
    n->prev=t;
}

int isPalindrome(){
    if(!head) return 1;

    struct Node *l=head, *r=head;
    while(r->next) r=r->next;

    while(l!=r && r->next!=l){
        if(l->data != r->data)
            return 0;
        l=l->next;
        r=r->prev;
    }
    return 1;
}

int main(){
    insertEnd(1);
    insertEnd(2);
    insertEnd(2);
    insertEnd(1);

    if(isPalindrome()) printf("Palindrome\n");
    else printf("Not Palindrome\n");

    return 0;
}