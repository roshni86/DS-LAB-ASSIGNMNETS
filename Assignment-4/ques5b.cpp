#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQueue st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl; // 30
    st.pop();
    cout << st.top() << endl; // 20
}
