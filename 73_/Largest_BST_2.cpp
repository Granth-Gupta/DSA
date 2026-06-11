// Largest BST in a Binary Tree - CN (Approach 2 - Optimized using class info (maxi, mini, isBST, size)) - TC: O(n) - SC: O(n)

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

class Info {
public:
    int size;
    int maxi;
    int mini;
    bool isBST;

    Info() {
        size = 0;
        maxi = INT_MIN;
        mini = INT_MAX;
        isBST = true;
    }
};

Info largestBST(Node* root) {
    if (root == NULL) {
        return Info();
    }

    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);

    Info currInfo;
    currInfo.size = 1 + leftInfo.size + rightInfo.size;
    currInfo.maxi = max(root->data, max(leftInfo.maxi, rightInfo.maxi));
    currInfo.mini = min(root->data, min(leftInfo.mini, rightInfo.mini));

    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxi && root->data < rightInfo.mini) {
        currInfo.isBST = true;
    } else {
        currInfo.isBST = false;
        currInfo.size = max(leftInfo.size, rightInfo.size);
    }

    return currInfo;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Info result = largestBST(root);
    cout << "Size of the largest BST is: " << result.size << endl;

    return 0;
}

