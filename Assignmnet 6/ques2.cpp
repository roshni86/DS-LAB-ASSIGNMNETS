#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;  
};

// Circular Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int data) {
        if (!head) return;

        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node{data, temp->next, nullptr};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int key) {
        if (!head) return;

        Node *curr = head, *prev = nullptr;

        while (curr->data != key) {
            if (curr->next == head) return;  
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = head->next;
            delete head;
            head = temp->next;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    bool search(int key) {
        if (!head) return false;

        Node* temp = head;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);

        return false;
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
// Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, head, nullptr};
        if (head)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
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

    void insertAfter(int key, int data) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) return;

        Node* newNode = new Node{data, temp->next, temp};
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int data) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) return;

        Node* newNode = new Node{data, temp, temp->prev};
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "Doubly List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    CircularLinkedList circularList;
    DoublyLinkedList doublyList;

    int choice, listType;
    int value, key;

    while (true) {
        cout << "Select List Type:\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        if (listType == 2) cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "8. Back to List Selection\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            (listType == 1) ? circularList.insertAtBeginning(value) : doublyList.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            (listType == 1) ? circularList.insertAtEnd(value) : doublyList.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter key after which to insert: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            (listType == 1) ? circularList.insertAfter(key, value) : doublyList.insertAfter(key, value);
            break;
        case 4:
            if (listType == 2) {
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                doublyList.insertBefore(key, value);
            } else {
                cout << "Invalid choice for Circular List.\n";
            }
            break;
        case 5:
            cout << "Enter node value to delete: ";
            cin >> key;
            (listType == 1) ? circularList.deleteNode(key) : doublyList.deleteNode(key);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> key;
            if ((listType == 1 && circularList.search(key)) || (listType == 2 && doublyList.search(key)))
                cout << "Node found.\n";
            else
                cout << "Node not found.\n";
            break;
        case 7:
            (listType == 1) ? circularList.display() : doublyList.display();
            break;
        case 8:
            continue;
        default:
            cout << "Invalid option.\n";
        }
    }

    cout << "Program exited.\n";
    return 0;
}
