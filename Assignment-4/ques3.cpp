#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size, capacity;
    
public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    void enqueue(int x) {
        if(size == capacity) return;
        rear++;
        arr[rear] = x;
        size++;
    }
    
    int dequeue() {
        if(size == 0) return -1;
        int x = arr[front];
        front++;
        size--;
        return x;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
};

void interleaveQueue(int arr[], int n) {
    Queue firstHalf(n/2);
    Queue secondHalf(n/2);
    
    for(int i = 0; i < n/2; i++) {
        firstHalf.enqueue(arr[i]);
    }
    
    for(int i = n/2; i < n; i++) {
        secondHalf.enqueue(arr[i]);
    }
    
    cout << "Original: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Interleaved: ";
    for(int i = 0; i < n/2; i++) {
        cout << firstHalf.dequeue() << " ";
        cout << secondHalf.dequeue() << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements (even number): ";
    cin >> n;
    
    if(n % 2 != 0) {
        cout << "Please enter even number of elements" << endl;
        return 0;
    }
    
    int* arr = new int[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    interleaveQueue(arr, n);
    
    return 0;
}