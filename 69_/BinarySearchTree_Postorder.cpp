// Binary Search Tree implementation in C++ (Postorder)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {

private:
    Node* root;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(8);
    bst.insert(21);
    bst.insert(7);
    bst.insert(27);
    bst.insert(5);
    bst.insert(4);
    bst.insert(3);

    cout << "Postorder Traversal: ";
    bst.postorder();

    return 0;
}   

