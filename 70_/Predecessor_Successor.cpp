// Predecessor and Successor in Binary Search Tree (TC: O(h), SC: O(1)) - CN

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    BinaryTreeNode<int>* temp = root;
    int predecessor = -1;
    int successor = -1;

    while(temp->data != key){
        if(temp->data > key){
            successor = temp->data;
            temp = temp->left;
        } else {
            predecessor = temp->data;
            temp = temp->right;
        }
    }

    // Finding predecessor
    BinaryTreeNode<int>* leftSubtree = temp->left;
    while(leftSubtree != nullptr){
        predecessor = leftSubtree->data;
        leftSubtree = leftSubtree->right;
    }

    // Finding successor
    BinaryTreeNode<int>* rightSubtree = temp->right;
    while(rightSubtree != nullptr){
        successor = rightSubtree->data;
        rightSubtree = rightSubtree->left;
    }

    pair<int, int> ans = make_pair(predecessor, successor);

    return ans;
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(7);

    int key = 5;
    pair<int, int> ans = predecessorSuccessor(root, key);
    cout << "Predecessor: " << ans.first << ", Successor: " << ans.second << endl;

    return 0;
}