#include <iostream>
using namespace std;

// Doubly Linked List (DLL)
// Uses head and tail pointers.
// Positions are 1-based: position 1 is the first node.
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    // ------------------------------------------------------------
    // Traverse Forward
    // ------------------------------------------------------------
    void traverseForward() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data;

            if (current->next != nullptr)
                cout << " <-> ";

            current = current->next;
        }

        cout << '\n';
    }

    // ------------------------------------------------------------
    // Traverse Backward
    // ------------------------------------------------------------
    void traverseBackward() const {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = tail;

        while (current != nullptr) {
            cout << current->data;

            if (current->prev != nullptr)
                cout << " <-> ";

            current = current->prev;
        }

        cout << '\n';
    }

    // ------------------------------------------------------------
    // Insert at Beginning
    // ------------------------------------------------------------
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // ------------------------------------------------------------
    // Insert at End
    // ------------------------------------------------------------
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // ------------------------------------------------------------
    // Insert at Position
    // Valid positions: 1 through size()+1
    // ------------------------------------------------------------
    bool insertAtPosition(int position, int value) {
        if (position < 1)
            return false;

        if (position == 1) {
            insertBeginning(value);
            return true;
        }

        if (head == nullptr)
            return false;

        Node* current = head;
        int currentPosition = 1;

        // Move to node at position - 1.
        while (currentPosition < position - 1 &&
               current->next != nullptr) {
            current = current->next;
            currentPosition++;
        }

        if (currentPosition != position - 1)
            return false;

        // If inserting after current tail, use insertEnd().
        if (current == tail) {
            insertEnd(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* nextNode = current->next;

        newNode->prev = current;
        newNode->next = nextNode;

        current->next = newNode;
        nextNode->prev = newNode;

        return true;
    }

    // ------------------------------------------------------------
    // Delete at Beginning
    // ------------------------------------------------------------
    bool deleteBeginning() {
        if (head == nullptr)
            return false;

        Node* oldHead = head;

        // One-node list.
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            delete oldHead;
            return true;
        }

        head = head->next;
        head->prev = nullptr;

        delete oldHead;
        return true;
    }

    // ------------------------------------------------------------
    // Delete at End
    // ------------------------------------------------------------
    bool deleteEnd() {
        if (tail == nullptr)
            return false;

        Node* oldTail = tail;

        // One-node list.
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            delete oldTail;
            return true;
        }

        tail = tail->prev;
        tail->next = nullptr;

        delete oldTail;
        return true;
    }

    // ------------------------------------------------------------
    // Delete at Position
    // Valid positions: 1 through size()
    // ------------------------------------------------------------
    bool deleteAtPosition(int position) {
        if (head == nullptr || position < 1)
            return false;

        if (position == 1)
            return deleteBeginning();

        Node* current = head->next;
        int currentPosition = 2;

        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr || currentPosition != position)
            return false;

        if (current == tail)
            return deleteEnd();

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        return true;
    }

    // ------------------------------------------------------------
    // Search
    // Returns the 1-based position of the first matching value.
    // Returns -1 if the value is not found.
    // ------------------------------------------------------------
    int search(int value) const {
        Node* current = head;
        int position = 1;

        while (current != nullptr) {
            if (current->data == value)
                return position;

            current = current->next;
            position++;
        }

        return -1;
    }

    // ------------------------------------------------------------
    // Get
    // Gets the value stored at a 1-based position.
    // Returns true on success and false for an invalid position.
    // ------------------------------------------------------------
    bool get(int position, int& value) const {
        if (position < 1)
            return false;

        Node* current = head;
        int currentPosition = 1;

        while (current != nullptr) {
            if (currentPosition == position) {
                value = current->data;
                return true;
            }

            current = current->next;
            currentPosition++;
        }

        return false;
    }

    // ------------------------------------------------------------
    // Clear
    // ------------------------------------------------------------
    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "INSERT OPERATIONS\n";
    list.insertBeginning(20);
    list.insertBeginning(10);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertAtPosition(3, 25);

    cout << "Forward:  ";
    list.traverseForward();

    cout << "Backward: ";
    list.traverseBackward();

    cout << "\nSEARCH / GET\n";
    cout << "30 found at position: " << list.search(30) << '\n';

    int value;
    if (list.get(3, value))
        cout << "Value at position 3: " << value << '\n';

    cout << "\nDELETE OPERATIONS\n";

    list.deleteBeginning();
    cout << "After deleteBeginning(): ";
    list.traverseForward();

    list.deleteEnd();
    cout << "After deleteEnd():       ";
    list.traverseForward();

    list.deleteAtPosition(2);
    cout << "After deleteAtPosition(2): ";
    list.traverseForward();

    return 0;
}
