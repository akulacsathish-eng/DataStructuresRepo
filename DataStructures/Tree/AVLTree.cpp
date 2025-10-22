#include <iostream>
using namespace std;

// ---------------------------
// Node Structure
// ---------------------------
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// ---------------------------
// Utility Functions
// ---------------------------

// Get height of a node using if-else
int height(Node* n) {
    if (n != nullptr)
        return n->height;
    else
        return 0;
}

// Get balance factor (left height - right height)
int getBalance(Node* n) {
    if (n != nullptr)
        return height(n->left) - height(n->right);
    else
        return 0;
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // leaf node
    return node;
}

// ---------------------------
// Rotation Functions
// ---------------------------

// Right rotation
Node* rotateRight(Node* pivot) {
    Node* child = pivot->left;        // left child becomes new root
    Node* grandchild = child->right;  // temporary subtree

    // Perform rotation
    child->right = pivot;
    pivot->left = grandchild;

    // Update heights
    if (pivot != nullptr)
        pivot->height = (height(pivot->left) > height(pivot->right) ? height(pivot->left) : height(pivot->right)) + 1;

    if (child != nullptr)
        child->height = (height(child->left) > height(child->right) ? height(child->left) : height(child->right)) + 1;

    // Return new root
    return child;
}

// Left rotation
Node* rotateLeft(Node* pivot) {
    Node* child = pivot->right;       // right child becomes new root
    Node* grandchild = child->left;   // temporary subtree

    // Perform rotation
    child->left = pivot;
    pivot->right = grandchild;

    // Update heights
    if (pivot != nullptr)
        pivot->height = (height(pivot->left) > height(pivot->right) ? height(pivot->left) : height(pivot->right)) + 1;

    if (child != nullptr)
        child->height = (height(child->left) > height(child->right) ? height(child->left) : height(child->right)) + 1;

    // Return new root
    return child;
}

// ---------------------------
// Insertion with Rebalancing
// ---------------------------
Node* insert(Node* root, int key) {
    // 1️⃣ Standard BST insertion
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    // 2️⃣ Update height of pivot
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // 3️⃣ Get balance factor
    int balance = getBalance(root);

    // 4️⃣ Perform rotations if unbalanced

    // Case 1: Left-Left (rotate right)
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Case 2: Right-Right (rotate left)
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Case 3: Left-Right (double rotation)
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Case 4: Right-Left (double rotation)
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Return unchanged node if already balanced
    return root;
}

// ---------------------------
// Traversal Function
// ---------------------------
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// ---------------------------
// Main Function
// ---------------------------
int main() {
    Node* root = nullptr;

    // Insert elements
    int keys[] = {30, 10, 40, 5, 20, 35, 50, 37};
    int size = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < size; i++) {
        root = insert(root, keys[i]);
    }

    cout << "Inorder traversal of the AVL tree:\n";
    inOrder(root);
    cout << endl;

    return 0;
}
