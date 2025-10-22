#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility: get height of node
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility: get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Create new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;  // new node is initially at height 1
    return node;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotate
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // new root
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotate
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // new root
}

// Insert key and balance
Node* insert(Node* node, int key) {
    // 1️⃣ Normal BST insert
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicates not allowed

    // 2️⃣ Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3️⃣ Check balance
    int balance = getBalance(node);

    // 4️⃣ Perform rotations if unbalanced

    // Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // unchanged node pointer
}

// Print tree in-order
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 35);
    root = insert(root, 50);

    cout << "Inorder traversal of AVL tree:\n";
    inOrder(root);
    cout << endl;

    return 0;
}
