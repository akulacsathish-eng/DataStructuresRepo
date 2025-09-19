#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        return isEmpty() ? -1 : arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}

