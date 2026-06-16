// Is Binary Tree a Heap? - GFG - Approach: using recursion - TC: O(n) - SC: O(h)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
    int countNodes(Node* root) {
        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(Node* root, int index, int totalNodes) {
        if(root == NULL) return true;

        if(index >= totalNodes) return false;

        return isComplete(root->left, 2*index + 1, totalNodes) && 
               isComplete(root->right, 2*index + 2, totalNodes);
    }

    bool isMaxHeap(Node* root) {
        if(root == NULL) return true;

        if(root->left != NULL && root->data < root->left->data) return false;
        if(root->right != NULL && root->data < root->right->data) return false;

        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }

  public:
    bool isHeap(Node* root) {
        int index = 0;
        int totalNodes = countNodes(root);

        return isComplete(root, index, totalNodes) && isMaxHeap(root);
    }
};

int main(){
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);

    Solution s;
    cout << s.isHeap(root) << endl; 

    return 0;
}