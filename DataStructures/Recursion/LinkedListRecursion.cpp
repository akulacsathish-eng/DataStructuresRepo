#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// recursive insert at end
void insertNode(Node*& head, int value) {
    if (head == NULL) {  // recursion base case
        head = new Node{value, NULL};
        return;
    }
    insertNode(head->next, value);  // recursive call
}

// recursive delete (first match)
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;  // base case

    if (head->data == value) {  // base case (match found)
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    deleteNode(head->next, value);  // recursive call
}

// recursive search
bool searchNode(Node* head, int value) {
    if (head == NULL) return false;     // base case
    if (head->data == value) return true;  
    return searchNode(head->next, value);  // recursive call
}

// recursive display
void displayList(Node* head) {
    if (head == NULL) {   // base case
        cout << endl;
        return;
    }
    cout << head->data << " ";
    displayList(head->next);  // recursive call
}

int main() {
    Node* head = NULL;

    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);

    cout << "List: ";
    displayList(head);

    cout << "Searching 20: " << (searchNode(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Deleting 20..." << endl;
    deleteNode(head, 20);

    cout << "List after deletion: ";
    displayList(head);

    return 0;
}
