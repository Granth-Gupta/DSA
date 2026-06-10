// Deletion of node in Binary Search Tree 
// TC: O(log n) in average case, O(n) in worst case when the tree is skewed, SC: O(h) where h is the height of the tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* minValueNode(Node* node) {
    Node* current = node;

    while(current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL)
        return NULL;

    // Search for the node to delete
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found

        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child (left)
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: One child (right)
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Inorder Traversal before deletion: ";
    inorder(root);
    cout << endl;

    int key = 5;
    root = deleteNode(root, key);

    cout << "Inorder Traversal after deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}