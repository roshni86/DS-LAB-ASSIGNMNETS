#include<iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front, rear, capacity;
    
public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        cout << "Enqueued: " << x << endl;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return x;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    
    void display() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while(i != (rear + 1) % capacity);
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
    cout << "Enter circular queue capacity: ";
    cin >> capacity;
    
    CircularQueue q(capacity);
    int choice, value;
    
    do {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
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
                
            case 0:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 0);
    
    return 0;
}