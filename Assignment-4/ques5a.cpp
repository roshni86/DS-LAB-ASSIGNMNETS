#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);                     // Step 1: Push into q2
        while (!q1.empty()) {           // Step 2: Move everything from q1 → q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);                   // Step 3: Swap q1 and q2
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackTwoQueues st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl; // 30
    st.pop();
    cout << st.top() << endl; // 20
}
