// Flatten binary tree to linked list - GFG (Morris Traversal Preorder)

// According to question
// TC: O(N) SC: O(1)
// Inline code without using extra space

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void flatten(Node* root){
    if(root == NULL)
        return;

    Node* current = root;

    while(current != NULL){
        if(current->left != NULL){
            Node* predecessor = current->left;
            while(predecessor->right != NULL){
                predecessor = predecessor->right;
            }
            predecessor->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);

    // Print the flattened linked list
    Node* current = root;
    while(current != NULL){
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}