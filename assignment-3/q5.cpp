#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0'); // convert char to int
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;
    cout << "Result = " << evaluatePostfix(expr) << endl;
    return 0;
}
