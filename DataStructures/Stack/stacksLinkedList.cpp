#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int x)
     {
        data = x;
        next = NULL;
     }

};

class myStack {
    Node* top;
    int count;
public:
   myStack()
     {
        // initially stack is empty
        top = NULL;
        count = 0;
     }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        count++;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int val = temp->data;
        count--;
        delete temp;
        return val;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
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
