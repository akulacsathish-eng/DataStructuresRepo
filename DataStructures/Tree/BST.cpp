#include <iostream>
using namespace std;

// Represents one node of the tree
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node() { data = 0; left = right = NULL; }
    Node(int val) { data = val; left = right = NULL; }
};

// ----------- Function Prototypes -----------
void inorder(Node *currentPtr);
Node* insert(Node *root, Node *element);
int add(Node *currentPtr);
int find(Node *currentPtr, int val);
Node* parent(Node *root, Node *node);
Node* minVal(Node *root);
Node* maxVal(Node *root);
int isLeaf(Node *node);
int hasOnlyLeftChild(Node *node);
int hasOnlyRightChild(Node *node);
Node* findNode(Node *currentPtr, int value);
Node* deleteNode(Node* root, int value);
int menu();

// ----------- Function Definitions -----------

// Print tree in sorted (inorder) order
void inorder(Node *currentPtr) {
    if (currentPtr != NULL) {
        inorder(currentPtr->left);
        cout << " " << currentPtr->data;
        inorder(currentPtr->right);
    }
}

// Insert a new node into the BST
Node* insert(Node *root, Node *element) {
    if (root == NULL) return element;
    if (element->data > root->data) {
        root->right = insert(root->right, element);
    } else {
        root->left = insert(root->left, element);
    }
    return root;
}

// Search for a value in the BST
int find(Node *currentPtr, int val) {
    if (!currentPtr) return 0;
    if (currentPtr->data == val) return 1;
    return (val < currentPtr->data)
           ? find(currentPtr->left, val)
           : find(currentPtr->right, val);
}

// Compute the sum of all nodes
int add(Node *currentPtr) {
    if (!currentPtr) return 0;
    return currentPtr->data + add(currentPtr->left) + add(currentPtr->right);
}

// Find parent of a given node
Node* parent(Node *root, Node *node) {
    if (!root || root == node) return NULL;
    if (root->left == node || root->right == node) return root;
    return (node->data < root->data)
           ? parent(root->left, node)
           : parent(root->right, node);
}

// Find smallest node (leftmost)
Node* minVal(Node *root) {
    return (root->left == NULL) ? root : minVal(root->left);
}

// Find largest node (rightmost)
Node* maxVal(Node *root) {
    return (root->right == NULL) ? root : maxVal(root->right);
}

int isLeaf(Node *node) { return (node->left == NULL && node->right == NULL); }
int hasOnlyLeftChild(Node *node) { return (node->left != NULL && node->right == NULL); }
int hasOnlyRightChild(Node *node) { return (node->left == NULL && node->right != NULL); }

// Locate node containing a given value
Node* findNode(Node *currentPtr, int value) {
    if (!currentPtr) return NULL;
    if (currentPtr->data == value) return currentPtr;
    return (value < currentPtr->data)
           ? findNode(currentPtr->left, value)
           : findNode(currentPtr->right, value);
}

// Delete a node from BST
Node* deleteNode(Node* root, int value) {
    Node *delnode = findNode(root, value);
    Node *par = parent(root, delnode);
    if (!delnode) return root;

    // Case 1: Leaf node
    if (isLeaf(delnode)) {
        if (!par) { delete root; return NULL; }
        if (value < par->data) delete par->left;
        else { delete par->right; par->right = NULL; }
        return root;
    }

    // Case 2: One left child
    if (hasOnlyLeftChild(delnode)) {
        if (!par) { Node *save = delnode->left; delete delnode; return save; }
        if (value < par->data) { Node *save = par->left; par->left = par->left->left; delete save; }
        else { Node *save = par->right; par->right = par->right->left; delete save; }
        return root;
    }

    // Case 3: One right child
    if (hasOnlyRightChild(delnode)) {
        if (!par) { Node *save = delnode->right; delete delnode; return save; }
        if (value < par->data) { Node *save = par->left; par->left = par->left->right; delete save; }
        else { Node *save = par->right; par->right = par->right->right; delete save; }
        return root;
    }

    // Case 4: Two children – replace with inorder successor
    Node *newDelNode = minVal(delnode->right);
    int saveVal = newDelNode->data;
    deleteNode(root, saveVal);
    delnode->data = saveVal;
    return root;
}

// Display user menu
int menu() {
    int ans;
    cout << "\nMenu:\n";
    cout << "1. Insert\n2. Delete\n3. Search\n4. Sum of nodes\n5. Inorder traversal\n6. Exit\n";
    cout << "Enter choice: ";
    cin >> ans;
    return ans;
}

// ----------- Main Driver -----------
int main() {
    Node *myRoot = NULL, *tempNode;
    int ans, val;

    ans = menu();
    while (ans != 6) {
        if (ans == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            tempNode = new Node(val);
            myRoot = insert(myRoot, tempNode);
        }
        else if (ans == 2) {
            cout << "Enter value to delete: ";
            cin >> val;
            if (!find(myRoot, val))
                cout << "Value not found.\n";
            else
                myRoot = deleteNode(myRoot, val);
        }
        else if (ans == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            cout << (find(myRoot, val)
                     ? "Found " + to_string(val) + " in the tree.\n"
                     : "Did not find " + to_string(val) + " in the tree.\n");
        }
        else if (ans == 4)
            cout << "Sum of all nodes: " << add(myRoot) << "\n";
        else if (ans == 5) {
            cout << "Inorder traversal: ";
            inorder(myRoot);
            cout << "\n";
        }
        ans = menu();
    }
    return 0;
}
