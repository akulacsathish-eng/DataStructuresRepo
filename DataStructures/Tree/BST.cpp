#include <iostream>
#include <algorithm>  // for max()
using namespace std;

// ----------------------------
// Node structure
// ----------------------------
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

// ----------------------------
// BST class with all functions
// ----------------------------
class BST {
public:
    Node* root;

    BST() { root = nullptr; }

    // Insert a new key
    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        
        return node;
    }

    // Search for a key
    bool search(Node* node, int key) {
        if (node == nullptr) 
            return false;
        if (node->key == key) 
            return true;
        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find the minimum key
    int findMin(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty.\n";
            return -1;
        }
        while (node->left != nullptr)
            node = node->left;
        return node->key;
    }

    // Find the maximum key
    int findMax(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty.\n";
            return -1;
        }
        while (node->right != nullptr)
            node = node->right;
        return node->key;
    }

    // Delete a node
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) 
            return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            // Case 1: no child
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: one child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: two children
            else {
                Node* successor = node->right;
                while (successor->left != nullptr)
                    successor = successor->left;
                node->key = successor->key;
                node->right = deleteNode(node->right, successor->key);
            }
        }
        return node;
    }

    // Inorder traversal (Left → Root → Right)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    // Preorder traversal (Root → Left → Right)
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder traversal (Left → Right → Root)
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }

    // Height of the BST
    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

// ----------------------------
// Driver function
// ----------------------------
int main() {
    BST tree;

    // Insert elements
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Minimum value: " << tree.findMin(tree.root) << endl;
    cout << "Maximum value: " << tree.findMax(tree.root) << endl;
    cout << "Height of tree: " << tree.height(tree.root) << endl;

    // Search
    int key = 60;
    cout << "Search " << key << ": "
         << (tree.search(tree.root, key) ? "Found" : "Not Found") << endl;

    // Delete
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "After deleting 20, inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
