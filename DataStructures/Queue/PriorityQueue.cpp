#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int x, int p) {
        data = x;
        priority = p;
        next = nullptr;
    }
};

class LinkedPriorityQueue {
    Node* frontPtr;   // points to highest-priority (head of sorted list)
    int count;
public:
    // Constructor without shorthand initialization
    LinkedPriorityQueue() {
        frontPtr = nullptr;
        count = 0;
    }

    // Insert by priority (higher priority first, stable for equals)
    void enqueue(int x, int p) {
        Node* n = new Node(x, p);

        // Case 1: empty list or new node has higher priority than head
        if (frontPtr == nullptr || p > frontPtr->priority) {
            n->next = frontPtr;
            frontPtr = n;
        } else {
            // Traverse to find correct place
            Node* curr = frontPtr;
            while (curr->next != nullptr && curr->next->priority >= p) {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        count++;
    }

    void dequeue() {
        if (frontPtr == nullptr) {
            cout << "Priority queue is empty.\n";
            return;
        }
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        count--;
    }

    int top() {
        if (frontPtr == nullptr) throw runtime_error("Priority queue empty");
        return frontPtr->data;
    }

    int topPriority() {
        if (frontPtr == nullptr) throw runtime_error("Priority queue empty");
        return frontPtr->priority;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void traverse() {
        Node* t = frontPtr;
        while (t != nullptr) {
            cout << "(" << t->data << ", p=" << t->priority << ") ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedPriorityQueue pq;
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Enqueue (data, priority)\n";
        cout << "2. Dequeue (remove highest priority)\n";
        cout << "3. Show top element (highest priority)\n";
        cout << "4. Show top priority value\n";
        cout << "5. Check if empty\n";
        cout << "6. Show size\n";
        cout << "7. Traverse (data,priority)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x, p;
                cout << "Enter data: ";
                cin >> x;
                cout << "Enter priority (higher = sooner): ";
                cin >> p;
                pq.enqueue(x, p);
                break;
            }
            case 2:
                if (!pq.empty()) {
                    cout << "Dequeued: (" << pq.top() << ", p=" << pq.topPriority() << ")\n";
                    pq.dequeue();
                } else {
                    cout << "Priority queue is empty.\n";
                }
                break;
            case 3:
                if (!pq.empty()) {
                    cout << "Top element: " << pq.top() << endl;
                } else {
                    cout << "Priority queue is empty.\n";
                }
                break;
            case 4:
                if (!pq.empty()) {
                    cout << "Top priority: " << pq.topPriority() << endl;
                } else {
                    cout << "Priority queue is empty.\n";
                }
                break;
            case 5:
                cout << (pq.empty() ? "Empty" : "Not empty") << endl;
                break;
            case 6:
                cout << "Size: " << pq.size() << endl;
                break;
            case 7:
                if (!pq.empty()) pq.traverse();
                else cout << "Priority queue is empty.\n";
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
