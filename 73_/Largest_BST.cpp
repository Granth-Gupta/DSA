// Largest BST in a Binary Tree - CN (Approach 1 - Brute Force) - TC: O(n^2) - SC: O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }

    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int largestBST(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (isBST(root, INT_MIN, INT_MAX)) {
        return countNodes(root);
    }

    return max(largestBST(root->left), largestBST(root->right));
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Size of the largest BST is: " << largestBST(root) << endl;

    return 0;
}

