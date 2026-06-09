// Search in a Binary Search Tree (BST) - Coding Ninjas (Approach 2: Iterative, TC: O(log n) in average case, O(n) in worst case when the tree is skewed, SC: O(1) )

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool searchInBST(BinaryTreeNode* root, int x) {
    while(root != NULL) {
        if(root->data == x)
            return true;
        
        if(root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main() {
    // Example usage:
    BinaryTreeNode* root = new BinaryTreeNode(10);
    root->left = new BinaryTreeNode(5);
    root->right = new BinaryTreeNode(15);
    root->left->left = new BinaryTreeNode(3);
    root->left->right = new BinaryTreeNode(7);

    int x = 7;
    if (searchInBST(root, x)) {
        cout << "Element " << x << " found in the BST." << endl;
    } else {
        cout << "Element " << x << " not found in the BST." << endl;
    }

    return 0;
}

