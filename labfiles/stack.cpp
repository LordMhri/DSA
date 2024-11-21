#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

template<typename T>
class stack
{
private:
    int top = -1; //keep track of the top element
    T arr[1000]; //size of array
    int size = sizeof(arr) / sizeof(T);

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    bool isOperator(char c) {
        return (!isalpha(c) && !isdigit(c));
    }

public:
    stack() {
        top = -1;
    }

    void push(T x){
        if (top < size - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack size exceeded";
        } 
    }

    void pop() {
        if (top < 0)
            cout << "Stack is empty";
        else {
            top -= 1;
        }
    }

    T topElement() {
        if (top >= 0) {
            return arr[top];
        }
        throw out_of_range("Stack is empty");
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    string infixToPostfix(string infix) {
        stack<char> s;
        string postfix = "";
        for (char &ch : infix) {
            if (isalnum(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                s.push(ch);
            } else if (ch == ')') {
                while (!s.empty() && s.topElement() != '(') {
                    postfix += s.topElement();
                    s.pop();
                }
                s.pop();
            } else {
                while (!s.empty() && precedence(s.topElement()) >= precedence(ch)) {
                    postfix += s.topElement();
                    s.pop();
                }
                s.push(ch);
            }
        }
        while (!s.empty()) {
            postfix += s.topElement();
            s.pop();
        }
        return postfix;
    }

    int evaluatePostfix(string postfix) {
        stack<int> s;
        for (char &ch : postfix) {
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else {
                int val1 = s.topElement(); s.pop();
                int val2 = s.topElement(); s.pop();
                switch (ch) {
                    case '+': s.push(val2 + val1); break;
                    case '-': s.push(val2 - val1); break;
                    case '*': s.push(val2 * val1); break;
                    case '/': s.push(val2 / val1); break;
                    case '^': s.push(pow(val2, val1)); break;
                }
            }
        }
        return s.topElement();
    }

    bool empty() {
        return top == -1;
    }
};

int main(int argc, char const *argv[])
{
    stack<int> st;
    for (int i = 0; i < 5; i++) {
        st.push(i * 2);
    }

    st.display();

    stack<char> stChar;
    string infix = "3+(2*2)^2";
    string postfix = stChar.infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << stChar.evaluatePostfix(postfix) << endl;

    return 0;
}
