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
    int choice, value;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. Search node\n";
        cout << "4. Display list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(head, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(head, value))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 4:
                cout << "Current list: ";
                displayList(head);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
