#include<iostream>
using namespace std;
#define MAX 100
int stackarr[MAX];
int top = -1;
void push(int x)
{
    if(top==MAX-1)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    stackarr[top]=x;
}
void pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
        return;
    }
    cout << "Popped element: " << stackarr[top] << endl;
    top--;
}
bool isEmpty() {
    return (top == -1);
}

bool isFull(){
    return (top==MAX-1);
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackarr[i] << " ";
    }
    cout << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << stackarr[top] << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Peek (Top element)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                    cout << "Stack is Empty." << endl;
                else
                    cout << "Stack is NOT Empty." << endl;
                break;

            case 4:
                if (isFull())
                    cout << "Stack is Full." << endl;
                else
                    cout << "Stack is NOT Full." << endl;
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}