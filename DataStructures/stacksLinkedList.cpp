#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class myStack {
    Node* top;
    
    int count;
    
public:
    myStack() {
        
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
        if (top == NULL) {
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
        if (top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

  
    bool isEmpty() {
        return top == NULL;
    }

    int size() {
        return count;
    }
};

int main() {
    myStack st;


    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    
    cout << "Popped: " << st.pop() << endl;

    // checking top element
    cout << "Top element: " << st.peek() << endl;

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << endl;

    // checking current size
    cout << "Current size: " << st.size() << endl;

    return 0;
}