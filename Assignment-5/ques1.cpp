#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    // (a) Insertion at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    // (b) Insertion at end
    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // (c) Insert before/after a node with specific value
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
        }
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete specific node
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    // (g) Search
    void search(int key) {
        int pos = 1;
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not Found\n";
    }

    // (h) Display
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Node\n";
        cout << "8. Search Node\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter key and value: "; cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cout << "Enter key and value: "; cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteFromBeginning(); break;
            case 6: list.deleteFromEnd(); break;
            case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
            case 8: cout << "Enter key: "; cin >> key; list.search(key); break;
            case 9: list.display(); break;
        }
    } while (choice != 10);

    return 0;
}
