#include <iostream>
using namespace std;

// Circular Doubly Linked List (CDLL)
// Uses only a head pointer.
// The last node is always available as head->prev.
class CircularDoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int v) : data(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    ~CircularDoublyLinkedList() {
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
            head->next = head;
            head->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
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
                Node* nextNode = current->next;

                newNode->prev = current;
                newNode->next = nextNode;

                current->next = newNode;
                nextNode->prev = newNode;

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

        Node* last = head->prev;
        Node* oldHead = head;

        head = head->next;

        head->prev = last;
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

        Node* last = head->prev;
        Node* newLast = last->prev;

        newLast->next = head;
        head->prev = newLast;

        delete last;
        return true;
    }

    // Delete the first occurrence of value
    bool deleteValue(int value) {
        if (head == nullptr) {
            return false;
        }

        Node* current = head;

        do {
            if (current->data == value) {
                if (current == head) {
                    return deleteBeginning();
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                return true;
            }

            current = current->next;
        } while (current != head);

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
    void displayForward() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;

        do {
            cout << current->data;
            current = current->next;

            if (current != head) {
                cout << " <-> ";
            }
        } while (current != head);

        cout << " <-> (back to head)\n";
    }

    // Backward traversal
    void displayBackward() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* last = head->prev;
        Node* current = last;

        do {
            cout << current->data;
            current = current->prev;

            if (current != last) {
                cout << " <-> ";
            }
        } while (current != last);

        cout << " <-> (back to last)\n";
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
    CircularDoublyLinkedList list;

    list.insertBeginning(20);
    list.insertBeginning(10);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Initial list (forward):\n";
    list.displayForward();

    cout << "\nInitial list (backward):\n";
    list.displayBackward();

    list.insertAfter(20, 25);
    cout << "\nAfter inserting 25 after 20:\n";
    list.displayForward();

    cout << "\nSearch 30: "
         << (list.search(30) ? "Found" : "Not found") << '\n';

    list.deleteBeginning();
    cout << "\nAfter deleting beginning:\n";
    list.displayForward();

    list.deleteEnd();
    cout << "\nAfter deleting end:\n";
    list.displayForward();

    list.deleteValue(25);
    cout << "\nAfter deleting 25:\n";
    list.displayForward();

    return 0;
}
