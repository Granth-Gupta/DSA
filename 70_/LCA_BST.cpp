// LCA of 2 nodes in a BST - CN (TC: O(h), SC: O(1) - iterative, O(h) - recursive)

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

BinaryTreeNode<int>* LCA(BinaryTreeNode<int>* root, int n1, int n2) {
    if(root == nullptr){
        return nullptr;
    }

    if(root->data > n1 && root->data > n2){
        return LCA(root->left, n1, n2);
    }

    if(root->data < n1 && root->data < n2){
        return LCA(root->right, n1, n2);
    }

    return root;
}

BinaryTreeNode<int>* LCA_Iter(BinaryTreeNode<int>* root, int n1, int n2){
    while(root != nullptr){
        if(root->data > n1 && root->data > n2){
            root = root->left;
        } else if(root->data < n1 && root->data < n2){
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(7);

    int n1 = 3;
    int n2 = 7;

    BinaryTreeNode<int>* ans = LCA(root, n1, n2);
    BinaryTreeNode<int>* ansIter = LCA_Iter(root, n1, n2);

    // Recursive approach - TC: O(h), SC: O(h) - recursive
    if(ans != nullptr){
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    } else {
        cout << "LCA does not exist." << endl;
    }

    // Iterative approach - TC: O(h), SC: O(1) 
    if(ansIter != nullptr){
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ansIter->data << endl;
    } else {
        cout << "LCA does not exist." << endl;
    }

    return 0;
}

