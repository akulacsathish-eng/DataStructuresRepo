#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedQueue {
    Node* frontPtr;
    Node* rearPtr;

    // recursive helper for enqueue
    void enqueue(Node*& cur, int x) {
        if (cur == nullptr) {
            cur = new Node(x);
            rearPtr = cur;
            return;
        }
        if (cur->next == nullptr) {
            cur->next = new Node(x);
            rearPtr = cur->next;
            return;
        }
        enqueue(cur->next, x);
    }

    // recursive helper for dequeue
    void dequeue(Node*& cur) {
        if (cur == nullptr) return;
        if (cur == frontPtr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
            frontPtr = cur;
            if (frontPtr == nullptr) rearPtr = nullptr;
            return;
        }
        dequeue(cur->next);
    }

    // recursive size
    int size(Node* cur) {
        if (cur == nullptr) return 0;
        return 1 + size(cur->next);
    }

    // recursive traverse
    void traverse(Node* cur) {
        if (cur == nullptr) {
            cout << "\n";
            return;
        }
        cout << cur->data << " ";
        traverse(cur->next);
    }

public:
    LinkedQueue() : frontPtr(nullptr), rearPtr(nullptr) {}

    void enqueue(int x) { enqueue(frontPtr, x); }
    void dequeue() { dequeue(frontPtr); }

    int front() {
        if (frontPtr == nullptr) throw runtime_error("Queue empty");
        return frontPtr->data;
    }

    int back() {
        if (rearPtr == nullptr) throw runtime_error("Queue empty");
        return rearPtr->data;
    }

    bool empty() { return frontPtr == nullptr; }
    int size() { return size(frontPtr); }
    void traverse() { traverse(frontPtr); }
};

int main() {
    LinkedQueue q;
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Enqueue (push)\n";
        cout << "2. Dequeue (pop)\n";
        cout << "3. Show front element\n";
        cout << "4. Show back element\n";
        cout << "5. Check if queue is empty\n";
        cout << "6. Show size of queue\n";
        cout << "7. Traverse queue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int x;
                cout << "Enter element to enqueue: ";
                cin >> x;
                q.enqueue(x);
                break;
            }
            case 2:
                if (!q.empty()) {
                    cout << "Dequeued: " << q.front() << endl;
                    q.dequeue();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 3:
                if (!q.empty()) {
                    cout << "Front element: " << q.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 4:
                if (!q.empty()) {
                    cout << "Back element: " << q.back() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 5:
                cout << (q.empty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 6:
                cout << "Size of queue: " << q.size() << endl;
                break;
            case 7:
                if (!q.empty()) {
                    q.traverse();
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}
