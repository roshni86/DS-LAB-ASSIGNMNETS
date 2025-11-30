#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List 
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Circular Linked List 
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (!head) return 0;

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void display() {
        if (!head) {
            cout << "Circular List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    DoublyLinkedList dlist;
    CircularLinkedList clist;

    dlist.insertAtEnd(10);
    dlist.insertAtEnd(20);
    dlist.insertAtEnd(30);

    clist.insertAtEnd(100);
    clist.insertAtEnd(200);
    clist.insertAtEnd(300);
    clist.insertAtEnd(400);

    cout << "\nDoubly Linked List:\n";
    dlist.display();
    cout << "Size of Doubly Linked List: " << dlist.getSize() << "\n";

    cout << "\nCircular Linked List:\n";
    clist.display();
    cout << "Size of Circular Linked List: " << clist.getSize() << "\n";

    return 0;
}
