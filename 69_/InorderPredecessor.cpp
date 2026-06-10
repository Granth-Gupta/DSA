// Find the Inorder Predecessor in a Binary Search Tree
// Inorder Predecessor of a key in a Binary Search Tree (BST) is the node which comes just before the key in the Inorder Traversal of the BST.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* findInorderPredecessor(Node* root, int key) {
    Node* predecessor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (current->data < key) {
            predecessor = current; // Update predecessor
            current = current->right; // Move right to find a larger value
        } else {
            current = current->left; // Move left to find a smaller value
        }
    }

    return predecessor;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    int key = 7;
    Node* predecessor = findInorderPredecessor(root, key);
    if (predecessor != nullptr) {
        cout << "Inorder Predecessor of " << key << " is: " << predecessor->data << endl;
    } else {
        cout << "Inorder Predecessor of " << key << " does not exist." << endl;
    }

    return 0;
}