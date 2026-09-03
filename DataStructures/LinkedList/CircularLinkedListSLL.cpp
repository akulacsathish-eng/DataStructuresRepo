#include <iostream>
using namespace std;

// Circular Singly Linked List (CSLL)
// Uses only a head pointer. No separate tail pointer is required.
class CircularSinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int v) : data(v), next(nullptr) {}
    };

    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    ~CircularSinglyLinkedList() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
    }

    // Insert after the first occurrence of target
    bool insertAfter(int target, int value) {
        if (head == nullptr) {
            return false;
        }

        Node* current = head;

        do {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
                return true;
            }

            current = current->next;
        } while (current != head);

        return false;
    }

    // Delete from beginning
    bool deleteBeginning() {
        if (head == nullptr) {
            return false;
        }

        // One-node list
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        Node* oldHead = head;
        head = head->next;
        last->next = head;

        delete oldHead;
        return true;
    }

    // Delete from end
    bool deleteEnd() {
        if (head == nullptr) {
            return false;
        }

        // One-node list
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }

        Node* previous = nullptr;
        Node* current = head;

        while (current->next != head) {
            previous = current;
            current = current->next;
        }

        previous->next = head;
        delete current;
        return true;
    }

    // Delete the first occurrence of value
    bool deleteValue(int value) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == value) {
            return deleteBeginning();
        }

        Node* previous = head;
        Node* current = head->next;

        while (current != head) {
            if (current->data == value) {
                previous->next = current->next;
                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    // Search for a value
    bool search(int value) const {
        if (head == nullptr) {
            return false;
        }

        Node* current = head;

        do {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        } while (current != head);

        return false;
    }

    // Forward traversal
    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        do {
            cout << current->data;
            current = current->next;

            if (current != head) {
                cout << " -> ";
            }
        } while (current != head);

        cout << " -> (back to head)\n";
    }

    // Remove all nodes
    void clear() {
        if (head == nullptr) {
            return;
        }

        Node* current = head->next;

        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete head;
        head = nullptr;
    }
};

int main() {
    CircularSinglyLinkedList list;

    list.insertBeginning(20);
    list.insertBeginning(10);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Initial list:\n";
    list.display();

    list.insertAfter(20, 25);
    cout << "\nAfter inserting 25 after 20:\n";
    list.display();

    cout << "\nSearch 30: "
         << (list.search(30) ? "Found" : "Not found") << '\n';

    list.deleteBeginning();
    cout << "\nAfter deleting beginning:\n";
    list.display();

    list.deleteEnd();
    cout << "\nAfter deleting end:\n";
    list.display();

    list.deleteValue(25);
    cout << "\nAfter deleting 25:\n";
    list.display();

    return 0;
}
