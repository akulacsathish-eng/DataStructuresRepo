#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

class myStack {
    Node* top;
    int count;
public:
    myStack() {
        top = NULL;
        count = 0;
    }

    void push(char x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        count++;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';
        }
        Node* temp = top;
        top = top->next;
        char val = temp->data;
        count--;
        delete temp;
        return val;
    }

    char peek() {
        if (top == nullptr) {
            return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return count;
    }
};

bool isOpen(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isClose(char c) {
    return (c == ')' || c == '}' || c == ']');
}

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(const string& expr) {
    myStack st;
    for (char c : expr) {
        if (isOpen(c)) {
            st.push(c);
        } else if (isClose(c)) {
            if (st.isEmpty()) return false;
            char topChar = st.pop();
            if (!matches(topChar, c)) return false;
        }
    }
    return st.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (checkBalanced(expr)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
