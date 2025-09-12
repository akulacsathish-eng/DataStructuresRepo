#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(nullptr), next(nullptr) {}
};

void insertAtBeginning(Node*& head, Node*& tail, int value) {
    Node* n = new Node(value);
    if (!head) {
        head = tail = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* n = new Node(value);
    if (!tail) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

bool deleteAtBeginning(Node*& head, Node*& tail) {
    if (!head) return false;
    Node* d = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete d;
    return true;
}

bool deleteAtEnd(Node*& head, Node*& tail) {
    if (!tail) return false;
    Node* d = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete d;
    return true;
}

void displayForward(Node* head) {
    for (Node* t = head; t; t = t->next) {
        cout << t->data << (t->next ? " <-> " : "");
    }
    cout << "\n";
}

void displayBackward(Node* tail) {
    for (Node* t = tail; t; t = t->prev) {
        cout << t->data << (t->prev ? " <-> " : "");
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice, value;

    do {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete at beginning\n";
        cout << "4. Delete at end\n";
        cout << "5. Display forward\n";
        cout << "6. Display backward\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, tail, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, tail, value);
                break;
            case 3:
                if (!deleteAtBeginning(head, tail))
                    cout << "List is empty.\n";
                break;
            case 4:
                if (!deleteAtEnd(head, tail))
                    cout << "List is empty.\n";
                break;
            case 5:
                cout << "Forward : ";
                displayForward(head);
                break;
            case 6:
                cout << "Backward: ";
                displayBackward(tail);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
