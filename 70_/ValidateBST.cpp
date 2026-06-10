// Validate Binary Search Tree - CN
// TC: O(n) where n is the number of nodes in the tree
// SC: O(h) where h is the height of the tree (due to recursion stack)

#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode 
{
  public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() 
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

bool isBST(BinaryTreeNode<int>* root, int min, int max){
    if(root == nullptr){
        return true;
    }
    if(root->data > min && root->data < max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int>* root) 
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(2);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);

    if(validateBST(root)){
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    delete root; // Clean up memory
    return 0;
}