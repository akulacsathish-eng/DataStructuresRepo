#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// add node at the end
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// delete first node with given value
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;

    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// search for a value
bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// print all nodes
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
