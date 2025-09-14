#include<iostream>
using namespace std;

class SimpleQueue {
    int* arr;
    int front, rear, size, capacity;
    
public:
    
    SimpleQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
        size++;
        cout << "Enqueued: " << x << endl;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        front++;
        size--;
        return x;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    void display() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    int capacity;
    cout << "Enter queue capacity: ";
    cin >> capacity;
    
    SimpleQueue q(capacity);
    int choice, value;
    
    do {
        cout << "\n--- Simple Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                value = q.dequeue();
                if(value != -1) {
                    cout << "Dequeued: " << value << endl;
                }
                break;
                
            case 3:
                value = q.peek();
                if(value != -1) {
                    cout << "Front element: " << value << endl;
                }
                break;
                
            case 4:
                q.display();
                break;
                
            case 5:
                if(q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;
                
            case 6:
                if(q.isFull()) {
                    cout << "Queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
                }
                break;
                
            case 7:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 7);
    
    return 0;
}