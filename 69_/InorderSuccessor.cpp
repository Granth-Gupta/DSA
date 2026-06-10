// Inorder Successor of a key in a Binary Search Tree (BST) 
// It is the node which comes just after the key in the Inorder Traversal of the BST.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* findInorderSuccessor(Node* root, int key) {
    Node* successor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (current->data > key) {
            successor = current; // Update successor
            current = current->left; // Move left to find a smaller value
        } else {
            current = current->right; // Move right to find a larger value
        }
    }

    return successor;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    int key = 7;
    Node* successor = findInorderSuccessor(root, key);
    if (successor != nullptr) {
        cout << "Inorder Successor of " << key << " is: " << successor->data << endl;
    } else {
        cout << "Inorder Successor of " << key << " does not exist." << endl;
    }

    return 0;
}