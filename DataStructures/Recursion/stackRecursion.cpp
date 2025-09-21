#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class myStack {
    Node* top;

    // recursive size
    int sizeRec(Node* node) {
        if (node == nullptr) return 0;        // base
        return 1 + sizeRec(node->next);       // recursive call
    }

    // recursive push (adds to front, by reference)
    void pushRec(Node*& head, int x) {
        if (head == nullptr) {                // base
            head = new Node(x);
            return;
        }
        pushRec(head->next, x);               // recursive call
    }

    // recursive pop (removes last added node)
    int popRec(Node*& head) {
        if (head == nullptr) return -1;       // base (empty)
        if (head->next == nullptr) {          // base (last node)
            int val = head->data;
            delete head;
            head = nullptr;
            return val;
        }
        return popRec(head->next);            // recursive call
    }

    // recursive peek (last added node)
    int peekRec(Node* node) {
        if (node == nullptr) return -1;       // base (empty)
        if (node->next == nullptr)            // base (last)
            return node->data;
        return peekRec(node->next);           // recursive call
    }

public:
    myStack() : top(nullptr) {}

    void push(int x) { pushRec(top, x); }
    int pop() { return popRec(top); }
    int peek() { return peekRec(top); }
    bool isEmpty() { return top == nullptr; }
    int size() { return sizeRec(top); }
};

int main() {
    myStack st;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if empty\n";
        cout << "5. Check size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int x;
                cout << "Enter value to push: ";
                cin >> x;
                st.push(x);
                break;
            }
            case 2:
                if (!st.isEmpty()) {
                    cout << "Popped: " << st.pop() << endl;
                } else {
                    cout << "Stack Underflow" << endl;
                }
                break;
            case 3:
                if (!st.isEmpty()) {
                    cout << "Top element: " << st.peek() << endl;
                } else {
                    cout << "Stack is Empty" << endl;
                }
                break;
            case 4:
                cout << (st.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << "Current size: " << st.size() << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
