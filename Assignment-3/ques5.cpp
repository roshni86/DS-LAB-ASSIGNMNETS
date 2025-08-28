#include <iostream>
#include <stack>
using namespace std;
//postfix expression is usually written as 23*5+
int main() {
    string exp;
    cout << "Enter Postfix Expression: ";
    cin >> exp;

    stack<int> st;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');   
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }

    cout << "Result = " << st.top();
    return 0;
}
