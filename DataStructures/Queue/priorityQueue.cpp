#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
    Node* prev;

    Node(int x, int p) {
        data = x;
        priority = p;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedPriorityQueue {
private:
    Node* frontPtr;
    Node* rearPtr;
    int count;

public:
    DoublyLinkedPriorityQueue() {
        frontPtr = nullptr;
        rearPtr = nullptr;
        count = 0;
    }

    void enqueue(int x, int p) {

        Node* n = new Node(x, p);


        if (frontPtr == nullptr) {
            frontPtr = rearPtr = n;
        }

        else if (p > frontPtr->priority) {
            n->next = frontPtr;
            frontPtr->prev = n;
            frontPtr = n;
        }

        else if (p <= rearPtr->priority) {
            rearPtr->next = n;
            n->prev = rearPtr;
            rearPtr = n;
        }

        else {
            Node* curr = frontPtr;

            while (curr->next != nullptr &&
                   curr->next->priority >= p) {
                curr = curr->next;
            }

            n->next = curr->next;

            if (curr->next != nullptr) {
                curr->next->prev = n;
            }

            curr->next = n;
            n->prev = curr;
        }

        count++;
    }

    void dequeue() {

  
        if (frontPtr == nullptr) {
            return;
        }

        Node* temp = frontPtr;

  
        if (frontPtr == rearPtr) {
            frontPtr = nullptr;
            rearPtr = nullptr;
        }


        else {
            frontPtr = frontPtr->next;
            frontPtr->prev = nullptr;
        }

        delete temp;
        count--;
    }

    void display() {

        Node* curr = frontPtr;

        while (curr != nullptr) {
            cout << "Data: " << curr->data
                 << ", Priority: " << curr->priority
                 << endl;

            curr = curr->next;
        }
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }

    int size() {
        return count;
    }
};


int main() {

    DoublyLinkedPriorityQueue pq;

    pq.enqueue(10, 3);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);

    cout << "Priority Queue:" << endl;
    pq.display();

    cout << "\nAfter Dequeue:" << endl;

    pq.dequeue();

    pq.display();

    return 0;
}
