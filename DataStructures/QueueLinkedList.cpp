#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedQueue {
    Node* frontPtr;
    Node* rearPtr;
    int count;
public:
  
    LinkedQueue() {
        frontPtr = nullptr;
        rearPtr = nullptr;
        count = 0;
    }
    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rearPtr == nullptr) {
            frontPtr = rearPtr = temp;
        } else {
            rearPtr->next = temp;
            rearPtr = temp;
        }
        count++;
    }
    void dequeue() {
        if (frontPtr == nullptr) return;
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) rearPtr = nullptr;
        delete temp;
        count--;
    }
    int front() {
        if (frontPtr == nullptr) throw runtime_error("Queue empty");
        return frontPtr->data;
    }
    int back() {
        if (rearPtr == nullptr) throw runtime_error("Queue empty");
        return rearPtr->data;
    }
    bool empty() { return count == 0; }
    int size() { return count; }
    void traverse() {
        Node* temp = frontPtr;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
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
